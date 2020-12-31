%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header

int lineno=1;
int count_c=0;

extern layerNode* currentNode;
extern layerNode* layer_root;
extern layerNode* makeNode(layerNode* node);
extern int assignRefSymbolType(layerNode*node,Item*);
%}

commentbegin "/*"
commentelement .|\n
commentend "*/"

LINECOMMENT \/\/[^\n]*
EOL	(\r\n|\r|\n)
WHILTESPACE [[:blank:]]


INTEGER [0-9]+
CHAR \'.?\'
STRING \".+\"

IDENTIFIER [[:alpha:]_][[:alpha:][:digit:]_]*

%x COMMENT
%%

{commentbegin} { count_c++; BEGIN COMMENT;}
<COMMENT>{commentbegin} { count_c++; }
<COMMENT>{commentend} {count_c--; if(count_c<=0) BEGIN INITIAL;}
<COMMENT>{EOL} {lineno++;}
<COMMENT>{commentelement} {}

{LINECOMMENT} {lineno++;}

"true" {
    TreeNode *node = new TreeNode(lineno,NODE_CONST);
    node->b_val = true;
    yylval = node;
    return TRUE;
}
"false" {
    TreeNode *node = new TreeNode(lineno,NODE_CONST);
    node->b_val = false;
    yylval = node;
    return FALSE;
}

"while" return WHILE;
"if" return IF;
"else" return ELSE;
"for" return FOR;

"continue" return CONTINUE;
"break" return BREAK;
"return" return RETURN;

"const" return CONST;
"void" return T_VOID;
"int" return T_INT;
"bool" return T_BOOL;
"char" return T_CHAR;
"string" return T_STRING;

"printf" return PRINTF;
"scanf" return SCANF;

"=" return ASSIGN;
"+=" return ADD_ASSIGN;
"-=" return SUB_ASSIGN;
"*=" return MUL_ASSIGN;
"/=" return DIV_ASSIGN;

"==" return EQ;
"!=" return NEQ;
">=" return GQT;
"<=" return LQT;
">" return GT;
"<" return LT;

"&&" return AND;
"||" return OR;
"!" return NOT;

"," return COMMA;
";" return SEMICOLON;
"&" return REFERENCE;

"++" return INC;
"--" return DEC;
"+" return ADD;
"-" return SUB;
"*" return MUL;
"/" return DIV;
"%" return MODE;
"(" return LP;
")" return RP;
"{" {currentNode=makeNode(currentNode);
    return LC;}
"}" {currentNode=currentNode->prev;
    currentNode->accessTime++;
    return RC;}

{INTEGER} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    node->int_val = atoi(yytext);
    node->layer_node=currentNode;
    yylval = node;
    return INTEGER;
}

{CHAR} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_CHAR;
    node->ch_val = yytext[1];
    node->layer_node=currentNode;
    yylval = node;
    return CHAR;
}

{STRING} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_STRING;
    node->str_val = yytext;
    node->layer_node=currentNode;
    yylval = node;
    return STRING;
}

{IDENTIFIER} {
    if(string(yytext)=="main"){
        TreeNode* node = new TreeNode(lineno, NODE_VAR);
        node->var_name = string(yytext);
        yylval = node;
        return IDENTIFIER;
    }
    TreeNode* node = new TreeNode(lineno, NODE_VAR);
    node->var_name = string(yytext);
    node->type=TYPE_VOID;//先定义为空类型
    node->layer_node=currentNode;
    yylval = node;
    Item* item=new Item;
    item->name=node->var_name;
    item->symbol_type=SYMBOL_VAR;
    item->symbol_property=PROPERTY_REFE;
    item->tree_node=node;
    item->def_pos = node;//先假设为自己
    currentNode->section->section_table.push_back(item);
    assignRefSymbolType(currentNode,item);
    return IDENTIFIER;
}

{WHILTESPACE} /* do nothing */

{EOL} {lineno++;}

. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%