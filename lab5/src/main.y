%{
    #include "common.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    int yylex();
    int yyerror( char const * );
%}
%start program

%token T_CHAR T_INT T_STRING T_BOOL 
%token TRUE FALSE
%token ASSIGN RELOP ADD SUB MUL DIV NOT
%token PRINTF SCANF
%token SEMICOLON LP RP LC RC WHILE ELSE IF RETURN FOR
%token IDENTIFIER INTEGER CHAR BOOL STRING

%right NOT
%left MUL DIV
%left ADD SUB
%left RELOP
%right ASSIGN
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
| assign SEMICOLON {$$ = $1;}
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
;

assign
: expr ASSIGN expr {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype=STMT_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$=node;
}

if_else
: IF bool_statment statement %prec LOWER_THEN_ELSE {
    TreeNode *node=new TreeNode($2->lineno,NODE_STMT);
    node->stype=STMT_IF;
    node->addChild($2);
    node->addChild($3);
    $$=node;
}
| IF bool_statment statement ELSE statement {
    TreeNode *node=new TreeNode($2->lineno,NODE_STMT);
    node->stype=STMT_IF;
    node->addChild($2);
    node->addChild($3);
    node->addChild($5);
    $$=node;
}
;

bool_statment
: LP bool_expr RP {$$=$2;};

while
: WHILE bool_statment statement {
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
: PRINTF LP expr RP {
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_PRINTF;
    node->addChild($3);
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
| T IDENTIFIER {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    $$ = node;   
}
;

bool_expr
: TRUE {$$=$1;}
| FALSE {$$=$1;}
| expr RELOP expr {
    TreeNode *node=new TreeNode($1->lineno,NODE_EXPR);
    //node->opType=OP_EQUAL;
    node->addChild($1);
    node->addChild($3);
    $$=node;
}
| NOT bool_expr {
    TreeNode *node=new TreeNode($2->lineno,NODE_EXPR);
    //node->opType=OP_NOT;
    node->addChild($2);
    $$=node;        
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
;

%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}