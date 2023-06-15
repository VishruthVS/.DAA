#include<stdio.h>

int a[10][10],visit[10],acy=1,n,c=0;

void dfs(int s)
{
	visit[s]=1;
	for(int i=s;i<=n;i++)
	{	
		c++;
		if(a[s][i]&&visit[i])
			acy=0;
		if(a[s][i]&&!visit[i])
		{
			printf("%d -- %d\n",s,i);
			dfs(i);
		}
	}
}

void concyc()
{
	int i;
	for(i=1;i<=n;i++)
		if(!visit[i])
			break;
	if(i>n)
		printf("Graph is connected\n");
	else
	{	
		dfs(i);
		printf("Graph is not connected\n");
	}
	if(acy)
		printf("Graph is Acyclic\n");
	else
		printf("Graph is Cyclic\n");	
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
	dfs(1);
	concyc();
}

