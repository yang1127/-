#include "SList.h"

void SListInit(SList* plt) //��ʼ��
{
	assert(plt);
	plt->_head = NULL;
}

void SListDestroy(SList* plt) //����
{
	assert(plt);
	plt->_head = NULL;
	{
		SListNode * tmp;
		while (plt->_head)
		{
			tmp = plt->_head;  //�Ƚ�plt->_head���浽��ʱ������
			plt->_head = plt->_head->_next; //ָ��plt->_head��next��free����ʱ�����е�plt->_head
			free(tmp);
		}
	}
}

void SListPushBack(SList* plt, SLTDataType x) //β��
{
	assert(plt);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode)); //�ȿ��ٿռ�
	newnode->_data = x;
	newnode->_next = NULL;

	if (plt->_head == NULL) //���������Ϊ��ֱ�Ӳ��룻��Ϊ�ա���β���ٲ���
	{
		plt->_head = newnode;
	}
	else
	{
		SListNode* cur = plt->_head;
		while (cur->_next != NULL) //��β
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
	}
}

void SListPushFront(SList* plt, SLTDataType x) //ͷ��
{
	assert(plt);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_next = plt->_head;
	plt->_head = newnode;
}

void SListPopBack(SList* plt) //βɾ
{
	assert(plt);
	SListNode* cur = plt->_head;
	if (cur == NULL)
	{
		return;
	}
	else if (cur->_next == NULL)
	{
		free(cur);
		plt->_head = NULL;
	}
	else
	{
		while (cur->_next->_next != NULL)
		{
			cur = cur->_next;
		}

		free(cur->_next);
		cur->_next = NULL;
	}
}

void SListPopFront(SList* plt) //ͷɾ
{
	assert(plt);
	if (plt->_head == NULL)
	{
		return;
	}
	else
	{
		SListNode* cur = plt->_head;
		plt->_head = cur->_next;
		free(cur);
		cur = NULL;
	}
}

SListNode* SlistFind(SList* plt, SLTDataType x)
{
	assert(plt);
	SListNode* cur = plt->_head;
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			return cur;
		}

		cur = cur->_next;
	}

	return NULL;
}

void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	newnode->_next = pos->_next;
	pos->_next = newnode;
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->_next == NULL)
	{
		return;
	}
	else
	{
		SListNode* next = pos->_next;
		pos->_next = next->_next;
		free(next);
		next = NULL;
	}
}

void SListRemove(SList* plt, SLTDataType x)
{
	assert(plt);

	SListNode* prev = NULL;
	SListNode* cur = plt->_head;
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			if (prev == NULL)
				plt->_head = cur->_next;
			else
				prev->_next = cur->_next;

			free(cur);
			cur = NULL;
			return;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
}

void SListPrint(SList* plt)
{
	assert(plt);

	SListNode* cur = plt->_head;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}