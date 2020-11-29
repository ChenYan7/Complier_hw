#ifndef LIST_H
#define LIST_H

#include "pch.h"
#include "type.h"

struct List_Node{
    string name;
    stack<int> s;
    int count = 0;
    struct List_Node* next=nullptr;
    List_Node(string name);
    void genCount();
};

//List_Node* first=nullptr;
void Insert_undef_ID(string name);
void Insert_def_ID(string name);
void stack_add();
void stack_sub();

#endif