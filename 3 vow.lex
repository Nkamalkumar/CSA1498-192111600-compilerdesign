%{
int vowel_count=0;
int constant_count=0;
%}

%%

[aeiouAEIOU] {vowel_count++;}

[a-zA-z] {constant_count++;}

%%

int yywrap()
{}

int main()
{
printf("\nEnter the string:");
yylex();
printf("no. of vowels are:%d\n",vowel_count);
printf("no. of consonants are:%d\n",constant_count);
return  0;
}				
