#ifndef TREE_H
#define TREE_H

#include "pch.h"
#include "type.h"
#include "SymbolTable.h"
#define layerNum 50
#define layerDescNum 100
struct layerNode;
struct changeField;
struct TreeNode;
struct funcInfo;

struct layerNode
{
    layerNode* prev;
    layerNode* list[layerNum];
    int layerDesc[layerDescNum];
    int nodeCount;
    int accessTime;
    SymbolTableSection * section;
};

struct changeField
{
    int needChange;
    int accessTime;
};

struct funcInfo{
    TreeNode* return_value;
    TreeNode* func_name;
    TreeNode* decl_list;
    TreeNode* func_body;
    TreeNode* arg_list;
};

enum NodeType
{
    NODE_CONST, 
    NODE_VAR,
    NODE_EXPR,
    NODE_TYPE,

    NODE_STMT,
    NODE_PROG,
    NODE_BLOCK,//语句块
    NODE_MAIN,//main函数
    NODE_FUNC_DEF,//函数定义
    NODE_FUNC_CALL,//函数调用
};

enum OperatorType
{
    //关系运算
    OP_EQ,  // ==
    OP_GT,  // >
    OP_LT,  // <
    OP_GQT, // >=
    OP_LQT, // <=
    OP_NEQ, // !=

    //算术运算符
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MODE, // %

    //逻辑运算符
    OP_AND,
    OP_OR,
    OP_NOT,

    //赋值符
    OP_ASSIGN,
    OP_ADD_ASSIGN,
    OP_SUB_ASSIGN,
    OP_MUL_ASSIGN,
    OP_DIV_ASSIGN,

    OP_INC,
    OP_DEC,
    OP_COMMA,
    OP_REF,
};

enum StmtType {
    STMT_SKIP,
    STMT_DECL,
    STMT_ASSIGN,
    STMT_IF,
    STMT_WHILE,
    STMT_FOR,
    STMT_RETURN,
    STMT_SCANF,
    STMT_PRINTF,
    STMT_CONTINUE,
    STMT_BREAK,
}

enum ExprType {
    EXPR_ADDITIVE,//算术表达式
    EXPR_ASSIGN,//赋值
    EXPR_LOGICAL,//逻辑
    EXPR_RELATION,//关系
    EXPR_POSTFIX,//后缀
    EXPR_UNARY,//前缀
}
;


struct TreeNode {
public:
    int nodeID;  // 用于作业的序号输出
    int lineno;
    NodeType nodeType;

    TreeNode* child = nullptr;
    TreeNode* sibling = nullptr;
    int child_num;

    void addChild(TreeNode*);
    void addSibling(TreeNode*);
    
    void printNodeInfo();
    void printChildrenId();

    void printAST(); // 先输出自己 + 孩子们的id；再依次让每个孩子输出AST。
    void printSpecialInfo();

    void genNodeId();

public:
    OperatorType optype;  // 如果是表达式
    Type* type;  // 变量、类型、表达式结点，有类型。
    StmtType stype;
    ExprType exprtype;
    int int_val;
    char ch_val;
    bool b_val;
    string str_val;
    string var_name;
    layerNode* layer_node;
    changeField change_field;
    funcInfo* func_info;
    int is_def;//是否是定义的变量

public:
    static string nodeType2String (NodeType type);
    static string opType2String (OperatorType type);
    static string sType2String (StmtType type);
    void change_Field(TreeNode* node);
    void change_Child_Field(TreeNode* node);
    int check_type();//类型检查


public:
    TreeNode(int lineno, NodeType type);
};


#endif