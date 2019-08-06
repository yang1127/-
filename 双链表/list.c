#include "list.h"

void ListInit(List* plt) //��ʼ��
{
	assert(plt);
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->_next = head;
	head->_prev = head;
	plt->_head = head;
} 

void ListDestory(List* plt) //�ͷ�
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* cur = head->_next;
	while (cur != plt->_head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(plt->_head);
	plt->_head = NULL;
}

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*) malloc (sizeof(ListNode));
	newnode->_next = NULL;
	newnode->_prev = NULL;
	newnode->_data = x;

	return newnode;
}

void ListPushBack(List* plt, LTDataType x) //β��
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* tail = head->_prev;
	ListNode* newnode = BuyListNode(x);
	//head��tail��newnode����֮���������
    tail->_next = newnode;
	newnode->_prev = tail;
    newnode->_next = head;
	head->_prev = newnode;

	//ListInsert(plt->_head, x);
}
void ListPopBack(List* plt) //βɾ
{
	assert(plt);
	ListNode* head = plt->_head;
	assert(head->_next != head);
	ListNode* tail = head->_prev;
	ListNode* prevtail = tail->_prev;
	free(tail);
	//head��prevtail��tail
	head->_prev = prevtail;
	prevtail->_next = head;

	//ListErase(plt->_head->prev);
}

void ListPushFront(List* plt, LTDataType x) //ͷ��
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* first = head->_next;
	ListNode* newnode = BuyListNode(x);
	//head��newnode��first����֮�侭������
	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = first;
	first->_prev = newnode;

	//ListInsert(plt->_next, x);
}
void ListPopFront(List* plt) //ͷɾ
{
	assert(plt);
	ListNode* head = plt->_head;
	assert(head->_next != head);
	ListNode* first = head->_next;
	ListNode* second = first->_next; //nextnext��ʾsecond
	free(first);
	//head��first ��second
	head->_next = second;
	second->_prev = first;

	//ListErase(plt->_head->prev, x);
}

ListNode* ListFind(List* plt, LTDataType x) //��ѯ
{
	assert(plt);
	ListNode* cur = plt->_head->_next; //��һ��
	while (cur != plt->_head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x) //��pos��ǰ����в���
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);
	//prev��newnode��pos����֮�侭������
	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}

void ListErase(ListNode* pos) //ɾ��posλ�õĽڵ�
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	prev->_next = next;
	next->_next = prev;
	free(pos);
}

int ListSize(List* plt)
{
	assert(plt);
	int size = 0;
	ListNode* cur = plt->_head->_next;
	while (cur != plt->_head)
	{
		++size;
		cur = cur->_next;
	}
	return size;
}

int ListEmpty(List* plt) //�շ���0���ǿշ���-1
{
	assert(plt);
	return plt->_head->_next == plt->_head ? 0 : -1;
}

void ListRemove(List* plt, LTDataType x) //�Ƴ�
{
	assert(plt);
	ListNode* node = ListFind(plt, x);
	if (node)
		ListErase(node);
}

void ListPrint(List* plt) //��ӡ
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* cur = head->_next;
	while (cur != plt->_head)
	{
		printf("%d<-> ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
