%{
    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include <stdlib.h>
    
    #include "config.h"
    #include "utils.h"

    extern FILE* yyin;
    extern char* yytext;
    extern int yylineno; 

%}

%union 
{
    int intval;
    char* strval;
    struct AstNode *astNode;
    struct NodeInfo *nodeVal;
}

%start s

%token INT C_FLOAT ARRAY CLASS VOID FUNCTION FLOAT STRING WHILE BTRUE BFALSE BOOL IF ELSE BEGINP ENDP CONST FOR RET TYPEOF EVAL CHAR 
<strval>ID EQ NEQ LEQ GEQ OR AND LT GT C_CHAR C_STRING 
<intval>C_INT 

%type<astNode>expression_value
%type<nodeVal>atomic_value function_call 

%left OR
%left AND 
%left EQ NEQ
%left LT GT LEQ GEQ
%left '+' '-' 
%left '*' '/'
%left '(' ')'

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
          '(' param_list ')' 
          {
            insert_func(&allFunctions, &currentFunction);
            clear_varList(&currentFunction.parameters);
          }
          '{' scope_body '}' 
          {
            remove_from_scope(); 
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
        currentVariable.value[0] = 0; 
        // initialized with 0
        currentVariable.typeInfo.isArray = 0;
        currentVariable.typeInfo.arrayLen = 1;
        currentVariable.line = yylineno;
        strncpy(currentVariable.name, $2, MAX_VAR_LEN);
        strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
      }
      | ARRAY type '[' C_INT ']' ID {
        currentVariable.typeInfo.isArray = 1;
        if($4 > MAX_ARRAY_LEN) {
          printf("Array elements limit exceeded on line %d\n", yylineno);
        }
        
        currentVariable.typeInfo.arrayLen = min($4, MAX_ARRAY_LEN);
        for(int i = 0; i < currentVariable.typeInfo.arrayLen; ++i) {
          currentVariable.value[i] = 0;
          // whole array initialized with 0
        }

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
              currentVariable.line = yylineno;
              strncpy(currentVariable.name, $1, MAX_VAR_LEN);
              strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
          }
          | ID {
              currentVariable.line = yylineno;
              strncpy(currentVariable.name, $1, MAX_VAR_LEN);
              strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
              arrayInitPos = 0;
          } '=' '{' array_content '}'
          ;

array_content : atomic_value {
                if(arrayInitPos >= currentVariable.typeInfo.arrayLen) {
                  printf("Array length excedeed when initializing on line %d. Array Length is %d, while initialization list length is %d.\n", 
                  yylineno, currentVariable.typeInfo.arrayLen, arrayInitPos + 1);
                }
                else {
                  if($1->nodeType == 2 && $1->dataType == 0) {
                    currentVariable.value[arrayInitPos] = atoi($1->value);
                  }
                  else {
                    currentVariable.value[arrayInitPos] = 0;
                  }
                }
                arrayInitPos++; 
              }
              | atomic_value {
                if(arrayInitPos < currentVariable.typeInfo.arrayLen) {
                  if($1->nodeType == 2 && $1->dataType == 0) {
                    currentVariable.value[arrayInitPos] = atoi($1->value);
                  }
                  else {
                    currentVariable.value[arrayInitPos] = 0;
                  }
                }
                arrayInitPos++; 
              } ',' array_content
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
            currentVariable.line = yylineno;
            strncpy(currentVariable.name, $1, MAX_VAR_LEN);
            strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
         }
         | ID 
         {
            currentVariable.line = yylineno;
            strncpy(currentVariable.name, $1, MAX_VAR_LEN);
            strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
          } 
          '=' expression_value 
          {
            // the case where the variable is initialized + assigned to an expression:))
            insert_declVar_AstList(allAssign, $1, currentScope, $4, yylineno, currentVariable.typeInfo.typeName);
          }
         ;

atomic_value : C_INT {
                $$ = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                $$->nodeType = 2;
                $$->dataType = 0;
                snprintf($$->value, MAX_VAR_LEN, "%d", $1);
             }
             | C_FLOAT
             {
                $$ = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                $$->nodeType = 2;
                $$->dataType = 2;
                snprintf($$->value, MAX_VAR_LEN, "%s", "float");
             }
             | BFALSE
             {
                $$ = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                $$->nodeType = 2;
                $$->dataType = 1;
                snprintf($$->value, MAX_VAR_LEN, "%s", "false");
             } 
             | BTRUE
             {
                $$ = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                $$->nodeType = 2;
                $$->dataType = 1;
                snprintf($$->value, MAX_VAR_LEN, "%s", "true");
             }
             | C_CHAR
             {
                $$ = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                $$->nodeType = 2;
                $$->dataType = 3;
                snprintf($$->value, MAX_VAR_LEN, "%s", $1);
             }
             | C_STRING
             {
                $$ = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                $$->nodeType = 2;
                $$->dataType = 4;
                snprintf($$->value, MAX_VAR_LEN, "%s", $1);
             }
             | ID 
             {
                int parameter = 1;
                int ret = check_var_parameter(&allFunctions, $1, currentScope);
                if(ret) {
                  parameter = 0;
                  ret = check_var_defined(&allVariables, $1, currentScope, yylineno);
                }
                $$ = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                $$->nodeType = 1;
                if(parameter) {
                  $$->dataType = extract_param_type(&allFunctions, $1, currentScope);
                }
                else {
                  $$->dataType = extract_variable_type(&allVariables, $1, currentScope);
                }
                snprintf($$->value, MAX_VAR_LEN, "%s", $1);
             }
             | function_call
             {
                $$ = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                $$->nodeType = $1->nodeType;
                $$->dataType = $1->dataType;
                snprintf($$->value, MAX_VAR_LEN, "%s", $1->value);
             }
             | ID '.' ID 
             {
               check_class_var(&allVariables, $3, $1, yylineno);
               $$ = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
               $$->nodeType = 1;
               $$->dataType = extract_class_varType(&allVariables, $3, $1);
               snprintf($$->value, MAX_VAR_LEN, "%s.%s", $1, $3);
             }
             | ID '[' C_INT ']'
             {
               check_array_defined(&allVariables, $1, currentScope, $3, yylineno);
               $$ = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
               $$->nodeType = 1;
               $$->dataType = extract_variable_type(&allVariables, $1, currentScope);
               snprintf($$->value, MAX_VAR_LEN, "%s[%d]", $1, $3);
             }
             | class_method_call
             ;

