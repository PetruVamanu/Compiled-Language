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
    
    struct AstNode {
      short nodeType;
      // nodeType = 0 -> OP, nodeType = 1 -> ID, nodeType = 2 -> NUM, type = 3 -> OTHER 
      short dataType;
      // dataType = 0 -> int, dataType = 1 -> boolean, dataType = 2 -> real dataType = 3 -> char, dataType = 4 -> string 
      // dataType = 5 -> void, dataType = 6 -> nodeType is operation
      char value[MAX_VAR_LEN];

      struct AstNode* left;
      struct AstNode* right;  
    };

    struct NodeInfo {
      short nodeType;
      short dataType;
      char value[MAX_VAR_LEN];
    };

    struct AstNode *init_Ast(short _nodeType, short _dataType, char *_value) 
    {
      struct AstNode *Ast = (struct AstNode *) malloc(sizeof(struct AstNode));
      Ast->left = Ast->right = NULL;
      Ast->nodeType = _nodeType;
      Ast->dataType = _dataType;
      strncpy(Ast->value, _value, MAX_VAR_LEN);
      return Ast;
    }

    struct AstNode *build_Ast(char *_value, struct AstNode *_left, struct AstNode *_right, int _nodeType) 
    {
      struct AstNode *Ast = (struct AstNode *) malloc(sizeof(struct AstNode));
      Ast->left = _left;
      Ast->right = _right;
      Ast->nodeType = _nodeType;
      Ast->dataType = 6;
      strncpy(Ast->value, _value, MAX_VAR_LEN); 
      return Ast; 
    }

    typedef struct {
      char varName[MAX_VAR_LEN];
      char scope[MAX_SCOPE_LEN];
      struct AstNode *Ast;
      int varType;
    } AstList;

    VariableList allVariables;
    FunctionList allFunctions;
    
    AstList *allAssign;
    int cntAssign;

    Variable currentVariable;
    Function currentFunction;

    struct AstNode *currentAst;
    struct AstNode *newRoot;

    short nodeType, dataType, isFunction, badExpression;
    char currentValue[MAX_VAR_LEN], currentOperation[MAX_VAR_LEN];
    
    int forCounter = 0, whileCounter = 0, ifCounter = 0, elseCounter = 0;

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
    
    void create_symbol_table() 
    {
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
        if(!strcmp(name, varTable->variables[i].name) && !strcmp(scope, varTable->variables[i].scope)) {
            printf("Variable %s is defined multiple times (line %d and line %d) in the same scope\n",
              name, varTable->variables[i].line, line
            );
            return -1;
        }
      }
      return 0;
    }

    short check_var_defined(VariableList *varTable, char *name, char *scope, int line) 
    {
      int varNum = varTable->varNumber;
      for(int i = 0; i < varNum; ++i) {
        if(!strcmp(name, varTable->variables[i].name)
           && strstr(scope, varTable->variables[i].scope)) {
            return 0;
        }
      }
      printf("Variable %s on line %d was not previously defined!\n", name, line);
      return -1;
    }

    short extract_variable_type(VariableList *varTable, char *name, char *scope) 
    {
      int varNum = varTable->varNumber, deepestScope = 0, pos = -1;
      for(int i = 0; i < varNum; ++i) {
        if(!strcmp(name, varTable->variables[i].name) && strstr(scope, varTable->variables[i].scope)) {
          int scopeLen = strlen(varTable->variables[i].scope);
          if(deepestScope < scopeLen) {
            deepestScope = scopeLen;
            pos = i;
          }
        }
      }
      if(pos == -1) {
        return -1;
      }
      return varTable->variables[pos].typeInfo.typeName;
    }

    short endWith(char *str, char *pat) 
    {
        int n = strlen(str);
        int m = strlen(pat);
        if(m > n) {
          return 0;
        }
        return (strcmp(str + n - m, pat) == 0);
    }

    short check_class_var(VariableList *varTable, char *varName, char *objName, int line) 
    {
      // variable scope should end with &objName/
      char pattern[MAX_VAR_LEN];
      snprintf(pattern, MAX_VAR_LEN, "&%s/", objName);
      int varNum = varTable->varNumber;

      for(int i = 0; i < varNum; ++i) {
        if(!strcmp(varName, varTable->variables[i].name) && endWith(varTable->variables[i].scope, pattern)) {
          return 0;          
        }
      }

      printf("The %s.%s field used on line %d wasn't previously defined!\n", varName, objName, line);
      return -1;
    }

    short extract_class_varType(VariableList *varTable, char *varName, char *objName) 
    {
      char pattern[MAX_VAR_LEN];
      snprintf(pattern, MAX_VAR_LEN, "&%s/", objName);
      int varNum = varTable->varNumber;

      for(int i = 0; i < varNum; ++i) {
        if(!strcmp(varName, varTable->variables[i].name) && endWith(varTable->variables[i].scope, pattern)) {
          return varTable->variables[i].typeInfo.typeName;          
        }
      }

      return -1;
    }

    short check_array_defined(VariableList *varTable, char *name, char *scope, int index, int line)
    {
      int varNum = varTable->varNumber;
      int arrayLen = -1;

      for(int i = 0; i < varNum; ++i) {
        if(!strcmp(name, varTable->variables[i].name) && strstr(scope, varTable->variables[i].scope)) {
            if(varTable->variables[i].typeInfo.isArray) {
              arrayLen = varTable->variables[i].typeInfo.arrayLen;
            }
            break;
        }
      }
      if(arrayLen == -1) {
        printf("Array %s on line %d was not previously defined!\n", name, line);
        return -1;
      }
      if(index < 0 || index >= arrayLen) {
        printf("Index %d of array %s on line %d is out of bounds!\n", index, name, line);
        return -1;
      }
      return 0;
    }

    short check_func_defined(FunctionList *funcTable, char *name, int line) 
    {
      // scope doesn't matter at simple functions
      int funcNum = funcTable->funcNumber;
      for(int i = 0; i < funcNum; ++i) {
        if(!strcmp(name, funcTable->functions[i].name)) {
          return 0;
        }
      }
      printf("Function %s called on line %d is not defined!\n", name, line);
      return -1;
    }

    short extract_func_return(FunctionList *funcTable, char *name) 
    {
      int funcNum = funcTable->funcNumber;
      for(int i = 0; i < funcNum; ++i) {
        if(!strcmp(name, funcTable->functions[i].name)) {
          return funcTable->functions[i].returnType;
        }
      }
      return -1;
    }
    
    void dfs(struct AstNode* nod) {
      if(!nod) {
        printf("This motherfucker ripped me offf!\n");
        return;
      }
      printf("Current node. Value: %s. NodeType: %d. DataType: %d\n", nod->value, nod->nodeType, nod->dataType);
      if(nod->left) {
        printf("Left son: %s\n", nod->left->value);
        dfs(nod->left);
      }
      printf("Back at %s\n", nod->value);
      if(nod->right) {
        printf("Right son: %s\n", nod->right->value);
        dfs(nod->right);
      }
    }

    short check_var_parameter(FunctionList *funcTable, char *name, char *scope) 
    {
      int funcNum = funcTable->funcNumber;
      for(int i = 0; i < funcNum; ++i) {
        int parNum = funcTable->functions[i].parameters.varNumber;
        for(int j = 0; j < parNum; ++j) {
          if(!strcmp(funcTable->functions[i].parameters.variables[j].name, name)) {
            if(strstr(scope, funcTable->functions[i].name)) {
              // if the name of the function is contained in the variable scope -> variable might be a parameter
              return 0;
            }
          }
        }
      }
      return -1;
    }

    short extract_param_type(FunctionList *funcTable, char *name, char *scope) 
    {
      int funcNum = funcTable->funcNumber;
      for(int i = 0; i < funcNum; ++i) {
        int parNum = funcTable->functions[i].parameters.varNumber;
        for(int j = 0; j < parNum; ++j) {
          if(!strcmp(funcTable->functions[i].parameters.variables[j].name, name)) {
            if(strstr(scope, funcTable->functions[i].name)) {
              // if the name of the function is contained in the variable scope -> variable might be a parameter
              return funcTable->functions[i].parameters.variables[j].typeInfo.typeName;
            }
          }
        }
      }
      return -1;
    }

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

