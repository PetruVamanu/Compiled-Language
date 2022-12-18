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
%%
s : declaratii main{ printf("cod sintactic corect! ;) \n"); }
  ;

declaratii : declaratii declarare
           | declarare
           | 
           ;

C_BOOL : BFALSE
       | BTRUE
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

declarare : var_decl ';'
          | func_decl
          | class_decl
          ;

class_decl : CLASS ID '{' class_content '}'
           ;

class_content : var_decl ';' class_content
              | func_decl ';' class_content
              |

var_decl : type var_list
         | ARRAY type '[' C_INT ']' array_list
         ;

array_list : array_var
           | array_var ',' array_list
           ;

array_var : ID 
          | ID '=' '{' array_content '}'
          ;

array_content : value
              | value ',' array_content
              ;

var_list : variable 
         | variable ',' var_list
         ;

value : C_INT
      | C_FLOAT
      | C_BOOL
      | C_STRING
      ;

variable : ID
         | ID '=' value
         

int_list : C_INT
         | C_INT ',' int_list
         ;


main : BEGINP program
     ;

program : ENDP
       ;
%%

void yyerror(char * s){
  printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
  yyin=fopen(argv[1],"r");
  yyparse();
} 
