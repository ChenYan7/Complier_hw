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
%token ASSIGN RELOP ADD SUB MUL DIV
%token PRINTF SCANF
%token SEMICOLON LP RP LC RC WHILE ELSE IF RETURN FOR
%token IDENTIFIER INTEGER CHAR BOOL STRING

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
| expr SEMICOLON { $$ = $1;}
| RETURN expr SEMICOLON {
    TreeNode* node = new TreeNode(lineno,NODE_STMT);
    node->stype = STMT_RETURN;
    node->addChild($2);
    $$ = node;
}
| LC statements RC {$$ = $2;}
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
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr RELOP expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->addChild($1);
    node->addChild($3);
    $$ = node;
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