%{
    #include <stdio.h>
    #include <string.h>
    #include <math.h>

    extern FILE* yyin;
    extern char* yytext;
    extern int yylineno; 
%}
%start s

%token INT CLASS VOID FUNCTION FLOAT STRING WHILE BTRUE BFALSE BOOL IF ELSE ID C_INT C_FLOAT C_STRING BEGINP ENDP CONST ARRAY
EQ NEQ LEQ GEQ OR AND FOR LT GT 
%%

s : declaratii main { printf("cod sintactic corect! ;) \n"); }
  ;

declaratii : declaratii declarare
           | declarare
           | 
           ;

type : is_const primitive_type
     ;

primitive_type : INT
               | FLOAT
               | BOOL
               | STRING
               ;

return_type : primitive_type  
            | VOID
            ;
            // to add return of arrays

func_decl : FUNCTION return_type ID '(' param_list ')' '{' '}'
          ;
          //to add block of instructions

param_list : args
           |
           ;

args : primitive_type ID
     | primitive_type ID ',' args
     ;

is_const : CONST
         |
         ;

declarare : var_decl 
          | func_decl
          | class_decl
          ;

class_decl : CLASS ID '{' class_content '}'
           ;

class_content : var_decl class_content
              | func_decl ';' class_content
              |
              ;

var_decl : type var_list ';'
         | ARRAY type '[' C_INT ']' array_list ';'
         ;

array_list : array_var
           | array_var ',' array_list
           ;

array_var : ID 
          | ID '=' '{' array_content '}'
          ;

array_content : atomic_value
              | atomic_value ',' array_content
              ;

var_list : variable 
         | variable ',' var_list
         ;

variable : ID
         | var_assignment
         ;

atomic_value : C_INT
             | C_FLOAT
             | BFALSE 
             | BTRUE
             | C_STRING
             | ID 
             ;

expression_value : atomic_value 
                 | expression_value operator expression_value
                 | '(' expression_value operator expression_value ')'
                 ;

operator : '+'
         | '-'
         | '*'
         | '/'
         | EQ 
         | NEQ 
         | LEQ
         | GEQ 
         | OR 
         | AND 
         | LT 
         | GT 
         ;

var_assignment : ID '=' expression_value
                      ;

main : BEGINP scope_body ENDP 
     ;

scope_body : var_decl scope_body
           /* | function_call scope_body */
           | var_assignment ';' scope_body
           | repetitive_loop scope_body
           | if_statement scope_body
           | 
           ;

/* function_call :   */

repetitive_loop : for_loop 
                | while_loop
                ;

for_loop : FOR '(' for_init ';' for_condition ';' for_step ')' '{' scope_body '}'
         ;

for_init : primitive_type var_list
         | expression_value 
         | var_assignment 
         |
         ;

for_condition : expression_value
              | 
              ;

for_step : var_assignment
         | 
         ;

while_loop : WHILE '(' expression_value ')' '{' scope_body '}'
           ;

if_statement : IF '(' expression_value ')' '{' scope_body '}' 
             | IF '(' expression_value ')' '{' scope_body '}' ELSE '{' scope_body '}' 
             ;
%%

void yyerror(char * s){
  printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
  yyin=fopen(argv[1],"r");
  yyparse();
} 
