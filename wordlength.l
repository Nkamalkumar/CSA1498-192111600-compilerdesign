%{
#include<stdio.h>
int count=0,s=0;
%}

%%

[^\t\n]+ {count+=yyleng;}
[ \t] {s+=yyleng;}

%%

int yywrap()
{}

int main()
{
printf("\nEnter the word:");
yylex();
printf("\nThe length of the word is:%d",count-s);
}
