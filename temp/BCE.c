#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int co=0;

int min(int a,int b)
{
	return a<b:a?b;
}

int bicoef(int n,int k)
{
	if(n<k)
		return -1;
	int c[n+1][k+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=min(i,k);j++)
			if(j<=1)
				c[i][j]=1;
			else
			{
				co++;
				c[i][j]=c[i-1][j-1]+c[i-1][j];
			}
	return c[n][k];
}
void main()
{
	FILE *f=fopen("BCEInfo.txt","w");
	FILE *fc=fopen("BCEco.txt","w");
	srand(time(0));
	fprintf(f,"n\tk\tcoeff\n");
	for(int i=0;i<n;i++)
	{
		int k=rand()%50+1;
		int n=rand()%10+k;
		coef=bicoef(n,k);
		fprintf(f,"%d\t%d\t%d\n",n,k,coeff)
	}
}
