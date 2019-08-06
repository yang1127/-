#include "list.h"

void ListInit(List* plt) //初始化
{
	assert(plt);
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->_next = head;
	head->_prev = head;
	plt->_head = head;
} 

void ListDestory(List* plt) //释放
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

void ListPushBack(List* plt, LTDataType x) //尾插
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* tail = head->_prev;
	ListNode* newnode = BuyListNode(x);
	//head、tail、newnode三者之间进行链接
    tail->_next = newnode;
	newnode->_prev = tail;
    newnode->_next = head;
	head->_prev = newnode;

	//ListInsert(plt->_head, x);
}
void ListPopBack(List* plt) //尾删
{
	assert(plt);
	ListNode* head = plt->_head;
	assert(head->_next != head);
	ListNode* tail = head->_prev;
	ListNode* prevtail = tail->_prev;
	free(tail);
	//head、prevtail、tail
	head->_prev = prevtail;
	prevtail->_next = head;

	//ListErase(plt->_head->prev);
}

void ListPushFront(List* plt, LTDataType x) //头插
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* first = head->_next;
	ListNode* newnode = BuyListNode(x);
	//head、newnode、first三者之间经行链接
	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = first;
	first->_prev = newnode;

	//ListInsert(plt->_next, x);
}
void ListPopFront(List* plt) //头删
{
	assert(plt);
	ListNode* head = plt->_head;
	assert(head->_next != head);
	ListNode* first = head->_next;
	ListNode* second = first->_next; //nextnext表示second
	free(first);
	//head、first 、second
	head->_next = second;
	second->_prev = first;

	//ListErase(plt->_head->prev, x);
}

ListNode* ListFind(List* plt, LTDataType x) //查询
{
	assert(plt);
	ListNode* cur = plt->_head->_next; //第一个
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

void ListInsert(ListNode* pos, LTDataType x) //在pos的前面进行插入
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);
	//prev、newnode、pos三者之间经行链接
	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}

void ListErase(ListNode* pos) //删除pos位置的节点
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

int ListEmpty(List* plt) //空返回0，非空返回-1
{
	assert(plt);
	return plt->_head->_next == plt->_head ? 0 : -1;
}

void ListRemove(List* plt, LTDataType x) //移除
{
	assert(plt);
	ListNode* node = ListFind(plt, x);
	if (node)
		ListErase(node);
}

void ListPrint(List* plt) //打印
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
