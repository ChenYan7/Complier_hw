%{
    #include "common.h"
    #define YYSTYPE TreeNode * 
    TreeNode* root;
    extern int lineno;
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
%token PRINTF SCANF QUOTE CONST
%token SEMICOLON COMMA LP RP LC RC WHILE ELSE IF RETURN FOR
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
: statements {root = new TreeNode(0, NODE_PROG); root->addChild($1);}
;

statements
:  statement {$$=$1;}
|  statements statement {$$=$1; $$->addSibling($2);}
;

statement
: SEMICOLON  {$$ = new TreeNode(lineno, NODE_STMT); $$->stype = STMT_SKIP;}
| declaration SEMICOLON {$$ = $1;}
| expr SEMICOLON { $$ = $1;}
| RETURN expr SEMICOLON {
    TreeNode* node = new TreeNode(lineno,NODE_STMT);
    node->stype = STMT_RETURN;
    node->addChild($2);
    $$ = node;
}
| if_else {$$ = $1;}
| while {$$ = $1;}
| for {$$ = $1;}
| scanf SEMICOLON {$$ = $1;}
| printf SEMICOLON {$$ = $1;}
| LC statements RC {$$ = $2;}
| func_statement {$$ = $1;}
;

func_statement
: T IDENTIFIER LP RP statement {
    TreeNode* node = new TreeNode($1->lineno,NODE_FUNC);
    node->addChild($1);
    node->addChild($2);
    node->addChild($5);
    $$ = node;
}



if_else
: IF LP expr RP statement %prec LOWER_THEN_ELSE {
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_IF;
    node->addChild($3);
    node->addChild($5);
    $$=node;
}
| IF LP expr RP statement ELSE statement {
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_IF;
    node->addChild($3);
    node->addChild($5);
    node->addChild($7);
    $$=node;
}
;

while
: WHILE LP expr RP statement {
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_WHILE;
    node->addChild($3);
    node->addChild($5);
    $$=node;
}
;

for
: FOR LP statement statement expr RP statement {
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild($3);
    node->addChild($4);
    node->addChild($5);
    node->addChild($7);
    $$ = node;
}

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
: T IDENTIFIER ASSIGN expr{  // declare and init
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    node->addChild($4);
    $$ = node;   
} 
| T id_list {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    $$ = node;   
}
| CONST T IDENTIFIER ASSIGN expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    node->addChild($4);
    $$ = node; 
}
;

id_list
: IDENTIFIER {$$=$1;}
| id_list COMMA IDENTIFIER{
    $$=$1;
    $$->addSibling($3);
}


expr
: IDENTIFIER {
    $$ = $1;
}
| QUOTE IDENTIFIER {$$=$2;}
| INTEGER {
    $$ = $1;
}
| CHAR {
    $$ = $1;
}
| STRING {
    $$ = $1;
}
| IDENTIFIER INC {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_INC;
    node->addChild($1);
    $$=node;
}
| IDENTIFIER DEC {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_DEC;
    node->addChild($1);
    $$=node;
}
| expr ASSIGN expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype=STMT_ASSIGN;
    node->optype=OP_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$=node;
}
| expr ADD_ASSIGN expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype=STMT_ASSIGN;
    node->optype=OP_ADD_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$=node;
}
| expr SUB_ASSIGN expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype=STMT_ASSIGN;
    node->optype=OP_SUB_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$=node;
}
| expr MUL_ASSIGN expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype=STMT_ASSIGN;
    node->optype=OP_MUL_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$=node;
}
| expr DIV_ASSIGN expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype=STMT_ASSIGN;
    node->optype=OP_DIV_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$=node;
}
| expr ADD expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_ADD;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr SUB expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_SUB;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr MUL expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_MUL;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr DIV expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_DIV;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr MODE expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_MODE;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| SUB expr %prec UMINUS {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_SUB;
    node->addChild($2);
    $$ = node;
}
| ADD expr %prec UADD {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_ADD;
    node->addChild($2);
    $$ = node;
}
| TRUE {$$=$1;}
| FALSE {$$=$1;}
| expr AND expr {
    TreeNode *node=new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_AND;
    node->addChild($1);
    node->addChild($3);
    $$=node;
} 
| expr OR expr {
    TreeNode *node=new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_OR;
    node->addChild($1);
    node->addChild($3);
    $$=node;
} 
| NOT expr {
    TreeNode *node=new TreeNode($2->lineno,NODE_EXPR);
    node->optype=OP_NOT;
    node->addChild($2);
    $$=node;        
}
| expr EQ expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_EQ;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr NEQ expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_NEQ;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr GQT expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_GQT;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr LQT expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_LQT;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr GT expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_GT;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr LT expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_LT;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
;


T: T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_INT;} 
| T_CHAR {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CHAR;}
| T_BOOL {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_BOOL;}
| T_STRING {$$ = new TreeNode(lineno,NODE_TYPE); $$->type = TYPE_STRING;}
| T_VOID {$$ = new TreeNode(lineno,NODE_TYPE); $$->type = TYPE_VOID;}
;

%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}