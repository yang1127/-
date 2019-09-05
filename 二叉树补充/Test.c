#include "BinaryTree.h"

void TestBinaryTree()
{
	char a[] = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, &i);
	printf("�����������ɹ���");
	printf("\n");

	printf("������:%d\n", BinaryTreeSize(root));
	printf("Ҷ�ӽ�����:%d\n", BinaryTreeLeafSize(root));
	printf("��K=3�������:%d\n", BinaryTreeLevelKSize(root, 3));

	//printf("C��λ��Ϊ��" );
	//BinaryTreeFind(root, 'C');
	//printf("\n");

	printf("ǰ�������");
	BinaryTreePrevOrder(root);
	printf("\n");

	printf("���������");
	BinaryTreeInOrder(root);
	printf("\n");

	printf("���������");
	BinaryTreePostOrder(root);
	printf("\n");

	//printf("��α�����");
	//BinaryTreeLevelOrder(root);
	//printf("\n");

	//printf("�ж��Ƿ�Ϊ��ȫ������(true-�ǡ�false-��)��");
	//BinaryTreeComplete(root);
	//printf("\n");
}

int main()
{
	TestBinaryTree();
	system("pause");
	return 0;
}