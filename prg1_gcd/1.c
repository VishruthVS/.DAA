#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cE=0,cME=0,cCI=0;
int gcd_Euc(int m,int n)
{
	int gcd,r;
	while(n!=0)
	{
		cE++;
		r=m%n;
		m=n;
		n=r;
	}
	gcd=m;
	return gcd;
}
int gcd_MEuc(int m,int n)
{
	int gcd;
	while(m!=n)
	{
		cME++;
		if(m>n)
			m=m-n;
		else
			n=n-m;
	}
	gcd=m;
	return gcd;
}
int gcd_ConInt(int m,int n)
{
	int gcd,min;
	min=m>n?n:m;
	while(min!=1)
	{
		cCI++;
		if(m%min==0)
			if(n%min==0)
				break;
		min--;
	}
	gcd=min;
	return gcd;
}
void main()
{
	int m,n;
	srand(time(0));
	FILE *fn=fopen("GCDN.txt","w");
	fprintf(fn,"m\t\tn\t\tGCDE\t\tGCDME\t\tGCDCI\n");
	FILE *fc=fopen("GCDC.txt","w");
	for(int i=0;i<10;i++)
	{
		m=(rand()+1)%100;
		n=(rand()+1)%100;
		fprintf(fn,"%d\t\t%d\t\t%d\t\t%d\t\t%d\n",m,n,gcd_Euc(m,n),gcd_MEuc(m,n),gcd_ConInt(m,n));
		fprintf(fc,"%d\t%d\t%d\n",cE,cME,cCI);
		cE=0,cME=0,cCI=0;
	}
	fclose(fn);
	fclose(fc);
	system("gedit GCDN.txt GCDC.txt");
}
