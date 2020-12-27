#include "pch.h"
#include "tree.h"
#pragma once
#ifndef layerNum
#define layerNum 50 //横向层级
#endif
#ifndef layerDescNum
#define layerDescNum 100  //纵向层级
#endif
struct TreeNode;
struct layerNode;

enum SymbolType{
    SYMBOL_VAR,
    SYMBOL_FUNC,
};

enum SymbolProperty{
    PROPERTY_DEF,//定义
    PROPERTY_REFE,//引用
};

//符号表元素结构
struct Item{
public:
    string name;
    SymbolType symbol_type;
    SymbolProperty symbol_property;
    TreeNode* tree_node;
};

struct SymbolTableSection{
public:
    list<Item*> section_table;
    int layerDesc[layerDescNum];
};

//全部符号表
struct SymbolTable{
public:
    list<SymbolTableSection*> symbol_table;
};

void copyLayerDesc(int* lay1,int* lay2);
void setProperty(SymbolTableSection* section,TreeNode* tree_node,SymbolProperty type);
void correctSymbol(layerNode*node);
void printSymbolTable(layerNode*node);
void setSymbolType(SymbolTableSection* section,TreeNode* tree_node,SymbolType type);
string SymbolProperty2String(SymbolProperty type);
string SymbolType2String(SymbolType type);