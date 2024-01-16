#include <stdio.h>
int main()
{
	int num1,num2,ans,choice;
	printf("\n\n Menu");
	printf("\n\n 1.Addition");
	printf("\n\n 2.Subtraction");
	printf("\n\n 3.Multiplication");
	printf("\n\n 4.Division");
	printf("\n\n Enter your choice(1,2,3,4)");
	scanf("\n\n %d",&choice);
	printf("\n\n enter any two no.");
	scanf("\n\n %d%d",&num1,&num2);
	if(choice==1)
	{
		ans=num1+num2;
		printf("Addition = %d",ans);
	}
	else if(choice==2)
	{
		ans=num1-num2;
		printf("Subtraction = %d",ans);
	}
	else if(choice==3)
	{
		ans=num1*num2;
		printf("Multiplication = %d",ans);
	}
	else if(choice==4)
	{
		if(num2==0)
		{
			printf("\n cannot divide by zero");
		}
		else
		{
			ans=num1/num2;
			printf("\n Division = %d",ans);
		}
	}
	else
	{
		printf("wrong choice");
	}
	return 0;
}
