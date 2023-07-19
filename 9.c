#include<stdio.h>
#include<stdlib.h>

int n,a[10][10],visit[10],stk[10],acy=1,t=-1,topo[10];

void dfs(int s)
{
	visit[s]=1;
	for(int i=s;i<=n;i++)
	{	
		if(a[s][i]&&visit[i])
			acy=0;
		if(a[s][i]&&!visit[i])
			dfs(i);
	}
	stk[++t]=s;
}

void toposort()
{
	int i=0;
	if(acy)
	    while(t>=0)
	    {
		    topo[i]=stk[t--];
		    printf("%d ",topo[i++]);
	    }
	else
	    printf("Graph is cyclic Topological sorting not possible\n");
	
}

void main()
{
	int i,j;
	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		visit[i]=0;
	printf("Enter the adjacency matrix : \n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		if(!visit[i])
			dfs(i);

	printf("The topological order is : ");
	toposort();
	printf("\n")
}
