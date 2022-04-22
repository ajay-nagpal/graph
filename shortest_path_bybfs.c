#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int queue[MAX];
int adj[MAX][MAX];
int rear=-1,front=-1;
#define initial 1
#define waiting 2
#define visited 3;
int n;
int state[MAX];

int path[MAX];
int prede[MAX];
int distance[MAX];
#define NIL -1
#define infinite 9999

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
int emptyqueue()
{
    if(front==-1||front==rear+1)
    return 1;
    else
    return 0;
}
void insert(int v)
{
    if(rear==MAX-1)
    {
         return;
    }
    if(front==-1)
    front=0;
    rear+=1;
    queue[rear]=v;
}
int deletefromqueue()
{
    int item;
    if(front==-1||front==rear+1)
    {
        printf("empty queue\n");
        exit(1);
    }
    item=queue[front];
    front+=1;
    return item;
}
void bfs(int v)
{
    int i;
    insert(v);
    state[v]=waiting;
    while(!emptyqueue())
    {
        v=deletefromqueue();
        printf("%d ",v);
        state[v]=visited;

        for(i=0;i<n;i++)
        {
            if(state[i]==initial&&adj[v][i]==1)
            {
                insert(i);
                state[i]=waiting;
                prede[i]=v;
                distance[i]=distance[v]+1;
            }
        }
    }
    printf("\n");
}
void bf_traversal()
{
    int v,i;
    for(i=0;i<n;i++)
    {
        state[i]=initial;
        distance[i]=infinite;
        prede[i]=NIL;
    }
      
    printf("enter any vertex to start traversal\n");
    scanf("%d",&v);  
    bfs(v);
}
int main()
{
    creategraph();
    bf_traversal();


    while(1)
    {
        int v;
    printf("enter destination vertex\n");
    scanf("%d",&v);
    
    if(v<-1||v>n-1)
    {
        printf("vertex n0t exist\n");
        continue;
    }
    if(v==-1)
        break;
    if(distance[v]==infinite)
    {
        printf("no path\n");
        continue;
    }
    else
        printf("shortest distance is %d\n ",distance[v]);

    int count=0,u;
    while(v!=NIL)
    {
        count++;
        path[count]=v;
        u=prede[v];
        v=u;
    }
    printf("shortest path is \n");
    int i;
    for(i=count;i>1;i--)
    {
        printf("%d->",path[i]);
    }
    printf("%d ",path[i]);
    }
    
}