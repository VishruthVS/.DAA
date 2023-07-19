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

/////

#include<stdio.h>
#include<stdlib.h>


void main()
{
	int i,j;
	int n,a[10][10],q[10],r=-1,f=0,co=0,v;
	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	int* indeg=calloc(n+1,sizeof(int));
	printf("Enter the adjacency matrix : \n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[j][i])
			    indeg[i]++;
    for(i=1;i<=n;i++)
        if(!indeg[i])
            q[++r]=i;
	int* topo=calloc(n+1,sizeof(int));
	while(r>=f)
	{
	    v=q[++f];
	    topo[++co]=v;
	        for(int j=1;j<=n;j++)
                if(a[v][j])
                {
                    a[v][j]=0;
                    indeg[j]--;
                    if(indeg[j]==0)
                        q[++r]=j;
                }
	}
	if(co<n)
	    printf("The topological sorting is not possible");
	else
	{
	    printf("topological Sorting is : ");
	    for(int i=0;i<=co;i++)
	        printf("%d ",topo[i]);
	}
	printf("\n");
}
