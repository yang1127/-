#include "BinaryTree.h"
#include "Queue.h"

BTNode* BinaryTreeCreate(char* a, int* pi) //例如：通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
{
	if (a[*pi] == '#')
	{
		return NULL;
	}
	 
	BTNode* root = (BTNode*)malloc(sizeof(BTNode)); //目的：省去二级指针的使用
	
	root->_data = a[*pi]; //前序遍历：根、左子树、右子树
	++(*pi);
	root->_left = BinaryTreeCreate(a, pi);
	++(*pi);
	root->_right = BinaryTreeCreate(a, pi);

	return root;

}


void BinaryTreeDestory(BTNode* root) //销毁
{
	if (root == NULL)
		return;

	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
}

int BinaryTreeSize(BTNode* root) //结点个数
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root) //叶子结点个数
{
	if (root == NULL) 
		return 0;

	if (root->_left == NULL && root->_right == NULL) //只有根结点
		return 1;

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k) //第k层结点个数
{
	//思路：假如有四层m1、m2、m3、m4，求第四层结点个数即：求以m1的第四层，以m2的第三层
	//以m3的第二层，以m4的第一层，再层层往上返
	if (root == NULL)
		return 0;

	if (k == 1) //如果k=1即只有根结点
		return 1;

	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
	
}

BTNode* BinaryTreeFind(BTNode* root, char x) //找到元素为x的结点,并且返回指针
{
	if (root == NULL)
		return NULL;

	if (root->_data == x) //根结点恰好为要找的x
		return root; //返回上一层

	BTNode* ltmp = BinaryTreeFind(root->_left, x); //在左子树找，若左子树找到不再去右子树找
	if (ltmp != NULL)
	{
		return ltmp;
	}

	BTNode* rtmp = BinaryTreeFind(root->_right, x);
	if (rtmp != NULL)
	{
		return rtmp;
	}

	return NULL;
}

void BinaryTreePrevOrder(BTNode* root) //前序遍历：根、左、右
{
	if (root == NULL)
		return;
	
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}  

void BinaryTreeInOrder(BTNode* root) //中序遍历：左、根、右
{
	if (root == NULL)
		return;

	BinaryTreeInOrder(root->_left);
	printf("%c ",root->_data );
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root) //后序遍历：右、左、根
{
	if (root == NULL)
		return;

	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
    printf("%c ", root->_data);
}


void BinaryTreeLevelOrder(BTNode* root) // 非递归遍历层次遍历
{
	Queue q; //调用队列，在队列存指针
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q); //取队头数据
		QueuePop(&q); //只是删掉队列的数

		printf("%c ", front->_data);
		if (front->_left != NULL)
			QueuePush(&q, front->_left);

		if (front->_right != NULL)
			QueuePush(&q, front->_right);
	}
}

bool BinaryTreeComplete(BTNode* root) // 判断二叉树是否是完全二叉树
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);

	while (!QueueEmpty(&q)) 
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL) //出到空，有效结点出完，
		{
			break;  
		}
		else  //左右都入
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front != NULL) //带进出的值不为空则判断不是完全二叉树
		{
			//QueueDestory(&q);
			return false;
		}
	}
	return true;
}
		

