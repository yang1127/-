#include "SList.h"

void SListInit(SList* plt) //初始化
{
	assert(plt);
	plt->_head = NULL;
}

void SListDestroy(SList* plt) //销毁
{
	assert(plt);
	plt->_head = NULL;
	{
		SListNode * tmp;
		while (plt->_head)
		{
			tmp = plt->_head;  //先将plt->_head保存到临时变量中
			plt->_head = plt->_head->_next; //指向plt->_head的next再free掉临时变量中的plt->_head
			free(tmp);
		}
	}
}

void SListPushBack(SList* plt, SLTDataType x) //尾插
{
	assert(plt);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode)); //先开辟空间
	newnode->_data = x;
	newnode->_next = NULL;

	if (plt->_head == NULL) //两种情况：为空直接插入；不为空、找尾、再插入
	{
		plt->_head = newnode;
	}
	else
	{
		SListNode* cur = plt->_head;
		while (cur->_next != NULL) //找尾
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
	}
}

void SListPushFront(SList* plt, SLTDataType x) //头插
{
	assert(plt);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_next = plt->_head;
	plt->_head = newnode;
}

void SListPopBack(SList* plt) //尾删
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

void SListPopFront(SList* plt) //头删
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