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


#define NIL -1


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
        printf("vertex %d visited\n",v);
        state[v]=visited;

        for(i=0;i<n;i++)
        {
            if(state[i]==initial &&adj[v][i]==1)
            {
                insert(i);
                state[i]=waiting;
    
                printf("tree edge is %d->%d\n",v,i);
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
       
    }
      
    printf("enter any vertex to start traversal\n");
    scanf("%d",&v);  
    bfs(v);
    for(i=0;i<n;i++)
    {
        if(state[i]==initial)
        bfs(i);
    }
}
int main()
{
    creategraph();
    bf_traversal();
}