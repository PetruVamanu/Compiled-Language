%{
    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include <stdlib.h>

    extern FILE* yyin;
    extern char* yytext;
    extern int yylineno; 

    #define MAX_VAR_LEN 32
    #define MAX_SCOPE_LEN 1024
    #define MAX_ARRAY_LEN 128
    #define MAX_VAR_NUM 128
    #define MAX_FUNC_NUM 128

    typedef struct {
      short typeName;
      // 0 - int, 1 - boolean, 2 - real, 3 - string 
      short isConst;
      // isConst = 0 if variabile is not constant, 1 otherwise
      short isArray;
      // isArray = 0 if variable is not an array, 1 otherwise 
      short isInit[MAX_ARRAY_LEN];
      // isInit[i] - if the ith component of the array is initialized. 
      // if isArray = 0 -> check isInit[0] to check if the whole variable is initialized 
      short arrayLen;
      // if isArray = 0 -> arrayLen will always be 1 (convention)
    } 
    Type;

    typedef struct {
      Type typeInfo;
      char name[MAX_VAR_LEN];
      char scope[MAX_SCOPE_LEN];
      int line;
      // scope will be of the following form: 
      // only an / means global  
      // /~ means inside main,
      // '/for' or '/while' means inside a for/while   
      // /f_funcName - means inside the funcName function
      // /objName - means a class  
      // /&objName.method - means inside a method of an object
      // Example of scopes : '/~/for/while/for' OR '/~/printAns' OR /~/&myClass OR /~/&myClass.printAns
    }
    Variable;

    typedef struct {
      Variable *variables;
      int varNumber;
    }
    VariableList;

    typedef struct {
      VariableList parameters;
      char name[MAX_VAR_LEN];
      short returnType;
      int line;
    } 
    Function;

    typedef struct {
      Function *functions;
      int funcNumber;
    } 
    FunctionList;

    VariableList allVariables;
    Variable currentVariable;
    char currentScope[MAX_SCOPE_LEN];

    void init_varList(VariableList *varTable) 
    {
      varTable->variables = (Variable *) malloc(MAX_VAR_NUM * sizeof(Variable));
      varTable->varNumber = 0;
    }

    void init_funcList(FunctionList *funcs) 
    {
      funcs->functions = (Function *) malloc(MAX_FUNC_NUM * sizeof(Function));
      funcs->funcNumber = 0;
    } 

    void insert_var(VariableList *varTable, Variable *newVar)
    {
      int varNum = varTable->varNumber;

      if(varNum >= MAX_VAR_NUM) {
        printf("Variable number limit is excedeed!");
        exit(1);
      }
      
      strncpy(varTable->variables[varNum].name, newVar->name, MAX_VAR_LEN);
      strncpy(varTable->variables[varNum].scope, newVar->scope, MAX_SCOPE_LEN);
      
      varTable->variables[varNum].line = newVar->line;
      varTable->variables[varNum].typeInfo.typeName = newVar->typeInfo.typeName;
      varTable->variables[varNum].typeInfo.isConst = newVar->typeInfo.isConst;
      varTable->variables[varNum].typeInfo.isArray = newVar->typeInfo.isArray;

      int arrayLen = newVar->typeInfo.arrayLen;

      if(arrayLen >= MAX_ARRAY_LEN) {
        printf("Array length limit is excedeed!");
        exit(1);
      }

      varTable->variables[varNum].typeInfo.arrayLen = arrayLen;

      for(int i = 0; i < arrayLen; ++i) {
        varTable->variables[varNum].typeInfo.isInit[i] = newVar->typeInfo.isInit[i];
      } 
      
      varNum++;
      varTable->varNumber = varNum;
    }
    
    void clear_varList(VariableList *varTable) 
    {
        free(varTable->variables);
        varTable->varNumber = 0;
    }
%}

%union 
{
    int intval;
    char* strval;
}

%start s

%token INT CLASS VOID FUNCTION FLOAT STRING WHILE BTRUE BFALSE BOOL IF ELSE <strval>ID C_INT C_FLOAT C_STRING BEGINP ENDP CONST ARRAY
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

primitive_type : INT {
                  currentVariable.typeInfo.typeName = 0;
               }
               | FLOAT {
                  currentVariable.typeInfo.typeName = 2;
               }
               | BOOL {
                  currentVariable.typeInfo.typeName = 1;
               }
               | STRING {
                  currentVariable.typeInfo.typeName = 3;
               }
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

is_const : CONST {
            currentVariable.typeInfo.isConst = 1;
         }
         | {
            currentVariable.typeInfo.isConst = 0;
         }
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

var_list : variable {
            insert_var(&allVariables, &currentVariable);
         }
         | variable {
            insert_var(&allVariables, &currentVariable);
         } ',' var_list
         ;

variable : ID {
            currentVariable.typeInfo.isArray = 0;
            currentVariable.typeInfo.arrayLen = 1;
            currentVariable.typeInfo.isInit[0] = 0;
            currentVariable.line = yylineno;
            strncpy(currentVariable.name, $1, MAX_VAR_LEN);
            strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
         }
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

var_assignment : ID {
                  currentVariable.typeInfo.isArray = 0;
                  currentVariable.typeInfo.arrayLen = 1;
                  currentVariable.typeInfo.isInit[0] = 1;
                  currentVariable.line = yylineno;
                  strncpy(currentVariable.name, $1, MAX_VAR_LEN);
                  strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
               } '=' expression_value 
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
  yyin = fopen(argv[1],"r");

  init_varList(&allVariables);
  strncpy(currentScope, "/", MAX_SCOPE_LEN);

  yyparse();

  for(int i = 0; i < allVariables.varNumber; ++i) {
    printf("%s %d %d\n", allVariables.variables[i].name, allVariables.variables[i].typeInfo.isArray, allVariables.variables[i].typeInfo.isInit[0]);
  }

  clear_varList(&allVariables);

} 
