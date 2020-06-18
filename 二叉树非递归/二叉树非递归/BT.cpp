#include "BT.h"


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

void BinaryTreePrevOrder(BTNode* root) //ǰ���������������
{
	if (root == NULL)
		return;

	cout << root->_data;
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

//�ǵݹ�ǰ��
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BTNode* p = root;
	stack<BTNode*> s;
	while (!s.empty() || p)
	{
		//�߱����ߴ�ӡ��������ջ��
		while (p)
		{
			cout << p->_data;
			s.push(p);
			p = p->_left;
		}
		//��pΪ��ʱ��˵���������������������ˣ��ý�����������
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->_right;
		}
	}
}

void BinaryTreeInOrder(BTNode* root) //����������󡢸�����
{
	if (root == NULL)
		return;

	BinaryTreeInOrder(root->_left);
	cout << root->_data;
	BinaryTreeInOrder(root->_right);
}

//�ǵݹ�����
void BinaryTreeInOrder(BTNode* root)
{
	//����
	if (root == NULL)
		return;
	//���ǿ�
	BTNode* p = root;
	stack<BTNode*> s;
	while (!s.empty() || p)
	{
		//һֱ���������������±ߣ��߱����߱�����ڵ㵽ջ��
		while (p)
		{
			s.push(p);
			p = p->_left;
		}
		//��pΪ��ʱ��˵���Ѿ��������������±ߣ���ʱ��Ҫ��ջ��
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			cout << p->_data;
			//��������������ʼ�µ�һ������������(���ǵݹ������ʵ��)
			p = p->_right;
		}
	}
}

void BinaryTreePostOrder(BTNode* root) //����������ҡ��󡢸�
{
	if (root == NULL)
		return;

	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	cout << root->_data;
}

//�ǵݹ����
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	stack<BTNode*> s;
	
	BTNode* pCur, *pLastVisit;//pCur:��ǰ���ʽڵ㣬pLastVisit:�ϴη��ʽڵ�

	pCur = root;
	pLastVisit = NULL;
	
	while (pCur)//�Ȱ�pCur�ƶ������������±�
	{
		s.push(pCur);
		pCur = pCur->_left;
	}
	while (!s.empty())
	{
		//�ߵ����pCurΪ�գ����Ѿ��������������׶�
		pCur = s.top();
		s.pop();

		//һ�����ڵ㱻���ʵ�ǰ���ǣ������������������ѱ����ʹ�
		if (pCur->_right == NULL || pCur->_right== pLastVisit)
		{
			cout << pCur->_data;
			pLastVisit = pCur;//�޸���������ʵĽڵ�
		}
		else //else if (pCur->_left == pLastVisit)//���������ձ����ʹ��������Ƚ��������������ڵ����ٴ���ջ
		{
			s.push(pCur);//���ڵ��ٴ���ջ
			pCur = pCur->_right;//�������������ҿ϶�������һ����Ϊ��

			while (pCur)
			{
				s.push(pCur);
				pCur = pCur->_left;
			}
		}
	}
}