#include "tree.h"
int node_num = 0;
void printLayer(layerNode*node);

void TreeNode::addChild(TreeNode* child) {
    if(this->child==nullptr)
    {
        this->child = child;
    }
    else{
        this->child->addSibling(child);
    }
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
}

TreeNode::TreeNode(int lineno, NodeType type) {
    this->lineno = lineno;
    this->nodeType = type;
    this->layer_node=nullptr;
    this->change_field.accessTime=0;
    this->change_field.needChange=0;
}

void TreeNode::genNodeId() {
    //cout<<node_num<<endl;
    this->nodeID = node_num;
    //cout<<this->lineno<<endl;
    node_num++;
    if(this->child)
        this->child->genNodeId();
    if(this->sibling)
        this->sibling->genNodeId();
}

void TreeNode::printNodeInfo() {
    cout<<"lno@"<<this->lineno<<"   ";
    cout<<"@"<<this->nodeID<<"      ";
    cout<<this->nodeType2String(this->nodeType)<<"    ";
    if(this->nodeType==NODE_PROG || this->nodeType==NODE_STMT || this->nodeType==NODE_EXPR 
        || this->nodeType==NODE_MAIN||this->nodeType==NODE_BLOCK||this->nodeType==NODE_FUNC_DEF||this->nodeType==NODE_FUNC_CALL)
    {
        cout<<"children: ";
        printChildrenId();
    }
    this->printSpecialInfo();
    cout<<endl;
}

void TreeNode::printChildrenId() {
    cout<<"[ ";
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
    cout<<"]    ";
}

void TreeNode::printAST() {
    this->printNodeInfo();
    //cout<<this->nodeType2String(this->nodeType)<<endl;
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
            if(this->type->getTypeInfo()=="bool")
                cout<<" [var:"<<this->b_val<<"]";
            if(this->type->getTypeInfo()=="int")
                cout<<" [var:"<<this->int_val<<"]";
            if(this->type->getTypeInfo()=="char")
                cout<<" [var:"<<this->ch_val<<"]";
            if(this->type->getTypeInfo()=="string")
                cout<<" [var:"<<this->str_val<<"]";
            break;
        case NODE_VAR:
            cout<<"varname:"<<this->var_name<<"     layer:";
            printLayer(this->layer_node);
            break;
        case NODE_EXPR:
            cout<<"op:"<<this->opType2String(this->optype);
            break;
        case NODE_STMT:
            cout<<"stmt:"<<this->sType2String(this->stype);
            if(this->sType2String(this->stype)=="assign")
            {
                cout<<"   op:"<<this->opType2String(this->optype);
            }
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
        case STMT_CONTINUE:
            str = "continue";
            break;
        case STMT_BREAK:
            str = "break";
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
        case NODE_BLOCK:
            str = "statement block";
            break;
        case NODE_MAIN:
            str = "main";
            break;
        case NODE_FUNC_CALL:
            str = "function call";
            break;
        case NODE_FUNC_DEF:
            str = "function definition";
            break;
        default:
            str = "?";
    }
    return str;
}

string TreeNode::opType2String (OperatorType type)
{
    string str;
    switch(type)
    {
        case OP_EQ:
            str = "==";
            break;
        case OP_GT:
            str = ">";
            break;
        case OP_LT:
            str = "<";
            break;
        case OP_GQT:
            str = ">=";
            break;
        case OP_LQT:
            str = "<=";
            break;
        case OP_NEQ:
            str = "!=";
            break;
        case OP_ADD:
            str = "+";
            break;
        case OP_SUB:
            str = "-";
            break;
        case OP_MUL:
            str = "*";
            break;
        case OP_DIV:
            str = "/";
            break;
        case OP_MODE:
            str = "%";
            break;
        case OP_AND:
            str = "&&";
            break;
        case OP_OR:
            str = "||";
            break;
        case OP_NOT:
            str = "!";
            break;
        case OP_ASSIGN:
            str = "=";
            break;
        case OP_ADD_ASSIGN:
            str = "+=";
            break;
        case OP_SUB_ASSIGN:
            str = "-=";
            break;
        case OP_MUL_ASSIGN:
            str = "*=";
            break;
        case OP_DIV_ASSIGN:
            str = "/=";
            break;
        case OP_INC:
            str = "++";
            break;
        case OP_DEC:
            str = "--";
            break;
        case OP_COMMA:
            str = ",";
            break;
        case OP_REF:
            str = "&";
            break;
        default:
            str = "??";
    }
    return str;
}

void TreeNode::change_Child_Field(TreeNode* node)
{
    if(node->child==nullptr)
        return;
    TreeNode*tmp=node->child;
    while(tmp!=nullptr)
    {
        if(tmp->nodeType!=NODE_BLOCK)
        {
            tmp->layer_node=node->layer_node;
            change_Child_Field(tmp);
        }    
        tmp=tmp->sibling;   
    }
}
void TreeNode:: change_Field(TreeNode* node)
{
    if(node->change_field.needChange)
    {
        node->layer_node=node->layer_node->list[node->change_field.accessTime];
        change_Child_Field(node);
    }
}

layerNode* makeNode(layerNode* node)
{
    layerNode* temp = node->list[node->nodeCount]=new layerNode;
    temp->nodeCount=0;
    temp->prev=node;
    temp->accessTime=0;
    //process layerDesc
    int flag=0;
    for(int i=0;i<layerDescNum;i++)
    {
        if(node->layerDesc[i]!=-1)
        {
            temp->layerDesc[i]=node->layerDesc[i];
            flag++;
        }
        else
        {
            temp->layerDesc[i]=-1;
        }
        
    }
    temp->layerDesc[flag]=node->nodeCount;
    node->nodeCount++;
    temp->section=new SymbolTableSection;
    return temp;
}

void printLayer(layerNode*node)
{
    if(node==nullptr)
    {
        cout<<"null"<<"     ";
        return ;
    }
    for(int i=0;i<layerDescNum&&node->layerDesc[i]!=-1;i++)
    {
        if(i+1<layerDescNum&&node->layerDesc[i+1]==-1)
        {
            cout<<node->layerDesc[i];
        }
        else
        {   
            cout<<node->layerDesc[i]<<"-";
        }
    }
    cout<<"    ";
}
