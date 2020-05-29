#pragma once
#include "TreeNode.h"

class BinaryTree
{
public:
	BinaryTree() {};
	BinaryTree(int value) {};
	~BinaryTree();
	void Insert(int value);
	TreeNode* Search(int value);
	void CreateMinimalBST(int* start, int startIndex,int lastIndex);

private:
	TreeNode Root;
	void Insert(int value,TreeNode* rootptr);
	TreeNode* Search(int value, TreeNode* rootptr);
	void RemoveBinaryTree(TreeNode* rootptr);
};

