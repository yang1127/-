#include "BT.h"

void TestBinaryTree()
{
	char a[] = "ABDG###E##CF###";
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, &i);
    cout << "�����������ɹ���";
	cout << endl;

	cout << "ǰ�������";
	BinaryTreePrevOrder(root);
	cout << endl;

	cout << "���������";
	BinaryTreeInOrder(root);
	cout << endl;

	cout << "���������";
	BinaryTreePostOrder(root);
	cout << endl;
}

int main()
{
	TestBinaryTree();
	system("pause");
	return 0;
}