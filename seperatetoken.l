%{
#include <stdio.h>
%}

DIGIT [0-9]
ALPHA [a-zA-Z]
IDENTIFIER {ALPHA}({ALPHA}|{DIGIT})*
NUMBER {DIGIT}+(\.{DIGIT}+)?([eE][+-]?{DIGIT}+)?

%%

{IDENTIFIER} printf("IDENTIFIER: %s\n", yytext);
{NUMBER} printf("NUMBER: %s\n", yytext);
"+" printf("ADD_OP\n");
"-" printf("SUB_OP\n");
"*" printf("MUL_OP\n");
"/" printf("DIV_OP\n");
"=" printf("ASSIGN_OP\n");
"(" printf("LEFT_PAREN\n");
")" printf("RIGHT_PAREN\n");
\n {/*Ignore newline */ }
[\t]+ {/* Ignore whitespace */ }
.{/* Ignore any other characters */ }

%%

int yywrap()
{}

int main()
{
    yylex();
    return 0;
}
