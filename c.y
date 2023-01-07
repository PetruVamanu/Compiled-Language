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

    const char *symb_table_path = "symbol_table.txt";
    const char *func_table_path = "symbol_table_functions.txt";
    char decodeType[6][20] = {"int", "boolean", "real", "char", "string", "void"};

    typedef struct {
      short typeName;
      // 0 - int, 1 - boolean, 2 - real, 3 - char, 4 - string
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
      // only a / means global  
      // /~/ means inside main,
      // '/for/' or '/while' means inside a for/while   
      // /funcName/ - means inside the funcName function
      // /&objName/ - means a class  
      // /&objName/method/ - means inside a method of an object
      // Example of scopes : '/~/for/while/for/' OR '/~/printAns/' OR /&myClass/ OR /~/&myClass/printAns/

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
      char scope[MAX_SCOPE_LEN];
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
    FunctionList allFunctions;

    Variable currentVariable;
    Function currentFunction;

    int forCounter = 0, whileCounter = 0, ifCounter = 0, elseCounter = 0;
    short isFunction;

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
    
    void insert_func(FunctionList *funcTable, Function *newFunc)
    {
      int funcNum = funcTable->funcNumber;

      if(funcNum >= MAX_FUNC_NUM) {
        printf("Function number limit is excedeed!");
        exit(1);
      }
      
      strncpy(funcTable->functions[funcNum].name, newFunc->name, MAX_VAR_LEN);
      strncpy(funcTable->functions[funcNum].scope, newFunc->scope, MAX_SCOPE_LEN);

      funcTable->functions[funcNum].line = newFunc->line;
      funcTable->functions[funcNum].returnType = newFunc->returnType;

      init_varList(&funcTable->functions[funcNum].parameters);

      for(int i = 0; i < newFunc->parameters.varNumber; ++i) {
        insert_var(&funcTable->functions[funcNum].parameters, &newFunc->parameters.variables[i]);
      }

      funcNum++;
      funcTable->funcNumber = funcNum;
    }

    void clear_varList(VariableList *varTable) 
    {
        free(varTable->variables);
        varTable->varNumber = 0;
    }

    void clear_funcList(FunctionList *funcs) 
    {
      free(funcs->functions);
      funcs->funcNumber = 0;
    } 

    void add_scope(char *add, short isClass) 
    {
        char addPath[MAX_SCOPE_LEN];
        if(!isClass)
          snprintf(addPath, MAX_SCOPE_LEN, "%s/", add);
        else
          snprintf(addPath, MAX_SCOPE_LEN, "&%s/", add);

        strcat(currentScope, addPath);
    }

    void remove_from_scope() 
    {
        int scopeLen = strlen(currentScope) - 1;
        currentScope[scopeLen--] = '\0';
        while(currentScope[scopeLen] != '/') {
          currentScope[scopeLen--] = '\0';
        }
    }
    
    void create_symbol_table() {
      FILE *F = fopen(symb_table_path, "w");
      if(!F) {
        fprintf(stderr, "Error at opening symbol_table_path!");
        exit(2);
      }
      fprintf(F, "The following variables where declared in the program:\n");
      for(int i = 0; i < allVariables.varNumber; ++i) {
          fprintf(F, "%d. Name: %s, ", i + 1, allVariables.variables[i].name);
          
          if(allVariables.variables[i].typeInfo.isConst) {
            fprintf(F, "State: Constant, ");
          }
          else {
            fprintf(F, "State: Mutable, ");
          }
          fprintf(F, "Structure: ");
          if(allVariables.variables[i].typeInfo.isArray) {
            fprintf(F, "Array of %d elements, ", allVariables.variables[i].typeInfo.arrayLen);
          }
          else {
            fprintf(F, "Simple, ");
          }
          fprintf(F, "Type: %s, ", decodeType[allVariables.variables[i].typeInfo.typeName]);
          fprintf(F, "Line: %d, ", allVariables.variables[i].line);
          fprintf(F, "Scope: %s\n", allVariables.variables[i].scope);
      }
    }
    void create_function_table() 
    {
      FILE *F = fopen(func_table_path, "w");
      if(!F) {
        fprintf(stderr, "Error at opening func_table_path!");
        exit(2);
      }

      fprintf(F, "The following functions where defined in the program:\n");
      for(int i = 0; i < allFunctions.funcNumber; ++i) {
  
        fprintf(F, "%d) Name: %s, ", i + 1, allFunctions.functions[i].name);
        
        fprintf(F, "Return Type: %s, ", decodeType[allFunctions.functions[i].returnType]);
        fprintf(F, "Scope: %s, ", allFunctions.functions[i].scope);
        fprintf(F, "Line: %d, ", allFunctions.functions[i].line);

        fprintf(F, "Parameters: \n");
        
        for(int j = 0; j < allFunctions.functions[i].parameters.varNumber; ++j) {
          Variable *curVar = &(allFunctions.functions[i].parameters.variables[j]);
          fprintf(F, "    %d.%d) Name: %s, ", i + 1, j + 1, curVar->name);
          if(curVar->typeInfo.isConst) {
            fprintf(F, "State: Constant, ");
          }
          else {
            fprintf(F, "State: Mutable, ");
          }

          fprintf(F, "Structure: ");
          if(curVar->typeInfo.isArray) {
            fprintf(F, "Array of %d elements, ", curVar->typeInfo.arrayLen);
          }
          else {
            fprintf(F, "Simple, ");
          }
          fprintf(F, "Type: %s\n", decodeType[curVar->typeInfo.typeName]);
          
        }
        //fprintf();
      }
    }
    short check_variable_already(VariableList *varTable, char *name, char *scope, int line) 
    {
      int varNum = varTable->varNumber;
      for(int i = 0; i < varNum; ++i) {
        if(!strcmp(name, varTable->variables[i].name)
           && !strcmp(scope, varTable->variables[i].scope)) {
            printf("Variable %s is defined multiple times (line %d and line %d) in the same scope\n",
              name, varTable->variables[i].line, line
            );
            return 1;
        }
      }
      return 0;
    }

    short check_prev_defined(VariableList *varTable, char *name, char *scope, int line) 
    {
      int varNum = varTable->varNumber;
      for(int i = 0; i < varNum; ++i) {
        if(!strcmp(name, varTable->variables[i].name)
           && strstr(scope, varTable->variables[i].scope)) {
            return 0;
        }
      }
      printf("Variable %s on line %d was not previously defined!\n", name, line);
      return 1;
    }
%}

