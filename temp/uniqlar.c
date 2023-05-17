#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int c=0;
void uniq(int *a,int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
		{
			c++;
			if(a[i]==a[j])
				break;
		}
}

void lar(int *a,int n)
{
	int l=a[0];
	for(int i=1;i<n;i++)
	{
		c++;
		if(l<a[i])
			l=a[i];
	}
}
void wC(int n,FILE *f)
{
	fprintf(f,"%d\t%d\n",n,c);
	c=0;
}
void main()
{
	int *a;
	FILE *f=fopen("arrayInfo.txt","w");
	FILE *fl=fopen("Lcount.txt","w");
	FILE *fu=fopen("Ucount.txt","w");
	srand(time(0));
	for(int n=10;n<=100;n+=10)
	{
		a=(int *)malloc(n*sizeof(int));
		fprintf(f,"Array : \n");
		for(int i=0;i<n;i++)
		{
			a[i]=(rand()+1)%100;
			fprintf(f,"%d\t",a[i]);
		}
		uniq(a,n);
		wC(n,fu);
		lar(a,n);
		wC(n,fl);
		free(a);
	}
	fclose(f);
	fclose(fu);
	fclose(fl);
	FILE *fg = fopen("Lplot.gnu","w");
fprintf(fg,"set yrange [0:]\nset xlabel \"n\"\nset ylabel \"t\"\nplot \"Lcount.txt\" w l ti \"Largest\", \"Ucount.txt\" w l ti \"Unique\"\nset term png\nset output \"LU.png\"\nreplot\nset term x11");
fclose(fg);
system("gnuplot \"Lplot.gnu\"");
system("eog LU.png");
}
