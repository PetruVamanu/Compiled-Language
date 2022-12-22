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
EQ NEQ LEQ GEQ OR AND FOR LT GT RET TYPEOF EVAL 
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

func_decl : FUNCTION return_type ID '(' param_list ')' '{' scope_body '}'
          ;
          

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

class_method_call : ID '.' function_call
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
             | eval_call
             | typeof_call
             | function_call
             | ID '.' ID 
             | ID '[' expression_value ']'
             | class_method_call
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

class_assignment : ID '.' ID '=' expression_value
                 ;

array_assignment : ID '[' expression_value ']' '=' expression_value
                 ;

main : BEGINP scope_body ENDP 
     ;

scope_body : var_decl scope_body
           | function_call ';' scope_body
           | typeof_call ';' scope_body
           | eval_call ';' scope_body 
           | class_method_call ';' scope_body
           | var_assignment ';' scope_body
           | class_assignment ';' scope_body
           | array_assignment ';' scope_body
           | return_statement ';'
           | repetitive_loop scope_body
           | if_statement scope_body
           | 
           ;

func_arguments : expression_value
               | expression_value ',' func_arguments

function_call :  ID '(' func_arguments ')'
              ;

typeof_call : TYPEOF '(' expression_value ')'
eval_call : EVAL '(' expression_value ')'

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

return_statement : RET expression_value

%%

void yyerror(char * s){
  printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
  yyin=fopen(argv[1],"r");
  yyparse();
} 
