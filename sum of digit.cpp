#include<stdio.h>
int main ()
{
	int num,rem,sum=0;
	printf("enter any no.");
	scanf("%d",&num);
	while(num>0)
	{
		rem=num%10;
		sum=sum+rem;
		sum=num/10;
	}
	printf("sum of digits = %d",sum);
return 0;
}
