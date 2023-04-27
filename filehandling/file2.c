#include<stdio.h>
void main()
{
	int y;
	FILE *fp=fopen("file3.txt","w+");
	printf("enter a string :");
	char c[100];
	scanf("%c",c);
	fputs(c,fp);
	fscanf(fp,"%d",&y);
	printf("y from file is : %d",y);
	fprintf(fp,"\nz= %d",7);
	fclose(fp);
}
