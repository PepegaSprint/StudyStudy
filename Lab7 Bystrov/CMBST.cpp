#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
	BinaryTree* KEKW = new BinaryTree();
	KEKW->Insert(2);
	KEKW->Insert(5);
	KEKW->Insert(6);
	KEKW->Insert(9);
	KEKW->Insert(1);
	KEKW->Insert(7);
	TreeNode* LULW = KEKW->Search(6);
	cout << LULW->getValue();
	KEKW->~BinaryTree();
	int arr[9]{1,6,12,16,18,21,25,28,30};
	int* pstart = &arr[0];
	BinaryTree* POG = new BinaryTree();
	POG->CreateMinimalBST(pstart, 0, 9);
	POG->~BinaryTree();
	cout << endl;
	system("pause");
	return 0;

}