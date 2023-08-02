%{
%}

%%

[0-9]{2} {printf("\n digit\n");}
.+ {printf("\n not a digit\n");}
 
%%

int yywrap()
{}

int main()
{
printf("\n enter the input:");
yylex();
}
