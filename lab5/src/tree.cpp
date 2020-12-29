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
    this->child_num++;
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
    this->child_num = 0;
    this->layer_node=nullptr;
    this->change_field.accessTime=0;
    this->change_field.needChange=0;
    this->change_field.is_func_field=0;
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
    //进入下一层
    if(node->change_field.needChange)
    {
        node->layer_node=node->layer_node->list[node->change_field.accessTime];
        change_Child_Field(node);
    }
    if(node->change_field.is_func_field)
    {
        node->layer_node->is_func=1;//表示这个layer_node是一个函数体的layer
    }
}

//生成一个域节点
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
    for(int i=0;i<layerDescNum &&node->layerDesc[i]!=-1;i++)
    {
        if(i+1<layerDescNum &&node->layerDesc[i+1]==-1)
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

//寻找函数定义位置
TreeNode* findFuncDef(string func_name,list<TreeNode*> func_list)
{
    for(list<TreeNode*>::iterator i=func_list.begin();i!=func_list.end();i++)
    {
        if((*i)->func_info->func_name->var_name==func_name)
            return *i;
    }
    return nullptr;
}

int TreeNode::check_type()
{
    if(this->nodeType==NODE_EXPR){
        switch(this->exprtype){
            case EXPR_ADDITIVE://两孩子均为整型
                if(this->child->type==TYPE_INT && this->child->sibling->type==TYPE_INT){
                    return 1;
                }
                else{
                    cout<<"expr_additive type error"<<endl;
                    return 0;
                }
                break;
            case EXPR_ASSIGN://孩子类型相同
                //cout<<this->child->type->type<<" "<<this->child->sibling->type->type<<endl;
                if(this->child->type->type == this->child->sibling->type->type){
                    return 1;
                }
                else{
                    cout<<"expr_assign type error"<<endl;
                    return 0;
                }
                break;
            case EXPR_LOGICAL://类型为bool型
                switch(optype){
                    case OP_NOT://单目运算
                        if(this->child->type==TYPE_BOOL){
                            return 1;
                        }
                        else{
                            cout<<"expr_logical type error"<<endl;
                            return 0;
                        }
                        break;
                    default:
                        if(this->child->type==TYPE_BOOL && this->child->sibling->type==TYPE_BOOL){
                            return 1;
                        }
                        else{
                            cout<<"expr_logical type error"<<endl;
                            return 0;
                        }
                        break;
                }
                break;
            case EXPR_RELATION://类型相同
                if(this->child->type->type == this->child->sibling->type->type){
                    return 1;
                }
                else{
                    cout<<"expr_relation type error"<<endl;
                    return 0;
                }
                break;
            case EXPR_POSTFIX://整型
                if(this->child->type==TYPE_INT){
                    return 1;
                }
                else{
                    cout<<"expr_postfix type error"<<endl;
                    return 0;
                }
                break;
            case EXPR_UNARY:
                if(this->child->type==TYPE_INT){
                    return 1;
                }
                else{
                    cout<<"expr_unary type error"<<endl;
                    return 0;
                }
                break;
            default:
                return 1;
        }
    }
    if(this->nodeType==NODE_STMT){
        switch(this->stype)
        {
        case STMT_WHILE://关系表达式、逻辑表达式
            if(this->child->exprtype==EXPR_RELATION || this->child->exprtype==EXPR_LOGICAL){
                return 1;
            }
            else return 0;
        case STMT_IF://关系表达式
            if(this->child->exprtype==EXPR_RELATION){
                return 1;
            }
            else return 0;
        case STMT_FOR://要考虑缺省情况
            if(this->child_num==3){
                if((this->child->nodeType==NODE_STMT&&this->child->stype==STMT_DECL)||this->child->exprtype==EXPR_ASSIGN){
                    if(this->child->sibling->exprtype==EXPR_RELATION){
                        if(this->child->sibling->sibling->nodeType==NODE_EXPR){
                            return 1;
                        }
                        else return 0;
                    }
                    else return 0;
                }
                else return 0;
            }
            break;
        }
    }
}

//检查变量的定义与重定义
void check_section(layerNode* node)
{
    check_symbol_table(node->section);
    for(int i=0;i<node->nodeCount;i++)
    {
        check_section(node->list[i]);
    }
}

// //生成label
// void TreeNode::gen_label(TreeNode* node){
//     if(node==nullptr){
//         return;
//     }

// }
