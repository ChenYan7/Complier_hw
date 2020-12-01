%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header

int lineno=1;
int id_count=0;
string lasttoken;
int count_c=0;

struct List_Node{
public:
    string name;
    stack<char> s;
    int count = 0;
    int num = 0;
    int flag;
    struct List_Node* next=nullptr;
    List_Node(string name);
    void genCount();
    void IDcount();
};

List_Node* first=nullptr;
List_Node* tail=nullptr;
int Insert_undef_ID(string name);
int Insert_def_ID(string name);
void stack_add();
void stack_sub();

List_Node::List_Node(string name)
{
    this->name = name;
}

void List_Node::genCount()
{
    this->count += 1;
}

void List_Node::IDcount()
{
    this->num = id_count;
}

//若找到同名且stack为空的节点则为重复声明
int Insert_undef_ID(string name){
    if(first==nullptr)
    {
        List_Node* node = new List_Node(name);
        node->flag = 1;
        id_count += 1;
        node->IDcount();
        first = tail = node;
        first->genCount();
        return first->num;   //正常返回
    }
    else{
        List_Node* cur = first;
        while(cur)
        {
            if(cur->name==name && cur->s.empty() && cur->flag==1)
            {
                cout<<"line "<<lineno<<" error:"<<name<<"变量重复声明"<<endl;
                return -1;   //重复声明,报错
            }
            cur = cur->next;
        }
        //若不是在同一个作用域，则使用尾插法添加节点
        List_Node* node = new List_Node(name);
        node->flag = 1;
        id_count += 1;
        node->IDcount();
        tail->next = node;
        tail = node;
        tail->genCount();
        return tail->num;
    }
}

//找同名且stack最小的
int Insert_def_ID(string name)
{
    int min_count=100;
    if(first==nullptr)
    {
        cout<<"line "<<lineno<<" error:"<<name<<"变量未声明"<<endl;
        return -1;  //未声明变量
    }
    List_Node* cur = first;
    List_Node* node;
    while(cur)
    {
        if(cur->name==name && cur->flag==1 && (int)cur->s.size()<min_count)
        {
            node = cur;
            min_count = (int)cur->s.size();
        }
        cur = cur->next;
    }
    if(min_count!=100)
    {
        node->genCount();
        return node->num;
    }
    else{
        cout<<"line "<<lineno<<" error:"<<name<<"变量未声明"<<endl;
        return -1;  //未声明变量
    }
}

//遇到LC，所有ID的stack加上一个元素1
void stack_add()
{
    List_Node* cur = first;
    while(cur)
    {
        if(cur->flag==1)
            cur->s.push('L');
        cur = cur->next;
    }
}

//遇到RC，所有ID的stack pop掉一个元素，如果stack为空了，就释放掉节点
void stack_sub()
{
    List_Node* cur = first;
    while(cur)
    {
        if(!cur->s.empty())
        {
            cur->s.pop();
        }
        else cur->flag = 0;
        cur = cur->next;
    }
}

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
"return" return RETURN;

"const" return CONST;
"void" {lasttoken = yytext; return T_VOID;};
"int" { lasttoken = yytext; return T_INT;};
"bool" { lasttoken = yytext; return T_BOOL;};
"char" {lasttoken = yytext; return T_CHAR;};
"string" {lasttoken = yytext; return T_STRING;};

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
";" {lasttoken = " "; return SEMICOLON;};
"&" return QUOTE;

"++" return INC;
"--" return DEC;
"+" return ADD;
"-" return SUB;
"*" return MUL;
"/" return DIV;
"%" return MODE;
"(" return LP;
")" return RP;
"{" { lasttoken = " "; stack_add(); return LC;};
"}" {stack_sub();return RC;};

{INTEGER} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    node->int_val = atoi(yytext);
    yylval = node;
    return INTEGER;
}

{CHAR} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_CHAR;
    node->ch_val = yytext[1];
    yylval = node;
    return CHAR;
}

{STRING} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_STRING;
    node->str_val = yytext;
    yylval = node;
    return STRING;
}

{IDENTIFIER} {
    int x=0;
    if(lasttoken==" ")
    {
        x = Insert_def_ID(yytext);
        //cout<<yytext<<":"<<x<<endl;
    }
    else{
        x = Insert_undef_ID(yytext);
        //cout<<yytext<<":"<<x<<endl;
    }
    TreeNode* node = new TreeNode(lineno, NODE_VAR);
    node->var_name = string(yytext);
    yylval = node;
    return IDENTIFIER;
}

{WHILTESPACE} /* do nothing */

{EOL} {lineno++;}

. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%