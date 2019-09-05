#include "BinaryTree.h"

void TestBinaryTree()
{
	char a[] = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, &i);
	printf("二叉树创建成功！");
	printf("\n");

	printf("结点个数:%d\n", BinaryTreeSize(root));
	printf("叶子结点个数:%d\n", BinaryTreeLeafSize(root));
	printf("第K=3层结点个数:%d\n", BinaryTreeLevelKSize(root, 3));

	//printf("C的位置为：" );
	//BinaryTreeFind(root, 'C');
	//printf("\n");

	printf("前序遍历：");
	BinaryTreePrevOrder(root);
	printf("\n");

	printf("中序遍历：");
	BinaryTreeInOrder(root);
	printf("\n");

	printf("后序遍历：");
	BinaryTreePostOrder(root);
	printf("\n");

	//printf("层次遍历：");
	//BinaryTreeLevelOrder(root);
	//printf("\n");

	//printf("判断是否为完全二叉树(true-是、false-否)：");
	//BinaryTreeComplete(root);
	//printf("\n");
}

int main()
{
	TestBinaryTree();
	system("pause");
	return 0;
}