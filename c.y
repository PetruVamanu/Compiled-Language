%{
    #include <stdio.h>
    #include <string.h>
    #include <math.h>

    extern FILE* yyin;
    extern char* yytext;
    extern int yylineno; 
%}
%start s

%token INT STRING WHILE IF ELSE ID C_INT C_FLOAT C_STRING BEGINP ENDP
%%
s : declaratii functii structuri progr
  | declaratii structuri progr
  ;
declaratii: declaratii declaratie ';'
          | declaratie ';'
          ;
declaratie: INT ID 
          | STRING ID
          ;
functii : functii functie ';' 
        | functie ';'
        ;
functie : INT ID '(' params ')'
        | INT ID '(' ')'
        | STRING ID '('params')'
        | STRING ID '(' ')'
        ;
params : declaratie ',' params
       | declaratie
       ;
structuri : 
          ;
progr : BEGINP {printf("main");}
        instrs ENDP 
      ;
instrs: instr ';' instrs
      | instr ';'
      ;
instr : ID '=' C_INT
      | ID '=' ID
%%

void yyerror(char * s){
  printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
  yyin=fopen(argv[1],"r");
  yyparse();
} 
