#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int n;
int state[MAX];

#define initial  1
#define visited  2
#define finished 3

int adjr[MAX][MAX];

void display(int matrix[MAX][MAX])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
void creategraph()
{
    printf("enter number of vertex\n");
    scanf("%d",&n);
    
    int MAX_edge=n*(n-1);
    printf("MAX edge is %d\n",MAX_edge);
    int i,j;
    int origin,destination;
    
    for(i=1;i<=MAX_edge;i++)
    {
        printf("enter edge %d ",i);
        scanf("%d %d",&origin,&destination);
        if(origin==-1 && destination==-1)
        break;
        if(origin>=n ||destination>=n ||origin<0 ||destination<0)
        {
            printf("invalid vertex\n");
            i--;
        }
        else
            adj[origin][destination]=1;
    }
    printf("adj is \n");
    display(adj);
}
void dfs(int v)
{
    int i;
    printf("%d ",v);
    state[v]=visited;
    for(i=0;i<n;i++)
    {
        if(state[i]==initial&&adj[v][i]==1)
            dfs(i);
    }
    state[v]=finished;
}
void df_traversal()
{
    int v,i,j;
    for(i=0;i<n;i++)
      state[i]=initial;
    printf("enter any vertex to start traversal\n");
    scanf("%d",&v);  
    dfs(v);
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(state[i]==initial)
            {
                printf("graph is not strongly connected\n");
                exit(1);
            }
            else
            {
                if(adj[i][j]==1)
                {
                    adjr[j][i]=1;
                }
            }
        }
        
    } */

    for(i=0;i<n;i++)
    {
      if(state[i]==initial)
      {
        printf("graph is not strongly connected\n");
        exit(1);
      }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(adj[i][j]==1)
                adjr[j][i]=1;
        }
    }
    printf("adj-reverse is \n");
    display(adjr); 

    for(i=0;i<n;i++)
      state[i]=initial;
    printf("enter any vertex to start traversal\n");
    scanf("%d",&v);  
    dfs(v);  
    for(i=0;i<n;i++)
    {
        if(state[i]==initial)
        {
             printf("graph is not strongly connected\n");
            exit(1);
        }
    }   
    printf("graph is strongly connected\n"); 
}
int main()
{
    creategraph();
    df_traversal();
}
