%{
    #include "common.h"
    #define YYSTYPE TreeNode * 
    TreeNode* root;
    extern int lineno;
    layerNode* currentNode;
    layerNode* layer_root;
    int yylex();
    int yyerror( char const * );
%}
%start program

%token T_CHAR T_INT T_STRING T_BOOL T_VOID
%token TRUE FALSE
%token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN
%token EQ NEQ GQT LQT GT LT
%token ADD SUB MUL DIV MODE INC DEC 
%token AND OR NOT
%token PRINTF SCANF REFERENCE CONST
%token SEMICOLON COMMA LP RP LC RC WHILE ELSE IF RETURN FOR
%token CONTINUE BREAK
%token IDENTIFIER INTEGER CHAR BOOL STRING

%left COMMA
%right ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN
%left OR
%left AND
%left EQ NEQ
%left GT LT GQT LQT
%left ADD SUB
%left MUL DIV MODE
%right UMINUS UADD
%right INC DEC NOT
%left LP RP
%nonassoc LOWER_THEN_ELSE
%nonassoc ELSE 

%%

program
: statements {
    root = new TreeNode(0, NODE_PROG); 
    root->addChild($1);
    root->layer_node=currentNode;}
;

statements
:  statement {$$=$1;}
|  statements statement {$$=$1; $$->addSibling($2);}
;

statement
: SEMICOLON  {
    $$ = new TreeNode($1->lineno, NODE_STMT); 
    $$->stype = STMT_SKIP;
    $$->layer_node=currentNode;}
| declaration SEMICOLON {$$ = $1;}
| assignment_expr SEMICOLON{
    $$ = $1;
}
| if_else {$$ = $1;}
| iteration_Stmt{
    $$=$1;
}
| jump_Stmt {
    $$=$1;
}
| compound_Stmt {$$=$1;}
| printf SEMICOLON {$$=$1;}
| scanf SEMICOLON {$$=$1;}
| function_Definition{
    $$=$1;
}
| function_Call{
    $$=$1;
}
;

function_Call
: IDENTIFIER LP id_list RP{
    TreeNode* node = new TreeNode($1->lineno, NODE_FUNC_CALL); 
    node->layer_node=currentNode;
    node->func_info=new funcInfo;
    node->func_info->func_name=$1;
    node->func_info->arg_list=$3;
    node->addChild($1);
    node->addChild($3);
    setSymbolType(currentNode->section,$1,SYMBOL_FUNC);
    $$=node;
}
| IDENTIFIER LP RP {
    TreeNode* node = new TreeNode($1->lineno, NODE_FUNC_CALL); 
    node->layer_node=currentNode;
    node->func_info=new funcInfo;
    node->func_info->func_name=$1;
    node->addChild($3);
    setSymbolType(currentNode->section,$1,SYMBOL_FUNC);
    $$=node;
}
;

function_Definition
: T IDENTIFIER LP declaration RP compound_Stmt{
    TreeNode* node = new TreeNode($2->lineno, NODE_FUNC_DEF); 
    node->layer_node=currentNode;
    node->func_info=new funcInfo;
    node->func_info->return_value=$1;
    node->func_info->func_name=$2;
    node->func_info->decl_list=$4;
    node->func_info->func_body=$6;
    node->addChild($1);
    node->addChild($2);
    node->addChild($4);
    node->addChild($6);
    setProperty(currentNode->section,$2,PROPERTY_DEF);
    setSymbolType(currentNode->section,$2,SYMBOL_FUNC);
    $$=node;
}
| T IDENTIFIER LP RP compound_Stmt{
    TreeNode* node = new TreeNode($2->lineno, NODE_FUNC_DEF);
    node->layer_node=currentNode;
    node->func_info=new funcInfo;
    node->func_info->return_value=$1;
    node->func_info->func_name=$2;
    node->func_info->func_body=$5;
    node->addChild($1);
    node->addChild($2);
    node->addChild($5);
    setProperty(currentNode->section,$2,PROPERTY_DEF);
    setSymbolType(currentNode->section,$2,SYMBOL_FUNC);
    $$=node; 
}
;

