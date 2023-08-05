%{
#include <stdio.h>
%}

%%
"apple"    { printf("orange "); }
.          { printf("%c", yytext[0]); }
%%
int yywrap()
{}


int main(int argc, char** argv) {
    yylex();
    
}