expression_value : 
                 atomic_value {
                    $$ = init_Ast($1->nodeType, $1->dataType, $1->value);
                 }
                 | 
                 expression_value '+' expression_value {
                    $$ = build_Ast("+", $1, $3, 0);
                 }  
                 |
                 expression_value '-' expression_value {
                    $$ = build_Ast("-", $1, $3, 0);
                 }  
                 |
                 expression_value '*' expression_value {
                    $$ = build_Ast("*", $1, $3, 0);
                 }  
                 |
                 expression_value '/' expression_value {
                    $$ = build_Ast("/", $1, $3, 0);
                 }  
                 |
                 expression_value EQ expression_value {
                    $$ = build_Ast("==", $1, $3, 0);
                 }  
                 |
                 expression_value NEQ expression_value {
                    $$ = build_Ast("<>", $1, $3, 0);
                 }  
                 |
                 expression_value LEQ expression_value {
                    $$ = build_Ast("<=", $1, $3, 0);
                 }  
                 |
                 expression_value GEQ expression_value {
                    $$ = build_Ast(">=", $1, $3, 0);
                 }  
                 |
                 expression_value OR expression_value {
                    $$ = build_Ast("||", $1, $3, 0);
                 }  
                 |
                 expression_value AND expression_value {
                    $$ = build_Ast("&&", $1, $3, 0);
                 }  
                 |
                 expression_value LT expression_value {
                    $$ = build_Ast("<", $1, $3, 0);
                 }  
                 |
                 expression_value GT expression_value {
                    $$ = build_Ast(">", $1, $3, 0);
                 }
                 | '(' expression_value ')' {
                    $$ = $2;
                 }
                 ;

var_assignment : ID '=' expression_value 
               {
                  int parameter = 1;
                  int ret = check_var_parameter(&allFunctions, $1, currentScope);
                  if(ret) {
                    parameter = 0;
                    ret = check_var_defined(&allVariables, $1, currentScope, yylineno);
                  }
                  if(!ret) {
                    insert_var_AstList(allAssign, $1, currentScope, $3, yylineno, parameter);
                  }
               }
               ;

class_assignment : ID '.' ID '=' expression_value 
                 {
                    int ret = check_class_var(&allVariables, $3, $1, yylineno);
                    if(!ret) {
                     insert_classVar_AstList(allAssign, $3, $1, currentScope, $5, yylineno);
                    }
                 }
                 ;

array_assignment : ID '[' C_INT ']' '=' expression_value
                 {
                    int ret = check_array_defined(&allVariables, $1, currentScope, $3, yylineno);
                    if(!ret) {
                     insert_arrayElem_AstList(allAssign, $1, $3, currentScope, $6, yylineno);
                    }
                 }
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
 
function_call : ID '(' func_arguments ')' 
              {
                $$ = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                check_func_defined(&allFunctions, $1, yylineno);
                $$->nodeType = 3;
                $$->dataType = extract_func_return(&allFunctions, $1);
                snprintf($$->value, MAX_VAR_LEN, "func");
              }
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
  
  // information about every assignation (varName, scope and AstTree coresponding to some Id)
  allAssign = (AstList *) malloc(MAX_VAR_NUM * sizeof(AstList));

  strncpy(currentScope, "/", MAX_SCOPE_LEN);

  yyparse();

  for(int i = 0; i < cntAssign; ++i) {
      printf("The variable %s on scope %s is assigned to the following value: \n", allAssign[i].varName, allAssign[i].scope);
      int expType = check_AstTypes(allAssign[i].Ast, allAssign[i].line);
      if(expType == -1) {
         continue;
      }
      if(allAssign[i].varType != expType) {
         printf("The left side of the assignment on line %d has a different type than the right side!\n", allAssign[i].line);
         printf("    The type of left side is '%s' while the type of right side is '%s'\n", decodeType[allAssign[i].varType], decodeType[expType]);
         continue;
      }
      int astResult = computeAst(allAssign[i].Ast, allAssign[i].scope, allAssign[i].line);
      update_var(allAssign[i].varName, allAssign[i].scope, astResult);
      printf("%d\n", astResult);
  }

  create_symbol_table();
  create_function_table();

  free(allAssign);

  clear_varList(&allVariables);
  clear_funcList(&allFunctions);
} 
