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
%token RELOP ADD SUB MUL DIV INC DEC 
%token AND OR NOT
%token PRINTF SCANF QUOTE
%token SEMICOLON COMMA LP RP LC RC WHILE ELSE IF RETURN FOR
%token IDENTIFIER INTEGER CHAR BOOL STRING

%right AND OR NOT
%left MUL DIV
%left ADD SUB
%left RELOP
%right ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN
%left LP RP
%nonassoc LOWER_THEN_ELSE
%nonassoc ELSE 

%%

program
: statements {root = new TreeNode(0, NODE_PROG); root->addChild($1);};

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
: T IDENTIFIER LP RP statement{
    TreeNode* node = new TreeNode($1->lineno,NODE_FUNC);
    node->addChild($1);
    node->addChild($2);
    node->addChild($5);
    $$ = node;
}


if_else
: IF bool_expr statement %prec LOWER_THEN_ELSE {
    TreeNode *node=new TreeNode($2->lineno,NODE_STMT);
    node->stype=STMT_IF;
    node->addChild($2);
    node->addChild($3);
    $$=node;
}
| IF LP bool_expr RP statement ELSE statement {
    TreeNode *node=new TreeNode($2->lineno,NODE_STMT);
    node->stype=STMT_IF;
    node->addChild($3);
    node->addChild($5);
    node->addChild($7);
    $$=node;
}
;

while
: WHILE bool_expr statement {
    TreeNode *node=new TreeNode($2->lineno,NODE_STMT);
    node->stype=STMT_WHILE;
    node->addChild($2);
    node->addChild($3);
    $$=node;
}
;

for
: FOR LP statement statement statement RP statement {
    TreeNode *node=new TreeNode($2->lineno,NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild($3);
    node->addChild($4);
    node->addChild($5);
    node->addChild($7);
    $$ = node;
}

printf
: PRINTF LP expr COMMA io_list RP {
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_PRINTF;
    node->addChild($3);
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
| SCANF LP expr COMMA io_list RP {
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_SCANF;
    node->addChild($3);
    node->addChild($5);
    $$=node;
}
;

io_list
: IDENTIFIER {$$=$1;}
| STRING {$$=$1;}
| INTEGER {$$=$1;}
| QUOTE CHAR {$$=$2;}

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
;

id_list
: IDENTIFIER {$$=$1;}
| IDENTIFIER COMMA id_list{
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->addChild($1);
    node->addChild($3);
    $$=node;
}

bool_expr
: TRUE {$$=$1;}
| FALSE {$$=$1;}
| expr {$$ = $1;}
| bool_expr AND bool_expr {
    TreeNode *node=new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_AND;
    node->addChild($1);
    node->addChild($3);
    $$=node;
} 
| bool_expr OR bool_expr {
    TreeNode *node=new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_OR;
    node->addChild($1);
    node->addChild($3);
    $$=node;
} 
| NOT bool_expr {
    TreeNode *node=new TreeNode($2->lineno,NODE_EXPR);
    node->optype=OP_NOT;
    node->addChild($2);
    $$=node;        
}
| bool_expr RELOP bool_expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype=OP_RELOP;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
;

expr
: IDENTIFIER {
    $$ = $1;
}
| INTEGER {
    $$ = $1;
}
| CHAR {
    $$ = $1;
}
| STRING {
    $$ = $1;
}
| expr ASSIGN expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype=STMT_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$=node;
}
| expr ADD_ASSIGN expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype=STMT_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$=node;
}
| expr SUB_ASSIGN expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype=STMT_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$=node;
}
| expr MUL_ASSIGN expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype=STMT_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$=node;
}
| expr DIV_ASSIGN expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype=STMT_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$=node;
}
| expr ADD expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr SUB expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr MUL expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr DIV expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| SUB expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->addChild($2);
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