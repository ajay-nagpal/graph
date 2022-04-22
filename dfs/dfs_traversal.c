#include<stdio.h>
#define MAX 100
int adj[MAX][MAX];
int n;
int state[MAX];
#define initial 1
#define visited 2
#include<stdlib.h>
int stack[MAX];
int top=-1;

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
void push(int v)
{
    if(top==MAX-1)
    {
        printf("stack overflow\n");
        return;
    }
    top+=1;
    stack[top]=v;
}
int pop()
{
    if(top==-1)
    {
       printf("stack underflow\n");
       exit(1); 
    }
    int v=stack[top];
    top-=1;
    return v;
}
int emptystack()
{
    if(top==-1)
    return 1;
    else 
    return 0;
}
void dfs(int v)
{
    int i;
    push(v);
    while(!emptystack())//top!=-1
    {
        v=pop();
       if(state[v]==initial)
       {
        printf("%d ",v);
        state[v]=visited;
       }
        for(i=n-1;i>=0;i--)
            if(state[i]==initial&&adj[v][i]==1)
                push(i);
    }
    printf("\n");
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
        if(state[i]==initial)
            dfs(i);
}
int main()
{
    creategraph();
    df_traversal();
}
