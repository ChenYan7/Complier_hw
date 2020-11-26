#include "List.h"


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