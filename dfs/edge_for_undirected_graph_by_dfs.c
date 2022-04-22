#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int n;
int state[MAX];

#define initial  1
#define visited  2
#define finished   3

#define NIL -1
int prede[MAX];

void creategraph()
{
    printf("enter number of vertex\n");
    scanf("%d",&n);
    
    int MAX_edge=n*(n-1)/2;
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
        {
            adj[origin][destination]=1;
            adj[destination][origin]=1;
        }         
    }
}
void dfs(int v)
{
    int i;
    printf("%d ",v);
    state[v]=visited;
    for(i=0;i<n;i++)
    {
        if(adj[v][i]==1 && prede[v]!=i)
        {
            if(state[i]==initial)
            {
                prede[i]=v;
                printf("\n tree edge %d->%d\n",v,i);
                dfs(i);
            }
            else if(state[i]==visited)
                printf("\n back edge %d->%d\n",v,i);  
        }     
    }
    state[v]=finished;
}
void df_traversal()
{
    int v,i;
    for(i=0;i<n;i++)
    {
         state[i]=initial;
         prede[i]=NIL;
    }
     
    printf("enter any vertex to start traversal\n");
    scanf("%d",&v);  
    dfs(v);
    for(i=0;i<n;i++)
    {
        if(state[i]==initial)
            dfs(i);
    }       
}
int main()
{
    creategraph();
    df_traversal();
}
