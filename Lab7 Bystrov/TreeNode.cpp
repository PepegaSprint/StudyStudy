#include "TreeNode.h"
#include <iostream>

using namespace std;


TreeNode::TreeNode()
{
    Value = NULL;
    LPointer = nullptr;
    RPointer = nullptr;
}


TreeNode::TreeNode(int value)
{
    Value = value;
    LPointer = nullptr;
    RPointer = nullptr;
}

TreeNode* TreeNode :: getLPointer()
{
    return LPointer;
}

TreeNode* TreeNode :: getRPointer()
{
    return RPointer;
}

void TreeNode::setLPointer(int value)
{
    TreeNode* lNode = new TreeNode(value);
    LPointer = lNode; 
}

void TreeNode::setRPointer(int value)
{
    TreeNode* rNode = new TreeNode(value);
    RPointer = rNode;
}

int TreeNode::getValue()
{
    return Value;
}

void TreeNode::setValue(int value)
{
    Value = value;
}