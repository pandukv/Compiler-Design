variable_test.l
%{
/* This LEX program returns the tokens for the Expression */
#include "y.tab.h"
%}
%%
"int " {return INT;}
"float" {return FLOAT;}
"double" {return DOUBLE;}
[a-zA-Z]*[0-9]* { printf("\nIdentifier is %s",yytext);return ID; }
. return yytext[0];
\n return 0;
%%

int yywrap() { return 1;}
