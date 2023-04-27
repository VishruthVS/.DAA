#include<stdio.h>
void main()
{
	int x=90;
	FILE *fp=fopen("file.txt","r+");
	fprintf(fp,"y=%d\n",x);
	
	fclose(fp);
}
