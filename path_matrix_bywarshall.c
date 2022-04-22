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
int main()
{
    int i,j;
    creategraph();
    int p[MAX][MAX];
     for(i=0;i<n;i++)
        for(j=0;j<n;j++)
           p[i][j]=adj[i][j];
    int k;
    for(k=0;k<n;k++)
    {
         for(i=0;i<n;i++)
            for(j=0;j<n;j++)
               p[i][j]=(p[i][j] ||(p[i][k]&&p[k][j]));

          printf("p%d is \n",k);
          display(p);     
    }
    printf("path matrix is p%d",k-1);
}