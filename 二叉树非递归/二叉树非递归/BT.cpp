#include "BT.h"


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

void BinaryTreePrevOrder(BTNode* root) //前序遍历：根、左、右
{
	if (root == NULL)
		return;

	cout << root->_data;
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

//非递归前序
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BTNode* p = root;
	stack<BTNode*> s;
	while (!s.empty() || p)
	{
		//边遍历边打印，并存入栈中
		while (p)
		{
			cout << p->_data;
			s.push(p);
			p = p->_left;
		}
		//当p为空时，说明根和左子树都遍历完了，该进入右子树了
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->_right;
		}
	}
}

void BinaryTreeInOrder(BTNode* root) //中序遍历：左、根、右
{
	if (root == NULL)
		return;

	BinaryTreeInOrder(root->_left);
	cout << root->_data;
	BinaryTreeInOrder(root->_right);
}

//非递归中序
void BinaryTreeInOrder(BTNode* root)
{
	//空树
	if (root == NULL)
		return;
	//树非空
	BTNode* p = root;
	stack<BTNode*> s;
	while (!s.empty() || p)
	{
		//一直遍历到左子树最下边，边遍历边保存根节点到栈中
		while (p)
		{
			s.push(p);
			p = p->_left;
		}
		//当p为空时，说明已经到达左子树最下边，这时需要出栈了
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			cout << p->_data;
			//进入右子树，开始新的一轮左子树遍历(这是递归的自我实现)
			p = p->_right;
		}
	}
}

void BinaryTreePostOrder(BTNode* root) //后序遍历：右、左、根
{
	if (root == NULL)
		return;

	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	cout << root->_data;
}

//非递归后序
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	stack<BTNode*> s;
	
	BTNode* pCur, *pLastVisit;//pCur:当前访问节点，pLastVisit:上次访问节点

	pCur = root;
	pLastVisit = NULL;
	
	while (pCur)//先把pCur移动到左子树最下边
	{
		s.push(pCur);
		pCur = pCur->_left;
	}
	while (!s.empty())
	{
		//走到这里，pCur为空，并已经遍历到左子树底端
		pCur = s.top();
		s.pop();

		//一个根节点被访问的前提是：无右子树或右子树已被访问过
		if (pCur->_right == NULL || pCur->_right== pLastVisit)
		{
			cout << pCur->_data;
			pLastVisit = pCur;//修改最近被访问的节点
		}
		else //else if (pCur->_left == pLastVisit)//若左子树刚被访问过，则需先进入右子树、根节点需再次入栈
		{
			s.push(pCur);//根节点再次入栈
			pCur = pCur->_right;//进入右子树，且肯定右子树一定不为空

			while (pCur)
			{
				s.push(pCur);
				pCur = pCur->_left;
			}
		}
	}
}