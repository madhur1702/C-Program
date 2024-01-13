#include<stdio.h>
int main()
{
	char ch[10];
	int i=0,vowel=0,cons=0;
	printf("enter string");
	scanf("%s",ch);
	printf("string=%s",ch);
	while(ch[i]!='\0');
	{
		if(ch[i]=='a'||ch[i]=='e'||ch[i]=='i'||ch[i]=='o'||ch[i]=='u')
		{
			vowel++;
		}
		else if(ch[i]=='A'||ch[i]=='E'||ch[i]=='I'||ch[i]=='O'||ch[i]=='U')
		{
		    vowel++;	
		}
		else
		{
			cons++;
		}
		i++;
	}
	printf("vowels=%d,consonent=%d",vowel,cons);
	return 0;
}
