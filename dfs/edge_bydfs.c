#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int n;
int state[MAX];

#define initial  1
#define visited  2
#define finished   3

int time=0;
int d[MAX];
int f[MAX];

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
}
void dfs(int v)
{
    int i;
    
    d[v]=++time;
    printf("%d ",v);
    state[v]=visited;
    for(i=0;i<n;i++)
    {
        if(adj[v][i]==1)
        {
            if(state[i]==initial)
            {
                printf("\n tree edge %d->%d\n",v,i);
                dfs(i);
            }
            else if(state[i]==visited)
                printf("\n back edge %d->%d\n",v,i);
            else if(d[v]<d[i])
                printf("\n forward edge %d->%d\n",v,i);
            else
                printf("\n cross edge %d->%d\n",v,i);        
        }     
    }
    state[v]=finished;
    f[v]=++time;
}
void df_traversal()
{
    int v,i;
    for(i=0;i<n;i++)
      state[i]=initial;
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
