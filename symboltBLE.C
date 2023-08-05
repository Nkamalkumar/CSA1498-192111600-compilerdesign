#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	char a[100],s=5;
	printf("enter the string:");
	scanf("%s",&a);
	int l=strlen(a),i;
	printf("symbol\tvalue\taddress\t token\n");
	for(i=0;i<l;i++)
	{
		if(isalpha(a[i]))
		{
			if(a[i]=='a')
			{
				int b=10;
				printf("%c\t%d\t %d\t identifier\n",a[i],b,&a[i]);
			}
			else if(a[i]=='b')
			{
				int c=5;
				printf("%c\t%d\t %d\t identifier\n",a[i],c,&a[i]);
			}
			else
			{
				printf("%c\t8\t %d\t identifier\n",a[i],&a[i]);
			}	
		}
		else if(isdigit(a[i]))
		{
			printf("%c\t%c\t %d\t  numerical\n",a[i],a[i],&a[i]);
		}
		else
		{
			printf("%c\t \t %d\t  operator\n",a[i],&a[i]);
		}
	}
}