compound_Stmt
: LC statements RC{
    TreeNode* node = new TreeNode($1->lineno, NODE_BLOCK); 
    node->layer_node=currentNode;
    node->change_field.accessTime=currentNode->accessTime-1;
    node->change_field.needChange=1;
    node->addChild($2);
    $$=node;
}
| LC RC{
    TreeNode* node = new TreeNode(lineno, NODE_BLOCK);
    node->layer_node=currentNode; 
    node->stype = STMT_SKIP;
    $$=node;
}
;

if_else
: IF LP expr RP compound_Stmt %prec LOWER_THEN_ELSE {
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_IF;
    node->addChild($3);
    node->addChild($5);
    node->layer_node=currentNode;
    node->change_field.accessTime=currentNode->accessTime-1;
    node->change_field.needChange=1;
    $$=node;
}
| IF LP expr RP compound_Stmt ELSE compound_Stmt {
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_IF;
    node->addChild($3);
    node->addChild($5);
    node->addChild($7);
    node->layer_node=currentNode;
    node->change_field.accessTime=currentNode->accessTime-1;
    node->change_field.needChange=1;
    $$=node;
}
;

iteration_Stmt
: WHILE LP expr RP compound_Stmt {
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_WHILE;
    node->addChild($3);
    node->addChild($5);
    node->layer_node=currentNode;
    node->change_field.accessTime=currentNode->accessTime-1;
    node->change_field.needChange=1;
    $$=node;
}
| FOR LP expr SEMICOLON expr SEMICOLON expr RP compound_Stmt {
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild($3);
    node->addChild($5);
    node->addChild($7);
    node->addChild($9);
    node->layer_node=currentNode;
    node->change_field.accessTime=currentNode->accessTime-1;
    node->change_field.needChange=1;
    $$ = node;
}
| FOR LP expr SEMICOLON expr SEMICOLON RP compound_Stmt {
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild($3);
    node->addChild($5);
    node->addChild($8);
    node->layer_node=currentNode;
    node->change_field.accessTime=currentNode->accessTime-1;
    node->change_field.needChange=1;
    $$ = node;
}
| FOR LP expr SEMICOLON SEMICOLON expr RP compound_Stmt {
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild($3);
    node->addChild($6);
    node->addChild($8);
    node->layer_node=currentNode;
    node->change_field.accessTime=currentNode->accessTime-1;
    node->change_field.needChange=1;
    $$ = node;
}
| FOR LP SEMICOLON expr SEMICOLON expr RP compound_Stmt {
    TreeNode *node=new TreeNode($1->lineno,NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild($4);
    node->addChild($6);
    node->addChild($8);
    node->layer_node=currentNode;
    node->change_field.accessTime=currentNode->accessTime-1;
    node->change_field.needChange=1;
    $$ = node;
}
| FOR LP expr SEMICOLON SEMICOLON RP compound_Stmt {
    TreeNode *node=new TreeNode($1->lineno,NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild($3);
    node->addChild($7);
    node->layer_node=currentNode;
    node->change_field.accessTime=currentNode->accessTime-1;
    node->change_field.needChange=1;
    $$ = node;
}
| FOR LP SEMICOLON SEMICOLON expr RP compound_Stmt {
    TreeNode *node=new TreeNode($1->lineno,NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild($5);
    node->addChild($7);
    node->layer_node=currentNode;
    node->change_field.accessTime=currentNode->accessTime-1;
    node->change_field.needChange=1;
    $$ = node;
}
| FOR LP SEMICOLON expr SEMICOLON RP compound_Stmt {
    TreeNode *node=new TreeNode($1->lineno,NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild($4);
    node->addChild($7);
    node->layer_node=currentNode;
    node->change_field.accessTime=currentNode->accessTime-1;
    node->change_field.needChange=1;
    $$ = node;
}
| FOR LP SEMICOLON SEMICOLON RP compound_Stmt {
    TreeNode *node=new TreeNode($1->lineno,NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild($6);
    node->layer_node=currentNode;
    node->change_field.accessTime=currentNode->accessTime-1;
    node->change_field.needChange=1;
    $$ = node;
}

jump_Stmt
: CONTINUE SEMICOLON{
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype=STMT_CONTINUE;
    node->layer_node=currentNode;
    $$=node;
}
| BREAK SEMICOLON{
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype=STMT_BREAK;
    node->layer_node=currentNode;
    $$=node;
}
| RETURN expr SEMICOLON{
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype=STMT_RETURN;
    node->layer_node=currentNode;
    node->addChild($2);
    $$=node;
}
| RETURN SEMICOLON{
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype=STMT_RETURN;
    node->layer_node=currentNode;
    $$=node;
}
;

printf
: PRINTF LP expr RP {
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_PRINTF;
    node->addChild($3);
    $$=node;
}
| PRINTF LP STRING COMMA io_list RP {
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_PRINTF;
    node->addChild($3);
    string str = $3->str_val;
    char t[10];
    int i = 0;
    int num = 0;
    while(i<(int)str.length())
    {
        if(str[i]=='%')
        {
            if(str[i+1]=='d' || str[i+1]=='s')
            {
                t[num] = str[i+1];
                num++;
            }
        }
        i++;
    }
    i = 0;
    while(i<num)
    {
        TreeNode* node_c = new TreeNode(lineno, NODE_CONST);
        node_c->type = TYPE_CHAR;
        node_c->ch_val = t[i];
        node->addChild(node_c);
        i++;
    }
    node->addChild($5);
    $$=node;
}
;

scanf
: SCANF LP expr RP {
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_SCANF;
    node->addChild($3);
    $$=node;
}
| SCANF LP STRING COMMA io_list RP {
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_SCANF;
    node->addChild($3);
    string str = $3->str_val;
    char t[10];
    int i = 0;
    int num = 0;
    while(i<(int)str.length())
    {
        if(str[i]=='%')
        {
            if(str[i+1]=='d' || str[i+1]=='s')
            {
                t[num] = str[i+1];
                num++;
            }
        }
        i++;
    }
    i = 0;
    while(i<num)
    {
        TreeNode* node_c = new TreeNode(lineno, NODE_CONST);
        node_c->type = TYPE_CHAR;
        node_c->ch_val = t[i];
        node->addChild(node_c);
        i++;
    }
    node->addChild($5);
    $$=node;
}
;

io_list
: expr {$$=$1;}
| io_list COMMA expr {
    $$ = $1;
    $$->addSibling($3);
}
;

declaration
: T IDENTIFIER ASSIGN additive_expr{  // declare and init
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    node->addChild($4);
    node->layer_node=currentNode;
    setProperty(currentNode->section,$2,PROPERTY_DEF);
    $$ = node;   
} 
| T id_list {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    node->layer_node=currentNode;
    //setProperty(currentNode->section,$2,PROPERTY_DEF);
    $$ = node;   
}
;

id_list
: IDENTIFIER {$$=$1;setProperty(currentNode->section,$1,PROPERTY_DEF);}
| id_list COMMA IDENTIFIER{
    $$=$1;
    $$->addSibling($3);
    $$->layer_node=currentNode;
    setProperty(currentNode->section,$3,PROPERTY_DEF);
}

expr
: condition_expr {$$=$1;} //条件表达式
| assignment_expr {$$=$1;} //赋值表达式
| declaration {$$=$1;} //声明表达式
;

condition_expr
: logical_or_expr{
    $$=$1;
}
;

logical_or_expr
: logical_and_expr{
    $$=$1;
}
| logical_or_expr OR logical_and_expr{
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_OR;
    node->addChild($1);
    node->addChild($3);
    node->layer_node=currentNode;
    $$ = node;
}
;

logical_and_expr
: equality_expr{
    $$=$1;
}
| logical_and_expr AND equality_expr{
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR );
    node->optype=OP_AND;
    node->addChild($1);
    node->addChild($3);
    node->layer_node=currentNode;
    $$ = node;
}
;

equality_expr
: relation_expr{
    $$=$1;
}
| equality_expr EQ relation_expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_EQ;
    node->addChild($1);
    node->addChild($3);
    node->layer_node=currentNode;
    $$ = node;
}
| equality_expr NEQ relation_expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR );
    node->optype=OP_NEQ;
    node->addChild($1);
    node->addChild($3);
    node->layer_node=currentNode;
    $$ = node;
}
;

relation_expr
: additive_expr{
    $$=$1;
}
| relation_expr LT additive_expr{
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR );
    node->optype=OP_LT;
    node->addChild($1);
    node->addChild($3);
    node->layer_node=currentNode;
    $$ = node;
}
| relation_expr LQT additive_expr{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype=OP_LQT;
    node->addChild($1);
    node->addChild($3);
    node->layer_node=currentNode;
    $$ = node;
}
| relation_expr GT additive_expr{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype=OP_GT;
    node->addChild($1);
    node->addChild($3);
    node->layer_node=currentNode;
    $$ = node;
}
| relation_expr GQT additive_expr{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype=OP_GQT;
    node->addChild($1);
    node->addChild($3);
    node->layer_node=currentNode;
    $$ = node;
}
;

