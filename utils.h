#ifndef utils
#define utils

char *concatenate_and_free(char *s1, char *s2) {
    char *result;
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if (result == NULL) {
        printf("Error allocating memory!\n");
        return NULL;
    }

    strcpy(result, s1);
    strcat(result, s2);

    free(s1);
    free(s2);

    return result;
}
char * final_result;
struct AstNode *init_Ast(short _nodeType, short _dataType, char *_value) 
{
    struct AstNode *Ast = (struct AstNode *) malloc(sizeof(struct AstNode));
    Ast->left = Ast->right = NULL;
    Ast->nodeInfo.nodeType = _nodeType;
    Ast->nodeInfo.dataType = _dataType;
    strncpy(Ast->nodeInfo.value, _value, MAX_VAR_LEN);
    return Ast;
}

struct AstNode *build_Ast(char *_value, struct AstNode *_left, struct AstNode *_right, int _nodeType) 
{
    struct AstNode *Ast = (struct AstNode *) malloc(sizeof(struct AstNode));
    Ast->left = _left;
    Ast->right = _right;
    Ast->nodeInfo.nodeType = _nodeType;
    Ast->nodeInfo.dataType = 6;
    strncpy(Ast->nodeInfo.value, _value, MAX_VAR_LEN); 
    return Ast; 
}

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
        return;
    }
    
    strncpy(varTable->variables[varNum].name, newVar->name, MAX_VAR_LEN);
    strncpy(varTable->variables[varNum].scope, newVar->scope, MAX_SCOPE_LEN);
    strncpy(varTable->variables[varNum].value, newVar->value, MAX_ARRAY_LEN);
    
    varTable->variables[varNum].line = newVar->line;
    varTable->variables[varNum].typeInfo.typeName = newVar->typeInfo.typeName;
    varTable->variables[varNum].typeInfo.isConst = newVar->typeInfo.isConst;
    varTable->variables[varNum].typeInfo.isArray = newVar->typeInfo.isArray;

    int arrayLen = newVar->typeInfo.arrayLen;

    if(arrayLen >= MAX_ARRAY_LEN) {
        printf("Array length limit is excedeed!");
        return;
    }

    varTable->variables[varNum].typeInfo.arrayLen = arrayLen;      
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
    if(!isClass) {
        snprintf(addPath, MAX_SCOPE_LEN, "%s/", add);
    }
    else {
        snprintf(addPath, MAX_SCOPE_LEN, "&%s/", add);
    }
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
        if(allVariables.variables[i].typeInfo.isArray || (strcmp(allVariables.variables[i].scope, "/") && strcmp(allVariables.variables[i].scope, "/~/") || 
            allVariables.variables[i].typeInfo.typeName != 0)) {
            // if it's an array or not global / declared in main don't show the value or if its not int 
            fprintf(F, "Scope: %s\n", allVariables.variables[i].scope);
        }   
        else {
            fprintf(F, "Scope: %s, ", allVariables.variables[i].scope);
            if(!allVariables.variables[i].typeInfo.isArray) {
                fprintf(F, "Value: %d\n", allVariables.variables[i].value[0]);
            } 
        }  
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
    }
}

