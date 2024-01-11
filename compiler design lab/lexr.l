%{
#include <stdio.h>
%}

%%

[ \t\n]                  /* skip whitespace */
[a-zA-Z][a-zA-Z0-9]*     printf("IDENTIFIER: %s\n", yytext);
[0-9]+                   printf("INTEGER: %s\n", yytext);
[-+*/()]                printf("OPERATOR: %s\n", yytext);
.                       printf("INVALID TOKEN: %s\n", yytext);

%%

int main() {
    yylex();
    return 0;
}
