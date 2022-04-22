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
int time=0;
int f_time[MAX];
int d_time[MAX];

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
    d_time[v]=++time;
    // printf("%d ",v);
    state[v]=visited;
    for(i=0;i<n;i++)
    {
        if(state[i]==initial && adj[v][i]==1)
            dfs(i);
    }
    state[v]=finished;
    f_time[v]=++time;
    // printf("\n");
}
int ver_with_max_ftime()
{
    int max_time=-1,i,v=-1;
    for(i=0;i<n;i++)
    {
        if(state[i]==initial)
        {
            max_time=f_time[i];
            v=i;
            break;
        }
    }
    for(i=0;i<n;i++)
    {
        if(state[i]==initial)
        {
            if(f_time[i]>max_time)
            {
                max_time=f_time[i];
                v=i;
            }
            
        }
    }    
    return v;   
}
void dfs2(int v)
{
    int i;
    //d_time[v]=++time;
    printf("%d ",v);
    state[v]=visited;
    for(i=0;i<n;i++)
    {
        if(state[i]==initial&&adjr[v][i]==1)
            dfs2(i);
    }
    state[v]=finished;
   // f_time[v]=++time;
   printf("\n");
}
void df_traversal2()
{
    int i, count=0;

    int v=ver_with_max_ftime();
    printf("v is %d ",v);
    if(v==-1)
      return;
    printf("SCC %d is", ++count);
    dfs2(v);

    for(i=0;i<n;i++)
    {
        if(state[i]==initial)
        {
            v=ver_with_max_ftime();
            if(v==-1)
                return;
            printf("SCC %d is", ++count);
            dfs2(v);     
        }
    } 
}
void df_traversal()
{
    int v,i,j;
    for(i=0;i<n;i++)
      state[i]=initial;
    printf("enter any vertex to start traversal\n");
    scanf("%d",&v);  
    dfs(v);

    for(i=0;i<n;i++)
    {
      if(state[i]==initial)
      {
        dfs(i);
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

    df_traversal2();
}
int main()
{
    creategraph();
    df_traversal();
}
