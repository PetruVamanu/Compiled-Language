%{
    #include <stdio.h>
    #include "comp.tab.h"
%}
%option noyywrap
%%
"int" {return INT;}
"string" {return STRING;}
"while" {return WHILE;}
"if" {return IF;}
"else" {return ELSE;}
"begin" {return BEGINP;}
"end" {return ENDP;}
[a-zA-Z][a-zA-Z0-9]* {return ID;}
0|[1-9][0-9]* {return C_INT;}
(0|[1-9][0-9]*)\.[0-9]+ {return C_FLOAT;}
\"[a-zA-Z]*\" {return C_STRING;}
[ \t] ;
\n {yylineno++;}
\r ;
. {return yytext[0];}
