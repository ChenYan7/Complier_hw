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
    cout<<"lno@"<<this->lineno<<"   ";
    cout<<"@"<<this->nodeID<<"  ";
    cout<<this->nodeType2String(this->nodeType)<<"  ";
    if(this->nodeType==NODE_PROG || this->nodeType==NODE_STMT || this->nodeType==NODE_EXPR)
    {
        cout<<"children:";
        printChildrenId();
    }
    this->printSpecialInfo();
    cout<<endl;
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
    cout<<"]";
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
            cout<<"type:"<<this->type->getTypeInfo();
            break;
        case NODE_VAR:
            cout<<"varname:"<<this->var_name;
            break;
        case NODE_EXPR:
            break;
        case NODE_STMT:
            cout<<"stmt:"<<this->sType2String(this->stype);
            break;
        case NODE_TYPE:
            cout<<"type:"<<this->type->getTypeInfo();
            break;
        default:
            break;
    }
}

string TreeNode::sType2String(StmtType type) {
    string str;
    switch(type)
    {
        case STMT_SKIP:
            str = "skip";
            break;
        case STMT_DECL:
            str = "declaration";
            break;
        case STMT_ASSIGN:
            str = "assign";
            break;
        case STMT_IF:
            str = "if";
            break;
        case STMT_WHILE:
            str = "while";
            break;
        case STMT_FOR:
            str = "for";
            break;
        case STMT_RETURN:
            str = "return";
            break;
        case STMT_SCANF:
            str = "scanf";
            break;
        case STMT_PRINTF:
            str = "printf";
            break;
    }
    return str;
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
            str = "statement";
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
