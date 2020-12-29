#include "tree.h"
extern void printLayer(layerNode*node);

//复制层级表
void copyLayerDesc(int* layer1,int* layer2)
{
    for(int i=0;i<layerDescNum;i++)
        layer1[i]=layer2[i];
}

//设置变量的type
void setProperty(SymbolTableSection* section,TreeNode* tree_node,SymbolProperty type)
{
    for(list<Item*>::iterator i=section->section_table.begin();i!=section->section_table.end();i++)
    {
        if((*i)->tree_node==tree_node)
        {
            (*i)->symbol_property=type;
        }
    }
}

void correctSymbol(layerNode*node)
{
    if(node==nullptr)
        return;
    //修正该layerNode内部
    for(list<Item*>::iterator i=node->section->section_table.begin();i!=node->section->section_table.end();)
    {
        if((*i)->tree_node->layer_node!=node)
        {
            layerNode* tmp=(*i)->tree_node->layer_node;
            tmp->section->section_table.push_back(*i);
            i=node->section->section_table.erase(i);
        }
        else
        {
            i++;
        }
    }
    //修正同层的
    for(int i=0;i<node->nodeCount;i++)
    {
        correctSymbol(node->list[i]);
    }
}

//设置符号表类型
void setSymbolType(SymbolTableSection* section,TreeNode* tree_node,SymbolType type)
{
    for(list<Item*>::iterator i=section->section_table.begin();i!=section->section_table.end();i++)
    {
        if((*i)->tree_node==tree_node)
        {
            (*i)->symbol_type=type;
        }
    }
}

void printSymbolTable(layerNode*node)
{
    if(node==nullptr)
        return;
    cout<<"layer:";
    printLayer(node);
    cout<<endl;
    for(list<Item*>::iterator i=node->section->section_table.begin();i!=node->section->section_table.end();i++)
    {
        cout<<"symbolname:"<<(*i)->name<<"    ";
        cout<<"ref_or_def:"<<SymbolProperty2String((*i)->symbol_property)<<"     ";
        cout<<"symbol_type:"<<SymbolType2String((*i)->symbol_type)<<"    ";
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<node->nodeCount;i++)
    {
        printSymbolTable(node->list[i]);
    }
}

string SymbolProperty2String(SymbolProperty type)
{
    switch (type)
    {
        case PROPERTY_DEF:{
            return "PROPERTY_DEF";
        }
        case PROPERTY_REFE:{
            return "PROPERTY_REFE";
        }
        default:
            return "?";
    }
}

string SymbolType2String(SymbolType type)
{
    switch(type)
    {
        case SYMBOL_FUNC:{
            return "SYMBOL_FUNC";
        }
        case SYMBOL_VAR:{
            return "SYMBOL_VAR";
        }
        default:
            return "?";
    }
}

//根据变量的定义和引用情况修正作用域
int assignRefSymbolType(layerNode* node,Item* item)
{
    if(node==nullptr)
        return 0;
    if(node->is_func)//如果是在函数体中寻找，则不再向上一级寻找
    {
        for(list<Item*>::iterator i=node->section->section_table.begin();i!=node->section->section_table.end();i++)
        {
            if((*i)->name==item->name&&(*i)->symbol_property==PROPERTY_DEF&&item!=(*i))
            {
                item->tree_node->type=(*i)->tree_node->type;//先设置类型相同
                //将引用的符号指向定义的符号
                item->def_pos=(*i)->def_pos;
                return 1;
            }
        }
        return 0;
    }
    for(list<Item*>::iterator i=node->section->section_table.begin();i!=node->section->section_table.end();i++)
    {
        //从符号表中寻找定义的同名变量
        if((*i)->name==item->name&&(*i)->symbol_property==PROPERTY_DEF&&item!=(*i)&&(*i)->symbol_type==SYMBOL_VAR)
        {
            item->tree_node->type=(*i)->tree_node->type;//先设置类型相同
            //将引用的符号指向定义的符号
            item->def_pos=(*i)->def_pos;
            return 1;
        }
    }
    /*
        在多级符号表中有可能需要向上一级作用域寻找
    */
    return assignRefSymbolType(node->prev,item);
}

//检查变量的未定义和重定义错误
void check_symbol_table(SymbolTableSection* section)
{
    //普通符号是否存在定义前引用
    for(list<Item*>::iterator i=section->section_table.begin();i!=section->section_table.end();i++)
    {
        if((*i)->symbol_type!=SYMBOL_FUNC)
        {
            if((*i)->def_pos==(*i)->tree_node&&(*i)->symbol_property==PROPERTY_REFE)
            {
                cout<<"varible referenced before defnition at line"<<(*i)->tree_node->lineno<<endl;
            }
        }
        //符号重定义
        if((*i)->symbol_property==PROPERTY_DEF)
        {
            for(list<Item*>::iterator j = i;j!=section->section_table.end();j++)
            {
                if((*j)->symbol_property==PROPERTY_DEF&&(*j)->name==(*i)->name&&*j!=*i)
                {
                    cout<<"varible redefined at line"<<(*j)->tree_node->lineno<<endl;
                    //cout<<(*j)->name<<endl;
                }
            }
        }
    }
}