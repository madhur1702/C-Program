#include <stdio.h>
int main()
{
	int a;
	printf("enter anny no.");
	scanf("%d",&a);
	if(a>0)
	{
		printf("a=%d is +ve",a);
	}
	else if(a<0)
	{
		printf("a=%d is -ve",a);
	}
	else
	{
		printf("a=0");
	}
	return 0;
}