%type<strval>operator
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
         | ID 
         {
            currentVariable.typeInfo.isInit[0] = 1;
            currentVariable.line = yylineno;
            strncpy(currentVariable.name, $1, MAX_VAR_LEN);
            strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
          } 
          '=' expression_value 
          {
            strncpy(allAssign[cntAssign].varName, $1, MAX_VAR_LEN);
            strncpy(allAssign[cntAssign].scope, currentScope, MAX_SCOPE_LEN); 
            allAssign[cntAssign].varType = currentVariable.typeInfo.typeName;
            allAssign[cntAssign].Ast = $4;
            cntAssign++;
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
                $$->nodeType = 3;
                $$->dataType = 2;
                snprintf($$->value, MAX_VAR_LEN, "%s", "float");
             }
             | BFALSE
             {
                $$ = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                $$->nodeType = 3;
                $$->dataType = 1;
                snprintf($$->value, MAX_VAR_LEN, "%s", "false");
             } 
             | BTRUE
             {
                $$ = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                $$->nodeType = 3;
                $$->dataType = 1;
                snprintf($$->value, MAX_VAR_LEN, "%s", "true");
             }
             | C_CHAR
             {
                $$ = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                $$->nodeType = 3;
                $$->dataType = 3;
                snprintf($$->value, MAX_VAR_LEN, "%s", $1);
             }
             | C_STRING
             {
                $$ = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                $$->nodeType = 3;
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
                 expression_value operator expression_value {
                    $$ = build_Ast($2, $1, $3, 0);
                    free($2);
                 }  
                 | '(' expression_value ')' {
                    $$ = $2;
                 }
                 ;

operator : '+' {
            $$ = (char *) malloc(MAX_VAR_LEN);
            snprintf($$, MAX_VAR_LEN, "%c", '+');
         }
         | '-' {
            $$ = (char *) malloc(MAX_VAR_LEN);
            snprintf($$, MAX_VAR_LEN, "%c", '-');
         }
         | '*' {
            $$ = (char *) malloc(MAX_VAR_LEN);
            snprintf($$, MAX_VAR_LEN, "%c", '*');
         }
         | '/' {
            $$ = (char *) malloc(MAX_VAR_LEN);
            snprintf($$, MAX_VAR_LEN, "%c", '/');
         }
         | EQ {
            $$ = (char *) malloc(MAX_VAR_LEN);
            snprintf($$, MAX_VAR_LEN, "%s", $1);
         }
         | NEQ {
            $$ = (char *) malloc(MAX_VAR_LEN);
            snprintf($$, MAX_VAR_LEN, "%s", $1);
         }
         | LEQ {
            $$ = (char *) malloc(MAX_VAR_LEN);
            snprintf($$, MAX_VAR_LEN, "%s", $1);
         }
         | GEQ {
            $$ = (char *) malloc(MAX_VAR_LEN);
            snprintf($$, MAX_VAR_LEN, "%s", $1);
         }
         | OR {
            $$ = (char *) malloc(MAX_VAR_LEN);
            snprintf($$, MAX_VAR_LEN, "%s", $1);
         }
         | AND {
            $$ = (char *) malloc(MAX_VAR_LEN);
            snprintf($$, MAX_VAR_LEN, "%s", $1);
         }
         | LT {
            $$ = (char *) malloc(MAX_VAR_LEN);
            snprintf($$, MAX_VAR_LEN, "%s", $1);
         }
         | GT {
            $$ = (char *) malloc(MAX_VAR_LEN);
            snprintf($$, MAX_VAR_LEN, "%s", $1);
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
                    strncpy(allAssign[cntAssign].varName, $1, MAX_VAR_LEN);
                    strncpy(allAssign[cntAssign].scope, currentScope, MAX_SCOPE_LEN); 
                    if(parameter) {
                      allAssign[cntAssign].varType = extract_param_type(&allFunctions, $1, currentScope);
                    }
                    else {
                      allAssign[cntAssign].varType = extract_variable_type(&allVariables, $1, currentScope);
                    }
                    allAssign[cntAssign].Ast = $3;
                    cntAssign++;
                  }
               }
               ;

