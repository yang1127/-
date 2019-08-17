#include "Queue.h"

void QueueInit(Queue* pq) //初始化
{
	assert(pq);
	pq->_front = NULL;
	pq->_tail = NULL;
}

void QueueDestroy(Queue* pq) //销毁
{
	QueueNode* cur = pq->_front;
	while (cur != NULL)  //所有链表节点释放掉
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next; //迭代
	}
	pq->_front = NULL;
	pq->_tail = NULL;
}

QueueNode* BuyQueueNode(QUDataType x) //置新节点
{
	QueueNode* node = ((QueueNode*)malloc(sizeof(QueueNode)));//新节点开辟空间
	node->_data = x;
	node->_next = NULL;
	return node;
}

void QueuePush(Queue* pq, QUDataType x) //入队:队尾入数据
{
	QueueNode* newnode = BuyQueueNode(x);
	if (pq->_tail == NULL) //开始定义tail为空
	{
		pq->_front = pq->_tail = newnode; //队里无数据时，队头队尾的值均为新节点
	}
	else
	{
		pq->_tail->_next = newnode;
		pq->_tail = newnode;  //队里有数据，直接队尾插入新节点
	}
}

void QueuePop(Queue* pq) //出队：对头出数据，删掉对头数据，先保存下一个数据
{
	assert(pq && pq->_front != NULL);

	QueueNode* next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;

	if (pq->_front == NULL) 
	{
		pq->_tail = NULL; //队头为空，将队尾的指针指向NULL，否则为野指针
	}
}

QUDataType QueueFront(Queue* pq) //取队头的数据
{
	assert(pq && pq->_front != NULL);
	return pq->_front->_data;
}

QUDataType QueueBack(Queue* pq) //取队尾的数据
{
	assert(pq && pq->_tail != NULL);
	return pq->_tail->_data;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL; //没有节点为空
	// return QueueSize(pq) == 0; //O(n)
}

int QueueSize(Queue* pq) 
{
	assert(pq);
	QueueNode* cur = pq->_front;
	size_t size = 0;
	while (cur != NULL)
	{
		++size;
		cur = cur->_next;
	}

	return size;
}
