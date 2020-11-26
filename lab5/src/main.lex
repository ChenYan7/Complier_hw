%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header
int lineno=1;
string lasttoken;

struct List_Node{
    string name;
    stack<int> s;
    int count = 0;
    struct List_Node* next=nullptr;
    List_Node(string name);
    void genCount();
};

List_Node* first=nullptr;
void Insert_undef_ID(string name);
void Insert_def_ID(string name);
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

//若找到同名且stack为空的节点则为重复声明
void Insert_undef_ID(string name){
    if(first==nullptr)
    {
        List_Node* node = new List_Node(name);
        first = node;
        first->genCount();
        return;   //正常返回
    }
    List_Node* cur = first;
    while(cur)
    {
        if(cur->name==name && cur->s.empty())
        {
            cout<<"error：重复声明"<<endl;
            return;   //重复声明,报错
        }
        cur = cur->next;
    }
    //若不是在同一个作用域，则使用头插法添加节点
    List_Node* node = new List_Node(name);
    node->next = first;
    node->genCount();
    first = node;
    return;
}

//找同名且stack最小的
void Insert_def_ID(string name)
{
    int min_count=100;
    if(first==nullptr)
    {
        cout<<"error:变量未声明"<<endl;
        return;  //未声明变量
    }
    List_Node* cur = first;
    List_Node* node;
    while(cur)
    {
        if(cur->name==name && cur->s.size()<min_count)
        {
            node = cur;
            min_count = cur->s.size();
        }
        cur = cur->next;
    }
    if(min_count!=100)
    {
        node->genCount();
        return;
    }
    else{
        cout<<"error:变量未声明"<<endl;
        return;  //未声明变量
    }
}

//遇到LP，所有ID的stack加上一个元素1
void stack_add()
{
    List_Node* cur = first;
    while(cur)
    {
        cur->s.push(1);
        cur = cur->next;
    }
}

//遇到RP，所有ID的stack pop掉一个元素，如果stack为空了，就释放掉节点
void stack_sub()
{
    if(first!=nullptr)
    {
        if(first->next==nullptr)    //只有一个变量
        {
            if(first->s.empty())
            {
                first = nullptr;//如果stack为空就释放掉
            }
            else first->s.pop();
        }
        else{
            if(first->s.empty())
            {
                first = first->next;
            }
            else first->s.pop();
            List_Node* cur = first;
            while(cur->next)
            {
                if(cur->next->s.empty())
                {
                    cur->next = cur->next->next;
                }
                else{
                    cur->next->s.pop();
                }
                cur = cur->next;
            }
            if(cur->s.empty())
            {
                cur = nullptr;
            }
            else cur->s.pop();
        } 
    }
}

%}
SGPS \/\/.*
DBPS \/\*(.|\n)*\*\/ 
EOL	(\r\n|\r|\n)
WHILTESPACE [[:blank:]]

relop ==|<=|>=|<|>|!=

INTEGER [0-9]+
CHAR \'.?\'
STRING \".+\"

IDENTIFIER [[:alpha:]_][[:alpha:][:digit:]_]*
%%

{DBPS}  /* do nothing */
{SGPS}  /* do nothing */

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

"void" {lasttoken = yytext; return T_VOID;};
"int" { lasttoken = yytext; return T_INT;};
"bool" { lasttoken = yytext; return T_BOOL;};
"char" {lasttoken = yytext; return T_CHAR;};
"string" {lasttoken = yytext; return T_STRING;};

"printf" return PRINTF;
"scanf" return SCANF;
"&" return QUOTE;

"=" return ASSIGN;
"+=" return ADD_ASSIGN;
"-=" return SUB_ASSIGN;
"*=" return MUL_ASSIGN;
"/=" return DIV_ASSIGN;

{relop} return RELOP;
"&&" return AND;
"||" return OR;
"!" return NOT;

"," return COMMA;
";" return  SEMICOLON;

"++" return INC;
"--" return DEC;
"+" return ADD;
"-" return SUB;
"*" return MUL;
"/" return DIV;
"(" return LP;
")" return RP;
"{" {stack_add(); return LC;};
"}" {stack_sub(); return RC;};

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
    if(lasttoken=="")
    {
        Insert_def_ID(yytext);
    }
    else{
        Insert_undef_ID(yytext);
    }
    TreeNode* node = new TreeNode(lineno, NODE_VAR);
    node->var_name = string(yytext);
    yylval = node;
    return IDENTIFIER;
}

{WHILTESPACE} /* do nothing */

{EOL} {lasttoken = ""; lineno++;}

. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%