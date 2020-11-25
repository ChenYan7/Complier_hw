#include "tree.h"
static int node_num = 0;
void TreeNode::addChild(TreeNode* child) {
    if(this->child==nullptr)
    {
        this->child = child;
    }
    else{
        this->child->addSibling(child);
    }
    this->child_num += 1;
}

void TreeNode::addSibling(TreeNode* sibling){
    if(this->sibling==nullptr)
    {
        this->sibling = sibling;
    }
    else
    {
        this->sibling->addSibling(sibling);
    }
    this->sibling_num+=1;
}

TreeNode::TreeNode(int lineno, NodeType type) {
    this->lineno = lineno;
    this->nodeType = type;
    this->child_num = 0;
    this->sibling_num = 0;
}

void TreeNode::genNodeId() {
    this->nodeID = node_num;
    node_num ++;
    if(this->child)
        this->child->genNodeId();
    if(this->sibling)
        this->sibling->genNodeId();
}

void TreeNode::printNodeInfo() {
    cout<<setw(10)<<"lno@"<<this->lineno;
    cout<<setw(10)<<"@"<<this->nodeID;
    cout<<setw(14)<<this->nodeType2String(this->nodeType);
    cout<<"children:";
    printChildrenId();
}

void TreeNode::printChildrenId() {
    cout<<"[";
    if(this->child!=nullptr)
    {
        cout<<"@"<<this->child->nodeID<<" ";
        TreeNode* node = this->child;
        while(node->sibling!=nullptr)
        {
            cout<<"@"<<node->sibling->nodeID<<" ";
            node = node->sibling;
        }
    }
    cout<<"]"<<endl;
}

void TreeNode::printAST() {
    this->printNodeInfo();
    if(this->child)
        this->child->printAST();
    if(this->sibling)
        this->sibling->printAST();
}


// You can output more info...
void TreeNode::printSpecialInfo() {
    switch(this->nodeType){
        case NODE_CONST:
            break;
        case NODE_VAR:
            break;
        case NODE_EXPR:
            break;
        case NODE_STMT:
            break;
        case NODE_TYPE:
            break;
        default:
            break;
    }
}

string TreeNode::sType2String(StmtType type) {
    return "?";
}


string TreeNode::nodeType2String (NodeType type){
    string str;
    switch(type)
    {
        case NODE_CONST:
            str = "const";
            break;
        case NODE_EXPR:
            str = "expr";
            break;
        case NODE_PROG:
            str = "program";
            break;
        case NODE_STMT:
            str = "statment";
            break;
        case NODE_TYPE:
            str = "type";
            break;
        case NODE_VAR:
            str = "variable";
            break;
    }
    return str;
}
