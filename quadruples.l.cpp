#include<stdio.h>
#include<string.h>
int main()
{
char line[20];
int s[20],t=1,m=0,i=0;     
printf("Enter string:");
gets(line);
for(i=0;i<20;i++)s[i]=0;
printf("mem\top\ta1\ta2\tres\n");
for(i=2;line[i]!='\0';i++)
{
if(line[i]=='/' || line[i]=='*')
{
if(s[i]==0)
{
if(s[i+1]==0)
{
printf("\n%d\t:=\t%c\t\t t%d\n",m,line[i+1],t);
m+
s[i+1]=t++;
}
printf("%c\t",line[i]);
(s[i-1]==0)?printf("%c\t",line[i-1]):printf("t%d\t",s[i-1]);
printf("t%d \t t%d",s[i+1],t);
s[i-1]=s[i+1]=t++;
s[i]=1;
}}}
for(i=2;line[i]!='\0';i++)
{
if(line[i]=='+' || line[i]=='-')

{
if(s[i]==0)
{
if(s[i+1]==0)
{
printf("\n%d\t:=\t%c\t\t t%d\n",m,line[i+1],t);
m++;
s[i+1]=t++;
}
printf("%d\t%c\t",m,line[i]);
m++;
(s[i-1]==0)?printf("%c\t",line[i-1]):printf("t%d\t",s[i-1]);
printf("t%d \t t%d",s[i+1],t);
s[i-1]=s[i+1]=t++;
s[i]=1;
}}}
printf("\n%d\t:=\tt%d\t\t%c",m,t-1,line[0]);
m++;
return 0;
}
