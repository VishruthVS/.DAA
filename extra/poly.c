#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int c=0;
void writeCount(int n,FILE *fp)
{
	fprintf(fp,"%d\t%d\n",n,c);
	c=0;
}
void writeArr(int *a,int n,FILE *fp)
{	
	fprintf(fp,"Array : \n");
	for(int i = 0;i<n;i++)
	{
		a[i]=rand()%100+1;
		fprintf(fp,"%d\t",a[i]);
	}
	fprintf(fp,"\n");
}
int poly(int *a,int x,int n)
{
	int s=a[0],pow=1;
	for(int i=1;i<n;i++)
	{
		c+=2;		
		pow*=x;
		s+=pow*a[i];
	}
	return s;
}
void recordCount(int *a,int n,FILE *f,FILE *fp)
{
	writeArr(a,n,f);
	int x=rand()+1;
	fprintf(f,"\nx = %d\nSum = %d\n\n",x,poly(a,x,n));
	writeCount(n,fp);
}
void main()
{
	FILE *f=fopen("polyInfo.txt","w");
	FILE *fc=fopen("PPcount.txt","w");
	int *a;srand(time(0));
	for(int n=10;n<=100;n+=10)
	{
		a=(int *)malloc(n*sizeof(int));
		recordCount(a,n,f,fc);
	}
	fclose(fc);
	fclose(f);
	FILE *fg = fopen("PPplot.gnu","w");
fprintf(fg,"set yrange [0:*]\nset xlabel \"n\"\nset ylabel \"t\"\nplot \"PPcount.txt\" w l ti \"SSort\"\nset term png\nset output \"PPG.png\"\nreplot\nset term x11");
fclose(fg);
system("gnuplot \"PPplot.gnu\"");
system("eog PPG.png");
}
