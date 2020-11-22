#include "tree.h"
void TreeNode::addChild(TreeNode* child) {
    TreeNode::child[child_num] = child;
    child_num += 1;
}

void TreeNode::addSibling(TreeNode* sibling){
    TreeNode::sibling[sibling_num] = sibling;
    sibling_num += 1;
}

TreeNode::TreeNode(int lineno, NodeType type) {
    TreeNode::nodeID = NodeID;
    NodeID +=1; 
    TreeNode::lineno = lineno;
    TreeNode::nodeType = type;
    TreeNode::child_num = 0;
    TreeNode::sibling_num = 0;
}

void TreeNode::genNodeId() {
    cout<<"@"<<NodeID<<" ";
}

void TreeNode::printNodeInfo() {
    cout<<setw(10)<<"lno@"<<lineno;
    cout<<setw(10)<<"@"<<NodeID;
    cout<<setw(14)<<nodeType;
    cout<<"children:";
    printChildrenId();
}

void TreeNode::printChildrenId() {
    cout<<"[";
    for(int i=0;i<TreeNode::child_num;i++)
    {
        cout<<"@"<<child[i]->nodeID<<" ";
    }
    cout<<"]"<<endl;
}

void TreeNode::printAST() {

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

string TreeNode::opType2String(OperatorType type){
    return "!";
}

string TreeNode::nodeType2String (NodeType type){
    return "<>";
}