short check_func_already(FunctionList *funcTable, char *funcName, VariableList *parameters, int line) {
    int funcNum = funcTable->funcNumber;
    for(int i = 0; i < funcNum; ++i) {
        if(!strncmp(funcTable->functions[i].name, funcName, MAX_VAR_LEN)) {
            // verificam si parametrii
            short sameSignature = 1;
            VariableList *old_params = &funcTable->functions[i].parameters;
            if(parameters->varNumber != old_params->varNumber) {
                sameSignature = 0;
            }
            else {
                short same_params = 1;
                for(int j = 0; j < old_params->varNumber; ++j) {
                    if(parameters->variables[j].typeInfo.typeName != old_params->variables[j].typeInfo.typeName) {
                        same_params = 0;
                        break;
                    }
                }
                if(!same_params)
                    sameSignature = 0;
            }
            if(sameSignature) {
                printf("Function %s redefined on line %d. There is another function on line %d.\n", funcName, line, funcTable->functions[i].line);
                return -1;
            }
        }
    }
    return 0;
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
        if(!strcmp(name, varTable->variables[i].name) && strstr(scope, varTable->variables[i].scope)) {
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
    printf("Current node. Value: %s. NodeType: %d. DataType: %d\n", nod->nodeInfo.value, nod->nodeInfo.nodeType, nod->nodeInfo.dataType);
    if(nod->left) {
        printf("Left son: %s\n", nod->left->nodeInfo.value);
        dfs(nod->left);
    }
    printf("Back at %s\n", nod->nodeInfo.value);
    if(nod->right) {
        printf("Right son: %s\n", nod->right->nodeInfo.value);
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

int min(int a, int b) {
    if(a < b) {
        return a;
    }
    return b;
}

void extract_AstTypes(struct AstNode *nod) 
{
    /*
        this function inserts into the astTypes every Operand dataType
        this array will be checked later in the code for 3(c)
    */
    if(nod->nodeInfo.nodeType != 0) {
        // not an operation 
        astTypes[astTypesLen++] = nod->nodeInfo.dataType;  
    }
    if(nod->left) {
       extract_AstTypes(nod->left);
    }
    if(nod->right) {
        extract_AstTypes(nod->right);
    }
}

short check_AstTypes(struct AstNode *Ast, int line) 
{
    // returns the main type of the expression if found or -1 if it is ambiguous
    astTypesLen = 0;
    extract_AstTypes(Ast);

    short precTypes[MAX_EXP_LEN];
    int precLen = 0;
    // in precTypes we put all the distinct dataTypes from the expression
    
    for(int i = 0; i < astTypesLen; ++i) {
        short found = 0;
        if(astTypes[i] == -1) {
            return -1;
        }
        for(int j = 0; j < precLen; ++j) {
            if(astTypes[i] == precTypes[j]) {
                found = 1;
                break;
            }
        }
        if(!found) {
            precTypes[precLen++] = astTypes[i];
        }
    }

    if(precLen == 1) {
        return precTypes[0];
    }

    printf("The expression from line %d has operands with different types.\n", line);
    printf("    Following types of operands are used in this expression: ");
    for(int i = 0; i < precLen; ++i) {
        if(precTypes[i] < 0) {
            continue;
        }
        printf("%s", decodeType[precTypes[i]]);
        if(i < precLen - 1) {
            printf(", ");
        }
        else {
            printf("\n");
        }
    }
    return -1;
}

int nr_slashes(char *scope) {
    int i = 0, slashes = 0;
    while(*(scope + i) != '\0') {
        if(*(scope + i) == '/') {
            slashes++;
        }
        i++;
    }
    return slashes;
}

int extract_variable_value(VariableList *varTable, char *name, char *scope) {
    int varNum = varTable->varNumber, deepestScope = 0, pos = -1;
    for(int i = 0; i < varNum; ++i) {
        if(!strcmp(name, varTable->variables[i].name) && strstr(scope, varTable->variables[i].scope)) {
            int scopeLen = nr_slashes(varTable->variables[i].scope);
            if(deepestScope < scopeLen) {
                deepestScope = scopeLen;
                pos = i;
            }
        }
    }
    if(pos == -1) {
        // this shouldn't happen tho
        return 0;
    }
    return varTable->variables[pos].value[0];
}

short extract_arrayElement_value(VariableList *varTable, char *name, int index, char *scope)
{
    int varNum = varTable->varNumber, deepestScope = 0, pos = -1;
    for(int i = 0; i < varNum; ++i) {
        if(!strcmp(name, varTable->variables[i].name) && strstr(scope, varTable->variables[i].scope) && varTable->variables[i].typeInfo.isArray) {
            int scopeLen = nr_slashes(varTable->variables[i].scope);
            if(deepestScope < scopeLen) {
                deepestScope = scopeLen;
                pos = i;
            }
        }
    }
    if(pos == -1 && index >= varTable->variables[pos].typeInfo.arrayLen) {
        // this shouldn't happen tho
        return 0;
    }
    return varTable->variables[pos].value[index];
}

short extract_classVar_value(VariableList *varTable, char *varName, char *objName, char *scope) 
{
    char pattern[MAX_VAR_LEN];
    snprintf(pattern, MAX_VAR_LEN, "&%s/", objName);
    int varNum = varTable->varNumber;

    for(int i = 0; i < varNum; ++i) {
        if(!strcmp(varName, varTable->variables[i].name) && endWith(varTable->variables[i].scope, pattern)) {
            return varTable->variables[i].value[0];          
        }
    }
    // shouldn't happen tho
    return 0;
}

void update_variable_value(VariableList *varTable, char *name, char *scope, int newVal) {
    int varNum = varTable->varNumber, deepestScope = 0, pos = -1;
    for(int i = 0; i < varNum; ++i) {
        if(!strcmp(name, varTable->variables[i].name) && strstr(scope, varTable->variables[i].scope)) {
            int scopeLen = nr_slashes(varTable->variables[i].scope);
            if(deepestScope < scopeLen) {
                deepestScope = scopeLen;
                pos = i;
            }
        }
    }
    if(pos < 0) {
        // this shouldn't happen tho
        return;
    }
    varTable->variables[pos].value[0] = newVal;
}

void update_arrayElement_value(VariableList *varTable, char *name, int index, char *scope, int newVal)
{
    int varNum = varTable->varNumber, deepestScope = 0, pos = -1;
    for(int i = 0; i < varNum; ++i) {
        if(!strcmp(name, varTable->variables[i].name) && strstr(scope, varTable->variables[i].scope) && varTable->variables[i].typeInfo.isArray) {
            int scopeLen = nr_slashes(varTable->variables[i].scope);
            if(deepestScope < scopeLen) {
                deepestScope = scopeLen;
                pos = i;
            }
        }
    }
    if(pos == -1 && index >= varTable->variables[pos].typeInfo.arrayLen) {
        // this shouldn't happen tho
        return;
    }
    varTable->variables[pos].value[index] = newVal;
}

void update_classVar_value(VariableList *varTable, char *varName, char *objName, char *scope, int newVal) 
{
    char pattern[MAX_VAR_LEN];
    snprintf(pattern, MAX_VAR_LEN, "&%s/", objName);
    int varNum = varTable->varNumber;

    for(int i = 0; i < varNum; ++i) {
        if(!strcmp(varName, varTable->variables[i].name) && endWith(varTable->variables[i].scope, pattern)) {
            varTable->variables[i].value[0] = newVal;        
            return;  
        }
    }
    // shouldn't happen tho
    return;
}


void update_var(char *name, char *scope, int newVal) 
{
    short isArray = (strchr(name, '[') != 0);
    short isObj = (strchr(name, '.') != 0);
    if(!isArray && !isObj) {
        update_variable_value(&allVariables, name, scope, newVal);
    }
    if(isArray) {
        // I know fo sho it's an array
        char arrName[MAX_VAR_LEN];
        int index;
        sscanf(name, "%[^[][%d]", arrName, &index);
        update_arrayElement_value(&allVariables, arrName, index, scope, newVal);
    }
    if(isObj) {
        // I know fo sho it's an object
        char objName[MAX_VAR_LEN], varName[MAX_VAR_LEN];
        sscanf(name, "%[^'.'].%s", objName, varName);
        update_classVar_value(&allVariables, varName, objName, scope, newVal);
    }
}

int computeAst(struct AstNode *nod, char *scope, int line)
{
    printf("%s\n", nod->nodeInfo.value);
    
    if(!nod) {
        // just in case but in shouldn't happen
        return 0;
    }

    if(nod->nodeInfo.nodeType != 0) {
        if(nod->nodeInfo.nodeType == 2 && !nod->nodeInfo.dataType) {
            // we are on a leaf with an int number
            return atoi(nod->nodeInfo.value);
        }
        if(nod->nodeInfo.nodeType == 1 && !nod->nodeInfo.dataType) {
            // we are on a leag with an identifier, array element, or class element 
            short isArray = (strchr(nod->nodeInfo.value, '[') != NULL);
            short isObj = (strchr(nod->nodeInfo.value, '.') != NULL);
            if(!isArray && !isObj) {
                return extract_variable_value(&allVariables, nod->nodeInfo.value, scope);
            }
            if(isArray) {
                // I know fo sho it's an array
                char arrName[MAX_VAR_LEN];
                int index;
                sscanf(nod->nodeInfo.value, "%[^[][%d]", arrName, &index);
                return extract_arrayElement_value(&allVariables, arrName, index, scope);
            }
            if(isObj) {
                // I know fo sho it's an object
                char objName[MAX_VAR_LEN], varName[MAX_VAR_LEN];
                sscanf(nod->nodeInfo.value, "%[^'.'].%s", objName, varName);
                return extract_classVar_value(&allVariables, varName, objName, scope);
            }
        }
        // in any other case, we should return 0
        return 0;
    }
    // I'm on a node with an operation
    char *op = nod->nodeInfo.value;
    if(!strcmp(op, "+")) {
        return computeAst(nod->left, scope, line) + computeAst(nod->right, scope, line);
    }
    if(!strcmp(op, "-")) {
        return computeAst(nod->left, scope, line) - computeAst(nod->right, scope, line);
    }
    if(!strcmp(op, "*")) {
        return computeAst(nod->left, scope, line) * computeAst(nod->right, scope, line);
    }
    if(!strcmp(op, "/")) {
        int right = computeAst(nod->right, scope, line);
        if(right == 0) {
            printf("Division by 0 on line %d\n", line);
            return 0;
        }
        return computeAst(nod->left, scope, line) / computeAst(nod->right, scope, line);
    }
    if(!strcmp(op, "==")) {
        return computeAst(nod->left, scope, line) == computeAst(nod->right, scope, line);
    }
    if(!strcmp(op, "<>")) {
        return computeAst(nod->left, scope, line) != computeAst(nod->right, scope, line);
    }
    if(!strcmp(op, "<")) {
        return computeAst(nod->left, scope, line) < computeAst(nod->right, scope, line);
    }
    if(!strcmp(op, "<=")) {
        return computeAst(nod->left, scope, line) <= computeAst(nod->right, scope, line);
    }
    if(!strcmp(op, ">=")) {
        return computeAst(nod->left, scope, line) >= computeAst(nod->right, scope, line);
    }
    if(!strcmp(op, ">")) {
        return computeAst(nod->left, scope, line) > computeAst(nod->right, scope, line);
    }
    if(!strcmp(op, "||")) {
        return computeAst(nod->left, scope, line) || computeAst(nod->right, scope, line);
    }
    if(!strcmp(op, "&&")) {
        return computeAst(nod->left, scope, line) && computeAst(nod->right, scope, line);
    }
}

void check_and_update_variable(char *varName, int varType, char *scope, struct AstNode *Ast, int line) 
{
    int expType = check_AstTypes(Ast, line);

    if(expType == -1) {
        return;
    }

    if(varType != expType) {
        printf("The left side of the assignment on line %d has a different type than the right side!\n", line);
        printf("    The type of left side is '%s' while the type of right side is '%s'\n", decodeType[varType], decodeType[expType]);
        return;
    }

    int astResult = computeAst(Ast, scope, line);
    update_var(varName, scope, astResult);
}

void do_var_assign(char *varName, char *scope, struct AstNode* Ast, int line, short paramFlag) 
{
    int varType;

    if(paramFlag) {
        varType = extract_param_type(&allFunctions, varName, scope);
    }
    else { 
        varType = extract_variable_type(&allVariables, varName, scope);
    }

    check_and_update_variable(varName, varType, scope, Ast, line);
}

void do_declVar_assign(char *varName, char *scope, struct AstNode *Ast, int line, short dataType)
{
    check_and_update_variable(varName, dataType, scope, Ast, line);
}

void do_classVar_assign(char *varName, char *obj, char *scope, struct AstNode* Ast, int line) 
{
    char actualName[MAX_VAR_LEN];
    snprintf(actualName, MAX_VAR_LEN, "%s.%s", obj, varName);
    int varType = extract_class_varType(&allVariables, varName, obj);
    
    check_and_update_variable(actualName, varType, scope, Ast, line);
}

void do_arrayElem_assign(char *varName, int index, char *scope, struct AstNode* Ast, int line) 
{
    char actualName[MAX_VAR_LEN];
    snprintf(actualName, MAX_VAR_LEN, "%s[%d]", varName, index);
    int varType = extract_variable_type(&allVariables, varName, currentScope);
    
    check_and_update_variable(actualName, varType, scope, Ast, line);
}

void check_func_arguments(FunctionList *funcTable, char *funcName, int *arg_types, int argNr, int line) 
{
    int funcNum = funcTable->funcNumber;
    
    int pos = -1;
    for(int i = 0; i < funcNum; ++i) {
        if(!strcmp(funcName, funcTable->functions[i].name)) {
            pos = i;
        }
    }
    if(pos == -1) {
        return;
    }  

    int paramNr = funcTable->functions[pos].parameters.varNumber;
    if(argNr != paramNr) {
        printf("Incorrect function call at line %d.\n", line);
        printf("    The function %s has %d parameters, while %d arguments has been passed.\n", funcName, paramNr, argNr);
        return;
    }

    // arg number match the paramNumber ==> paramNr == argNrs
    VariableList *parameters = &funcTable->functions[pos].parameters;
    short typeMatch = 1;
    for(int i = 0; i < paramNr; ++i) {
        if(parameters->variables[i].typeInfo.typeName != arg_types[i] && arg_types[i] != -1) {
            // if it's -1 then it was already broken so another error will appear on the screen
            typeMatch = 0;
        }
    }
    
    if(typeMatch) {
        // all good -> number matched and types matched 
        return;
    }

    printf("Incorrect function %s call at line %d. The types of the following arguments and parameters doesn't match:\n", funcName, line);
    for(int i = 0; i < paramNr; ++i) {
        if(parameters->variables[i].typeInfo.typeName != arg_types[i] && arg_types[i] != -1) {
            printf("    Argument %d is having the type '%s', while type '%s' is expected.\n", 
                        i + 1, decodeType[arg_types[i]], decodeType[parameters->variables[i].typeInfo.typeName]);
        }
    }
}

#endif