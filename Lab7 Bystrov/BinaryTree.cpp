#include "BinaryTree.h"
#include <iostream>

using namespace std;

 void BinaryTree::Insert(int value)
{
	 if (Root.getValue() == NULL)
		 Root.setValue(value);
	 else
		 Insert(value, &Root);
}

TreeNode* BinaryTree::Search(int value)
{
	return Search(value, &Root);
}

void BinaryTree::Insert(int value, TreeNode* rootptr)
{
	if (value < rootptr->getValue())
	{
		if (rootptr->getLPointer() == NULL)
			rootptr->setLPointer(value);
		else
			Insert(value, rootptr->getLPointer());
	}
	if (value > rootptr->getValue())
	{
		if (rootptr->getRPointer() == NULL)
			rootptr->setRPointer(value);
		else
			Insert(value, rootptr->getRPointer());
	}
}

TreeNode* BinaryTree::Search(int value, TreeNode* rootptr)
{
	if (value == rootptr->getValue())
		return rootptr;
	else if (value < rootptr->getValue())
		Search(value, rootptr->getLPointer());
	else if (value > rootptr->getValue())
		Search(value, rootptr->getRPointer());
}

BinaryTree::~BinaryTree()
{
	RemoveBinaryTree(&Root);
}

void BinaryTree::RemoveBinaryTree(TreeNode* rootptr)
{
	if (rootptr->getLPointer() != nullptr)
		RemoveBinaryTree(rootptr->getLPointer());
	if (rootptr->getRPointer() != nullptr)
		RemoveBinaryTree(rootptr->getRPointer());
	free(rootptr);
}

void BinaryTree::CreateMinimalBST(int* start, int startIndex, int lastIndex)
{
	int* startPtr = start;
	int* lastPtr = start;
	int* middlePtr = start;
	int middleIndex = (lastIndex + startIndex) / 2;
	for (int i = 0; i < startIndex; i++)
		startPtr++;
	for (int i = 0; i < lastIndex; i++)
		lastPtr++;
	for (int i = 0; i < middleIndex; i++)
		middlePtr++;
	Insert(*middlePtr);
	if (startIndex==lastIndex)
		return;
	if (middleIndex!= startIndex)
		CreateMinimalBST(start, startIndex, middleIndex-1);
	if (middleIndex != lastIndex)
		CreateMinimalBST(start, middleIndex+1, lastIndex);
}