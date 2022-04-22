#include<stdio.h>
#define MAX 10
int adj[MAX][MAX];
int n;
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
    int max_edge=n*(n-1);
    printf("max edge is %d\n",max_edge);
    int i;
    int origin,destination;
    
    for(i=1;i<=max_edge;i++)
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
    printf("\n the adjancy matrix is \n");
    display(adj);
}
void multiply(int adjp[MAX][MAX],int adj[MAX][MAX],int tmp[MAX][MAX])
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            tmp[i][j]=0;
            for(k=0;k<n;k++)
            {
                tmp[i][j]=tmp[i][j]+adjp[i][k]*adj[k][j];
            }
        }
    }
}
void power(int p,int adjp[MAX][MAX])
{
    int i,j;
    int tmp[MAX][MAX];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            adjp[i][j]=adj[i][j];
    for(int k=1;k<p;k++)
    {
        multiply(adjp,adj,tmp);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                adjp[i][j]=tmp[i][j];
    }
}
int main()
{
    int x[MAX][MAX],path[MAX][MAX],adjp[MAX][MAX];
    int i,j;
    creategraph();

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            x[i][j]=0;
    int p;
    for(p=1;p<=n;p++)
    {
        power(p,adjp);
        printf("adjp martrix power %d is\n",p);
        display(adjp);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                x[i][j]=x[i][j]+adjp[i][j];
    }
    printf("matrix x is \n");
    display(x);
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(x[i][j]==0)
            path[i][j]=0;
            else
            path[i][j]=1;
        }
    }
     printf(" path matrix  is \n");
    display(path);         
}