%union 
{
    int intval;
    char* strval;
}

%start s

%token INT CLASS VOID FUNCTION FLOAT STRING WHILE BTRUE BFALSE BOOL IF ELSE C_STRING BEGINP ENDP CONST
EQ NEQ LEQ GEQ OR AND FOR LT GT RET TYPEOF EVAL CHAR C_CHAR
<strval>ID 
<intval>C_INT C_FLOAT ARRAY

%%

s : declaratii main { printf("cod sintactic corect! ;) \n"); }
  ;

declaratii : declaratii declarare
           | declarare
           | 
           ;

declarare : var_decl 
          | func_decl 
          | class_decl
          ;

type : is_const primitive_type
     ;

primitive_type : INT {
                  if(isFunction) 
                    currentFunction.returnType = 0;
                  else currentVariable.typeInfo.typeName = 0;
               }
               | FLOAT {
                  if(isFunction) 
                    currentFunction.returnType = 2;
                  else currentVariable.typeInfo.typeName = 2;
               }
               | BOOL {
                  if(isFunction) 
                    currentFunction.returnType = 1;
                  else currentVariable.typeInfo.typeName = 1;
               }
               | STRING {
                  if(isFunction) 
                    currentFunction.returnType = 4;
                  else currentVariable.typeInfo.typeName = 4;
               }
               | CHAR {
                  if(isFunction) 
                    currentFunction.returnType = 3;
                  else currentVariable.typeInfo.typeName = 3;
               }
               ;

return_type : primitive_type  
            | VOID {
              currentFunction.returnType = 5;
            }
            ;
            // to add return of arrays

func_decl : FUNCTION {isFunction = 1;} return_type ID 
          {
            strncpy(currentFunction.scope, currentScope, MAX_SCOPE_LEN);
            strncpy(currentFunction.name, $4, MAX_VAR_LEN);
            add_scope($4, 0); 
            init_varList(&currentFunction.parameters); 
            currentFunction.line = yylineno;
            isFunction = 0;
          } 
          '(' param_list ')' '{' scope_body '}' 
          {
            remove_from_scope(); 
            insert_func(&allFunctions, &currentFunction);
            clear_varList(&currentFunction.parameters);
          }
          ;
          

param_list : param {
              insert_var(&currentFunction.parameters, &currentVariable);
           }
           | param {
              insert_var(&currentFunction.parameters, &currentVariable);
           } ',' param_list
           |
           ;

param : type ID {
        currentVariable.typeInfo.isArray = 0;
        currentVariable.typeInfo.arrayLen = 1;
        currentVariable.line = yylineno;
        strncpy(currentVariable.name, $2, MAX_VAR_LEN);
        strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
      }
      | ARRAY type '[' C_INT ']' ID {
        currentVariable.typeInfo.isArray = 1;
        currentVariable.typeInfo.arrayLen = $4;
        currentVariable.line = yylineno;
        strncpy(currentVariable.name, $6, MAX_VAR_LEN);
        strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
      }
     ;