assignment_expr
: unary_expr ASSIGN additive_expr{//有可能需要函数如 a=func()
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype=OP_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    node->layer_node=currentNode;
    $$ = node;
}
| unary_expr ADD_ASSIGN additive_expr{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype=OP_ADD_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    node->layer_node=currentNode;
    $$ = node;
}
| unary_expr SUB_ASSIGN additive_expr{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype=OP_SUB_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    node->layer_node=currentNode;
    $$ = node;
}
| unary_expr MUL_ASSIGN additive_expr{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype=OP_MUL_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    node->layer_node=currentNode;
    $$ = node;
}
| unary_expr DIV_ASSIGN additive_expr{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype=OP_DIV_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    node->layer_node=currentNode;
    $$ = node;
}
;

additive_expr
: mult_expr{
    $$=$1;
}
| additive_expr ADD mult_expr{
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_ADD;
    node->addChild($1);
    node->addChild($3);
    node->layer_node=currentNode;
    $$ = node;
}
| additive_expr SUB mult_expr{
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_SUB;
    node->addChild($1);
    node->addChild($3);
    node->layer_node=currentNode;
    $$ = node;
}
;

mult_expr
: cast_expr{
    $$=$1;
}
| mult_expr MUL cast_expr{
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_MUL;
    node->addChild($1);
    node->addChild($3);
    node->layer_node=currentNode;
    $$ = node;
}
| mult_expr DIV cast_expr{
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_DIV;
    node->addChild($1);
    node->addChild($3);
    node->layer_node=currentNode;
    $$ = node;
}
| mult_expr MODE cast_expr{
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_MODE;
    node->addChild($1);
    node->addChild($3);
    node->layer_node=currentNode;
    $$ = node;
}
;

