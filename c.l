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
"char" {return CHAR;}
"true" {return BTRUE;}
"false" {return BFALSE;}
"for" {return FOR;}
"while" {return WHILE;}
"if" {return IF;}
"else" {return ELSE;}
"begin" {return BEGINP;}
"void" {return VOID;}
"return" {return RET;}
"end" {return ENDP;}
"==" {return EQ;}
"!=" {return NEQ;}
"<=" {return LEQ;}
"<" {return LT;}
">" {return GT;}
">=" {return GEQ;}
"||" {return OR;}
"&&" {return AND;}
"Eval" {return EVAL;}
"TypeOf" {return TYPEOF;}

[a-zA-Z][a-zA-Z0-9]* {
    yylval.strval = strdup(yytext); 
    return ID;
}

0|[1-9][0-9]* {
    yylval.intval = atoi(yytext); 
    return C_INT; 
}

(0|[1-9][0-9]*)\.[0-9]+ {return C_FLOAT;}
\"[?!,.;" "a-zA-Z]*\" {return C_STRING;}
\'[?!,.;" "a-zA-Z]\' {return C_CHAR;}
[ \t] ;
\n {yylineno++;}
\r ;
. {return yytext[0];}
