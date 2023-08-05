%{
#include <stdio.h>
#include <string.h>
int count = 0; 
%}

%%
[a-zA-Z]+   {
                if (strcmp(yytext, "apple") == 0) {
                    printf("Found 'apple'\n");
                    count++;
                }
            }
.|\n        ; 

%%

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return 1;
    }

    yyin = inputFile;
    yylex();

    fclose(inputFile);

    printf("Frequency of 'apple': %d\n", count);
    return 0;
}

int yywrap() {
    return 1;
}
