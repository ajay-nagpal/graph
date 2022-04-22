#include<stdio.h>
#define MAX 100
int adj[MAX][MAX];
int main()
{
    int n;
    printf("enter number of vertex\n");
    scanf("%d",&n);
    //int adj[n][n];

    int graph_type;
    printf("enter graph type 1 for undirect 2 for direct\n");
    scanf("%d",&graph_type);

    int max_edge;
    if(graph_type==1)
    max_edge=n*(n-1)/2;
    else
    max_edge=n*(n-1);
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
        {
            adj[origin][destination]=1;
            if(graph_type==1)
            adj[destination][origin]=1;
        }
    }
    int j;
    printf("\n the adjancy matrix is \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
}