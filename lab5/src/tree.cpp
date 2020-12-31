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
                if(this->child->type->type==TYPE_INT->type && this->child->sibling->type->type==TYPE_INT->type){
                    return 1;
                }
                else{
                    cout<<"expr_additive type error at line "<<this->lineno<<endl;
                    return 0;
                }
                break;
            case EXPR_ASSIGN://孩子类型相同
                //cout<<this->child->type->type<<" "<<this->child->sibling->type->type<<endl;
                if(this->child->type->type == this->child->sibling->type->type){
                    return 1;
                }
                else{
                    cout<<"expr_assign type error at line "<<this->lineno<<endl;
                    return 0;
                }
                break;
            case EXPR_LOGICAL://类型为bool型
                switch(optype){
                    case OP_NOT://单目运算
                        if(this->child->type->type==TYPE_BOOL->type){
                            return 1;
                        }
                        else{
                            cout<<"expr_logical type error at line "<<this->lineno<<endl;
                            return 0;
                        }
                        break;
                    default:
                        if(this->child->type->type==TYPE_BOOL->type && this->child->sibling->type->type==TYPE_BOOL->type){
                            return 1;
                        }
                        else{
                            cout<<"expr_logical type error at line "<<this->lineno<<endl;
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
                    cout<<"expr_relation type error at line "<<this->lineno<<endl;
                    return 0;
                }
                break;
            case EXPR_POSTFIX://整型
                if(this->child->type->type==TYPE_INT->type){
                    return 1;
                }
                else{
                    cout<<"expr_postfix type error at line "<<this->lineno<<endl;
                    return 0;
                }
                break;
            case EXPR_UNARY:
                if(this->optype==OP_NOT && (this->child->type->type==TYPE_BOOL->type||this->child->nodeType==NODE_VAR)){
                    return 1;
                }
                if(this->optype==OP_REF && this->child->nodeType==NODE_VAR)
                    return 1;
                if(this->optype==OP_SUB && this->child->type->type==TYPE_INT->type)
                    return 1;
                else{
                    cout<<"expr_unary type error at line "<<this->lineno<<endl;
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
        case STMT_FOR://要考虑缺省情况，只分为三个都有和最后一个缺省两种情况
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
            if(this->child_num==2){
                if((this->child->nodeType==NODE_STMT&&this->child->stype==STMT_DECL)||this->child->exprtype==EXPR_ASSIGN){
                    if(this->child->sibling->exprtype==EXPR_RELATION){
                        return 1;
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

//生成label
void TreeNode::gen_label(TreeNode* node){
    if(node==nullptr){
        return;
    }
    int flag=0;
    if(node->nodeType==NODE_PROG)
    {
        flag=1;
    }
    else if(node->nodeType==NODE_MAIN)
    {
        flag=1;
        if(node->label.begin_label==nullptr)
        {
            node->label.begin_label=new string("label_main_begin");
            *node->label.begin_label=*node->label.begin_label+to_string(node->nodeID);
        }
        if(node->label.next_label==nullptr)
        {
            node->label.next_label=new string("label_main_next");
            *node->label.next_label=*node->label.next_label+to_string(node->nodeID);
        }
        node->child->sibling->label.begin_label=node->label.next_label;//main函数入口的话应该是孩子的开始是爹的next
    }
    else if(node->nodeType==NODE_STMT && node->stype==STMT_IF)//if
    {
        flag=1;
        if(node->label.begin_label==nullptr)
        {
            node->label.begin_label=new string("label_if_begin");
            *node->label.begin_label=*node->label.begin_label+to_string(node->nodeID);
        }
        if(node->label.next_label==nullptr)
        {
            node->label.next_label=new string("label_if_next");
            *node->label.next_label=*node->label.next_label+to_string(node->nodeID);
        }
        if(this->child_num==2)//没有else
        {
            //兄弟节点的begin即为node的next
            if(node->sibling!=nullptr)
                node->sibling->label.begin_label=node->label.next_label;
            //if条件的true_label即为if语句块的begin
            node->child->label.true_label=node->child->sibling->label.begin_label=new string("label_if_true");
            *node->child->label.true_label+=to_string(node->child->nodeID);
            //if为真语句块的next即为if的next
            node->child->sibling->label.next_label=node->label.next_label;
            //if条件的false_label即为if语句块的next
            node->child->label.false_label=node->label.next_label;
        }
        else if(this->child_num==3)//有else
        {
            //兄弟节点的begin即为node的next
            if(node->sibling!=nullptr)
                node->sibling->label.begin_label=node->label.next_label;
            //if条件的true_label即为if语句块的begin
            node->child->label.true_label=node->child->sibling->label.begin_label=new string("label_if_true");
            *node->child->label.true_label+=to_string(node->child->nodeID);
            //if条件的false_label即为else语句块的begin
            node->child->label.false_label=node->child->sibling->sibling->label.begin_label=new string("label_if_false");
            *node->child->label.false_label+=to_string(node->child->nodeID);
            //if为真语句块的next即为if的next
            node->child->sibling->label.next_label=node->label.next_label;
            //if为假语句块的next即为if的next
            node->child->sibling->sibling->label.next_label=node->label.next_label;
        }
    }
    else if(node->nodeType==NODE_STMT && node->stype==STMT_DECL)//定义语句
    {
        flag=1;
        if(node->label.begin_label==nullptr)
        {
            node->label.begin_label=new string("decl_begin");
            *node->label.begin_label=*node->label.begin_label+to_string(node->nodeID);
        }
        if(node->label.next_label==nullptr)
        {
            node->label.next_label=new string("decl_next");
            *node->label.next_label=*node->label.next_label+to_string(node->nodeID);
        }
        //兄弟节点的begin即为node的next
        if(node->sibling!=nullptr)
            node->sibling->label.begin_label=node->label.next_label;
    }
    else if(node->nodeType==NODE_EXPR && node->exprtype==EXPR_ASSIGN)//赋值语句不带逗号
    {
        flag=1;
        if(node->label.begin_label==nullptr)
        {
            node->label.begin_label=new string("assign_expr_begin");
            *node->label.begin_label=*node->label.begin_label+to_string(node->nodeID);
        }
        if(node->label.next_label==nullptr)
        {
            node->label.next_label=new string("assign_expr_next");
            *node->label.next_label=*node->label.next_label+to_string(node->nodeID);
        }
        //兄弟节点的begin即为node的next
        if(node->sibling!=nullptr)
            node->sibling->label.begin_label=node->label.next_label;
    }
    else if(node->nodeType==NODE_STMT && node->stype==STMT_WHILE)//while语句
    {
        flag=1;
        TreeNode*condition=node->child;
        TreeNode*loop_body=node->child->sibling;
        if(node->label.begin_label==nullptr)
        {
            node->label.begin_label=new string("while_begin");
            *node->label.begin_label=*node->label.begin_label+to_string(node->nodeID);
        }
        if(node->label.next_label==nullptr)
        {
            node->label.next_label=new string("while_next");
            *node->label.next_label=*node->label.next_label+to_string(node->nodeID);
        }
        //兄弟节点的begin即为node的next
        if(node->sibling!=nullptr)
            node->sibling->label.begin_label=node->label.next_label;
        //循环体的下一条语句————循环的开始(继续循环)
        loop_body->label.next_label=node->label.begin_label;
        //循环体的开始标号即为循环条件的真值的标号
        loop_body->label.begin_label=condition->label.true_label=new string("while_body_begin"+to_string(loop_body->nodeID));
        //循环条件的假值标号即为循环的下一条语句标号
        condition->label.false_label=node->label.next_label;
    }
    else if(node->nodeType==NODE_STMT && node->stype==STMT_FOR && node->child_num==3)
    {
        TreeNode*condition=node->child->sibling;
        TreeNode*prev=node->child;
        TreeNode*after=node->child->sibling->sibling;
        TreeNode*loop_body=node->child->sibling->sibling->sibling;
        if(node->label.begin_label==nullptr)
        {
            node->label.begin_label=new string("for_e_e_e_begin");
            *node->label.begin_label=*node->label.begin_label+to_string(node->nodeID);
        }
        if(node->label.next_label==nullptr)
        {
            node->label.next_label=new string("for_e_e_e_next");
            *node->label.next_label=*node->label.next_label+to_string(node->nodeID);
        }
        //兄弟节点的begin即为node的next
        if(node->sibling!=nullptr)
            node->sibling->label.begin_label=node->label.next_label;
        //for循环第一个位置的begin即为for节点的begin
        prev->label.begin_label=node->label.begin_label;
        //for循环第一个位置的next应该是一个新的next
        prev->label.next_label=new string("for_first_pos_next"+to_string(prev->nodeID));
        //循环体的下一条语句应该是for最后一个位置的begin
        loop_body->label.next_label=after->label.begin_label=new string("for_loop_body_next"+to_string(loop_body->lineno));
        //循环体的开始语句应该是prev的next
        loop_body->label.begin_label=prev->label.next_label;
        //for循环最后一个位置的next应该是循环体的开始语句
        after->label.next_label=loop_body->label.begin_label;
        //condition的真值标号应该是循环体的begin
        condition->label.true_label=loop_body->label.begin_label;
        //condition的假值标号应该是for的next
        condition->label.false_label=node->label.next_label;
    }
    else if(node->nodeType==NODE_STMT && node->stype==STMT_FOR && node->child_num==2)
    {
        TreeNode*prev=node->child;
        TreeNode*condition=node->child->sibling;
        TreeNode*loop_body=node->child->sibling->sibling;
        if(node->label.begin_label==nullptr)
        {
            node->label.begin_label=new string("for_e_e__begin");
            *node->label.begin_label=*node->label.begin_label+to_string(node->nodeID);
        }
        if(node->label.next_label==nullptr)
        {
            node->label.next_label=new string("for_e_e__next");
            *node->label.next_label=*node->label.next_label+to_string(node->nodeID);
        }
        //兄弟节点的begin即为node的next
        if(node->sibling!=nullptr)
            node->sibling->label.begin_label=node->label.next_label;
        //for循环第一个位置的begin即为for节点的begin
        prev->label.begin_label=node->label.begin_label;
        //for循环第一个位置的next应该是一个新的next
        prev->label.next_label=new string("for_first_pos_next"+to_string(prev->nodeID));
        //循环体的开始应该是第一个位置的next
        loop_body->label.begin_label=prev->label.next_label;
        //循环体的next应该是第一个位置的next
        loop_body->label.next_label=prev->label.next_label;
        //condition的真值是循环的开始
        condition->label.true_label=loop_body->label.begin_label;
        //condition的假值是node的next
        condition->label.false_label=node->label.next_label;
    }
    else if(node->nodeType==NODE_EXPR)
    {
        if(node->exprtype==EXPR_LOGICAL)
        {
            if(node->optype==OP_OR)
            {
                flag=1;
                TreeNode*first_op=node->child;
                TreeNode*seconde_op=node->child->sibling;
                if(node->label.true_label==nullptr)
                {
                    node->label.true_label=new string("expr_or_true_label"+to_string(node->nodeID));
                }
                if(node->label.false_label==nullptr)
                {
                    node->label.false_label=new string("expr_or_false_label"+to_string(node->nodeID));
                }
                first_op->label.true_label=node->label.true_label;
                first_op->label.false_label=new string("E1_false_label"+to_string(first_op->nodeID));
                seconde_op->label.true_label=node->label.true_label;
                seconde_op->label.false_label=node->label.false_label;
            }
            else if(node->optype==OP_AND)
            {
                flag=1;
                TreeNode*first_op=node->child;
                TreeNode*seconde_op=node->child->sibling;
                if(node->label.true_label==nullptr)
                {
                    node->label.true_label=new string("expr_and_true_label"+to_string(node->nodeID));
                }
                if(node->label.false_label==nullptr)
                {
                    node->label.false_label=new string("expr_and_false_label"+to_string(node->nodeID));
                }
                first_op->label.true_label=new string("E1_true_label"+to_string(first_op->nodeID));
                first_op->label.false_label=node->label.false_label;
                seconde_op->label.true_label=node->label.true_label;
                seconde_op->label.false_label=node->label.false_label;
            }
        }
        else if(node->exprtype==EXPR_UNARY && node->optype==OP_NOT)
        {
            flag=1;
            TreeNode*E1=node->child;
            if(node->label.true_label==nullptr)
            {
                node->label.true_label=new string("expr_and_true_label"+to_string(node->nodeID));
            }
            if(node->label.false_label==nullptr)
            {
                node->label.false_label=new string("expr_and_false_label"+to_string(node->nodeID));
            }
            E1->label.true_label=node->label.false_label;
            E1->label.false_label=node->label.true_label;
        }
    }
    if(flag)
    {
        TreeNode *tmp = node->child;
        while (tmp != nullptr)
        {
            gen_label(tmp);
            tmp = tmp->sibling;
        }
    }
}

int find_str(list<string*>*str_list,string*str)
{
    if(str_list->empty())
        return 0;
    for(list<string*>::iterator i = str_list->begin();i!=str_list->end();i++)
    {
        if(**i==*str)
        {
            return 1;
        }
    }
    return 0;
}

void TreeNode:: print_label(TreeNode*root,list<string*>*str_list)
{
    if(root==nullptr)
        return;
    if(root->label.begin_label!=nullptr&&!find_str(str_list,root->label.begin_label))
    {
        cout<<*root->label.begin_label<<endl<<endl;
        str_list->push_back(root->label.begin_label);
    }
    TreeNode*tmp=root->child;
    while(tmp!=nullptr)
    {
        print_label(tmp,str_list);
        tmp=tmp->sibling;
    }
    if(root->label.next_label!=nullptr&&!find_str(str_list,root->label.next_label))
    {
        cout<<*root->label.next_label<<endl<<endl;
        str_list->push_back(root->label.next_label);
    }
}