cast_expr
: unary_expr{
    $$=$1;
}

unary_expr
: postfix_expr{
    $$=$1;//增加这一层是为了方便以后扩充
}
| SUB cast_expr{
    TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_SUB;
    node->addChild($2);
    node->layer_node=currentNode;
    $$=node;
}
| NOT cast_expr{
    TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_NOT;
    node->addChild($2);
    node->layer_node=currentNode;
    $$=node;
}
| REFERENCE cast_expr{
    TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_REF;
    node->addChild($2);
    node->layer_node=currentNode;
    $$=node;
}
;

postfix_expr
: primary_expr{
    $$=$1;
}
| postfix_expr INC{
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_INC;
    node->addChild($1);
    node->layer_node=currentNode;
    $$=node;
}
| postfix_expr DEC{
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_DEC;
    node->addChild($2);
    node->layer_node=currentNode;
    $$=node;
}
;

primary_expr
: IDENTIFIER {
    $$ = $1;
}
| paperConst{
    $$=$1;
}
| LP expr RP{
    $$=$2;
}
;

paperConst
: INTEGER {
    $$ = $1;

}
| CHAR {
    $$ = $1;

}
| STRING {
    $$ = $1;

}
| BOOL {
    $$=$1;

}
;


T: T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_INT;$$->layer_node=currentNode;} 
| T_CHAR {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CHAR;$$->layer_node=currentNode;}
| T_BOOL {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_BOOL;$$->layer_node=currentNode;}
| T_STRING {$$ = new TreeNode(lineno,NODE_TYPE); $$->type = TYPE_STRING;$$->layer_node=currentNode;}
| T_VOID {$$ = new TreeNode(lineno,NODE_TYPE); $$->type = TYPE_VOID;$$->layer_node=currentNode;}
;

%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}