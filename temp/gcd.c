#include<stdio.h>
#include<stdlib.h>
void gcdE(int m,int n)
{
	int rem,gcd,count=0;
	while(n!=0)
	{
		count++;
		rem=m%n;
		m=n;
		n=rem;
	}	
	gcd=m;
	printf("GCD using Euclid's Alogrithm is : %d",gcd);
	printf("\nCount : %d",count);
}
void gcdME(int m,int n)
{
	int gcd,count=0;
	while(n!=m)
	{
		count++;
		if(m>n)
			m=m-n;
		else
			n=n-m;
	}	
	gcd=m;
	printf("\nGCD using Modified Euclid's Alogrithm is : %d",gcd);
	printf("\nCount : %d\n",count);
}
void gcdC(int m,int n)
{
	int min,count=0;
	min=(m<n)?m:n;	
	while(min!=1)
	{
		count++;
		if(m%min==0)
			if(n%min==0)
				break;
		min--;
	}
	int gcd=min;
	printf("\nGCD using Consective integer Alogrithm is : %d",gcd);
	printf("\nCount : %d\n",count);
}
void main()
{
	int m,n;
	printf("Enter the numbers : ");
	scanf("%d%d",&m,&n);
	gcdE(m,n);
	gcdME(m,n);
	gcdC(m,n);
}