is_const : CONST {
            currentVariable.typeInfo.isConst = 1;
         }
         | {
            currentVariable.typeInfo.isConst = 0;
         }
         ;


class_decl : CLASS ID {add_scope($2, 1);} '{' class_content '}' {remove_from_scope();}
           ;
class_content : var_decl class_content
              | func_decl ';' class_content
              |
              ;

class_method_call : ID '.' function_call
                  ;

var_decl : type 
         {
            currentVariable.typeInfo.isArray = 0;
            currentVariable.typeInfo.arrayLen = 1;
         } var_list ';'
         | ARRAY type '[' C_INT ']' 
         {
            currentVariable.typeInfo.isArray = 1;
            currentVariable.typeInfo.arrayLen = $4;
         } array_list ';'
         ;

array_list : array_var {
              insert_var(&allVariables, &currentVariable);
           }
           | array_var {
              insert_var(&allVariables, &currentVariable);
           } ',' array_list
           ;

array_var : ID {
              for(int i = 0; i < currentVariable.typeInfo.arrayLen; ++i) {
                currentVariable.typeInfo.isInit[i] = 0;
              }
              currentVariable.line = yylineno;
              strncpy(currentVariable.name, $1, MAX_VAR_LEN);
              strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
          }
          | ID {
              for(int i = 0; i < currentVariable.typeInfo.arrayLen; ++i) {
                currentVariable.typeInfo.isInit[i] = 1;
              }
              currentVariable.line = yylineno;
              strncpy(currentVariable.name, $1, MAX_VAR_LEN);
              strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
          } '=' '{' array_content '}'
          ;

array_content : atomic_value
              | atomic_value ',' array_content
              ;

var_list : variable {
            int returnVal = check_variable_already(&allVariables, currentVariable.name, currentScope, yylineno);
            if(!returnVal) {
              insert_var(&allVariables, &currentVariable);
            }
         }
         | variable {
            int returnVal = check_variable_already(&allVariables, currentVariable.name, currentScope, yylineno);
            if(!returnVal) {
              insert_var(&allVariables, &currentVariable);
            }
         } ',' var_list
         ;

variable : ID {
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
             | C_CHAR
             | C_STRING
             | ID {
                check_prev_defined(&`allVariables, $1, currentScope, yylineno);
             }
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

main : BEGINP {add_scope("~", 0);} scope_body ENDP {remove_from_scope();}
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

for_loop : FOR 
         {
            forCounter++; 
            char newScope[MAX_VAR_LEN];
            snprintf(newScope, MAX_VAR_LEN, "for_%d", forCounter);
            add_scope(newScope, 0);
         } 
         '(' for_init ';' for_condition ';' for_step ')' '{' scope_body '}' 
         {
            remove_from_scope();
         }
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

while_loop : WHILE 
            {
              whileCounter++; 
              char newScope[MAX_VAR_LEN];
              snprintf(newScope, MAX_VAR_LEN, "while_%d", whileCounter);
              add_scope(newScope, 0);
            } 
            '(' expression_value ')' '{' scope_body '}' 
            {
              remove_from_scope();
            }
           ;

if_statement : IF 
             {
                ifCounter++; 
                char newScope[MAX_VAR_LEN];
                snprintf(newScope, MAX_VAR_LEN, "if_%d", ifCounter);
                add_scope(newScope, 0);
             } 
             '(' expression_value ')' '{' scope_body '}' 
             {
              remove_from_scope();
             } 
             else_statement
             ;

else_statement : ELSE 
               {
                  elseCounter++; 
                  char newScope[MAX_VAR_LEN];
                  snprintf(newScope, MAX_VAR_LEN, "else_%d", elseCounter);
                  add_scope(newScope, 0);
               } 
               '{' scope_body '}' 
               {
                  remove_from_scope();
               }
               | 
               ;

return_statement : RET expression_value

%%

void yyerror(char *s)
{
  printf("eroare: %s la linia:%d\n", s, yylineno);
}

int main(int argc, char** argv)
{
  yyin = fopen(argv[1],"r");

  init_varList(&allVariables);
  init_funcList(&allFunctions);

  strncpy(currentScope, "/", MAX_SCOPE_LEN);

  yyparse();

  create_symbol_table();
  create_function_table();

  printf("The number of functions is %d: \n", allFunctions.funcNumber);

  clear_varList(&allVariables);
  clear_funcList(&allFunctions);
} 
