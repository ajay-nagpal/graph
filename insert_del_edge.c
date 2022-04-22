#include<stdio.h>
#define MAX 100
int adj[MAX][MAX];
int n,graph_type;
void creategraph()
{
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
}
void insert(int origin,int destination)
{
    if(origin>=n ||destination>=n ||origin<0 ||destination<0)
    {
        printf("invalid vertex\n");
        return;
    }
    adj[origin][destination]=1;
    if(graph_type==1)
    adj[destination][origin]=1;
}
void delete(int origin,int destination)
{
    if(origin>=n ||destination>=n ||origin<0 ||destination<0|| adj[origin][destination]==0)
    {
        printf("invalid vertex\n");
        return;
    }
    adj[origin][destination]=0;
    if(graph_type==1)
    adj[destination][origin]=0;
}
void display(int n)
{
    int i,j;
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
int main()
{
    printf("enter number of vertex\n");
    scanf("%d",&n);
    printf("enter graph type 1 for undirect 2 for direct\n");
    scanf("%d",&graph_type);
    creategraph();

    int choice;
    int origin,destination;
    while(1)
    {
        printf("\n enter choice 1 for insert 2 for delete  3 for display 4 for exit ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nenter edge to insert\n");
            scanf("%d %d",&origin,&destination);
            insert(origin,destination);
            break;

            case 2:
            printf("\nenter edge to delete\n");
            scanf("%d %d",&origin,&destination);
            delete(origin,destination);
            break;

            case 3:
            printf("\n adjancy matrix is \n");
            display(n);
            break;

            case 4:
            return 0;

            default:
            printf("\n wrong choice\n");
            break;
        }
    }
}