#include "BT.h"

void TestBinaryTree()
{
	char a[] = "ABDG###E##CF###";
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, &i);
    cout << "二叉树创建成功！";
	cout << endl;

	cout << "前序遍历：";
	BinaryTreePrevOrder(root);
	cout << endl;

	cout << "中序遍历：";
	BinaryTreeInOrder(root);
	cout << endl;

	cout << "后序遍历：";
	BinaryTreePostOrder(root);
	cout << endl;
}

int main()
{
	TestBinaryTree();
	system("pause");
	return 0;
}