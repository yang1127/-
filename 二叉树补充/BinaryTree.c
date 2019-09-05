#include "BinaryTree.h"
#include "Queue.h"

BTNode* BinaryTreeCreate(char* a, int* pi) //���磺ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
{
	if (a[*pi] == '#')
	{
		return NULL;
	}
	 
	BTNode* root = (BTNode*)malloc(sizeof(BTNode)); //Ŀ�ģ�ʡȥ����ָ���ʹ��
	
	root->_data = a[*pi]; //ǰ�������������������������
	++(*pi);
	root->_left = BinaryTreeCreate(a, pi);
	++(*pi);
	root->_right = BinaryTreeCreate(a, pi);

	return root;

}


void BinaryTreeDestory(BTNode* root) //����
{
	if (root == NULL)
		return;

	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
}

int BinaryTreeSize(BTNode* root) //������
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root) //Ҷ�ӽ�����
{
	if (root == NULL) 
		return 0;

	if (root->_left == NULL && root->_right == NULL) //ֻ�и����
		return 1;

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k) //��k�������
{
	//˼·���������Ĳ�m1��m2��m3��m4������Ĳ��������������m1�ĵ��Ĳ㣬��m2�ĵ�����
	//��m3�ĵڶ��㣬��m4�ĵ�һ�㣬�ٲ�����Ϸ�
	if (root == NULL)
		return 0;

	if (k == 1) //���k=1��ֻ�и����
		return 1;

	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
	
}

BTNode* BinaryTreeFind(BTNode* root, char x) //�ҵ�Ԫ��Ϊx�Ľ��,���ҷ���ָ��
{
	if (root == NULL)
		return NULL;

	if (root->_data == x) //�����ǡ��ΪҪ�ҵ�x
		return root; //������һ��

	BTNode* ltmp = BinaryTreeFind(root->_left, x); //���������ң����������ҵ�����ȥ��������
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

void BinaryTreePrevOrder(BTNode* root) //ǰ���������������
{
	if (root == NULL)
		return;
	
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}  

void BinaryTreeInOrder(BTNode* root) //����������󡢸�����
{
	if (root == NULL)
		return;

	BinaryTreeInOrder(root->_left);
	printf("%c ",root->_data );
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root) //����������ҡ��󡢸�
{
	if (root == NULL)
		return;

	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
    printf("%c ", root->_data);
}


void BinaryTreeLevelOrder(BTNode* root) // �ǵݹ������α���
{
	Queue q; //���ö��У��ڶ��д�ָ��
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q); //ȡ��ͷ����
		QueuePop(&q); //ֻ��ɾ�����е���

		printf("%c ", front->_data);
		if (front->_left != NULL)
			QueuePush(&q, front->_left);

		if (front->_right != NULL)
			QueuePush(&q, front->_right);
	}
}

bool BinaryTreeComplete(BTNode* root) // �ж϶������Ƿ�����ȫ������
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);

	while (!QueueEmpty(&q)) 
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL) //�����գ���Ч�����꣬
		{
			break;  
		}
		else  //���Ҷ���
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front != NULL) //��������ֵ��Ϊ�����жϲ�����ȫ������
		{
			//QueueDestory(&q);
			return false;
		}
	}
	return true;
}
		

