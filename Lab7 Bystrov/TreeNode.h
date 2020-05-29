#pragma once

class TreeNode
{
public:
	TreeNode();
	TreeNode(int value);
	TreeNode* getLPointer();
	TreeNode* getRPointer();
	void setLPointer(int value);
	void setRPointer(int value);
	int	 getValue();
	void setValue(int value);


private:
	int Value;
	TreeNode* LPointer;
	TreeNode* RPointer;
};