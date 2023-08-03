%{
#include<stdio.h>
%}

%%

[0-3][0-9]{1}-[0-1][1-9]{1}-[1-2][0-9]{3} {printf("DOB IS VALID");}
.+ {printf("DOB IS INVALID");}

%%

int yywrap()
{}

int main()
{
printf("ENTER DOB IN THE FORMAT DD-MM-YYYY : ");
yylex();
return 0;
}
