%{
%}

%%

[a-z.0-9]+@[a-z]+".com"|".in" {printf("\n mail_id valid\n");}
.+ {printf("\n mail_id invalid\n");}
 
%%

int yywrap()
{}

int main()
{
printf("\n enter the mail_id:");
yylex();
}
