#include<stdio.h>
int main()
{
	int i,j,rows;
	printf("enter rows");
	scanf("%d",&rows);
	for(i=1;i<=rows;i++)
	{
		printf("\n\n");
		for(j=1;j<=i;j++)
		{
			printf("*");
		}
	}
 return 0;
}
