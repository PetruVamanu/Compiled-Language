%{
    #include <stdio.h>
    #include "c.tab.h"
%}
%option noyywrap
%%
"const" {return CONST;}
"array" {return ARRAY;}
"int" {return INT;}
"const" {return CONST;}
"function" {return FUNCTION;}
"class" {return CLASS;}
"real" {return FLOAT;}
"boolean" {return BOOL;}
"string" {return STRING;}
"true" {return BTRUE;}
"false" {return BFALSE;}
"while" {return WHILE;}
"if" {return IF;}
"else" {return ELSE;}
"begin" {return BEGINP;}
"void" {return VOID;}
"end" {return ENDP;}
[a-zA-Z][a-zA-Z0-9]* {return ID;}
0|[1-9][0-9]* {return C_INT;}
(0|[1-9][0-9]*)\.[0-9]+ {return C_FLOAT;}
\"[a-zA-Z]*\" {return C_STRING;}
[ \t] ;
\n {yylineno++;}
\r ;
. {return yytext[0];}