class_assignment : ID '.' ID '=' expression_value 
                 {
                    check_class_var(&allVariables, $3, $1, yylineno);
                    snprintf(allAssign[cntAssign].varName, MAX_VAR_LEN, "%s.%s", $1, $3);
                    strncpy(allAssign[cntAssign].scope, currentScope, MAX_SCOPE_LEN); 
                    allAssign[cntAssign].varType = extract_class_varType(&allVariables, $3, $1);
                    allAssign[cntAssign].Ast = $5;
                    cntAssign++;
                 }
                 ;

array_assignment : ID '[' C_INT ']' '=' expression_value
                 {
                    check_array_defined(&allVariables, $1, currentScope, $3, yylineno);
                    snprintf(allAssign[cntAssign].varName, MAX_VAR_LEN, "%s[%d]", $1, $3);
                    strncpy(allAssign[cntAssign].scope, currentScope, MAX_SCOPE_LEN); 
                    allAssign[cntAssign].varType = extract_variable_type(&allVariables, $1, currentScope);
                    allAssign[cntAssign].Ast = $6;
                    cntAssign++;
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
  allAssign = (AstList *) malloc(MAX_VAR_NUM * sizeof(AstList));

  strncpy(currentScope, "/", MAX_SCOPE_LEN);

  yyparse();

  /* for(int i = 0; i < cntAssign; ++i) {
    printf("The variable %s on scope %s with type %d has the following AST: \n", allAssign[i].varName, allAssign[i].scope, allAssign[i].varType);
    dfs(allAssign[i].Ast);
  } */

  create_symbol_table();
  create_function_table();

  printf("The number of functions is %d: \n", allFunctions.funcNumber);

  free(allAssign);
  clear_varList(&allVariables);
  clear_funcList(&allFunctions);
} 
