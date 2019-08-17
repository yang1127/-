#include "Queue.h"

void QueueInit(Queue* pq) //��ʼ��
{
	assert(pq);
	pq->_front = NULL;
	pq->_tail = NULL;
}

void QueueDestroy(Queue* pq) //����
{
	QueueNode* cur = pq->_front;
	while (cur != NULL)  //��������ڵ��ͷŵ�
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next; //����
	}
	pq->_front = NULL;
	pq->_tail = NULL;
}

QueueNode* BuyQueueNode(QUDataType x) //���½ڵ�
{
	QueueNode* node = ((QueueNode*)malloc(sizeof(QueueNode)));//�½ڵ㿪�ٿռ�
	node->_data = x;
	node->_next = NULL;
	return node;
}

void QueuePush(Queue* pq, QUDataType x) //���:��β������
{
	QueueNode* newnode = BuyQueueNode(x);
	if (pq->_tail == NULL) //��ʼ����tailΪ��
	{
		pq->_front = pq->_tail = newnode; //����������ʱ����ͷ��β��ֵ��Ϊ�½ڵ�
	}
	else
	{
		pq->_tail->_next = newnode;
		pq->_tail = newnode;  //���������ݣ�ֱ�Ӷ�β�����½ڵ�
	}
}

void QueuePop(Queue* pq) //���ӣ���ͷ�����ݣ�ɾ����ͷ���ݣ��ȱ�����һ������
{
	assert(pq && pq->_front != NULL);

	QueueNode* next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;

	if (pq->_front == NULL) 
	{
		pq->_tail = NULL; //��ͷΪ�գ�����β��ָ��ָ��NULL������ΪҰָ��
	}
}

QUDataType QueueFront(Queue* pq) //ȡ��ͷ������
{
	assert(pq && pq->_front != NULL);
	return pq->_front->_data;
}

QUDataType QueueBack(Queue* pq) //ȡ��β������
{
	assert(pq && pq->_tail != NULL);
	return pq->_tail->_data;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL; //û�нڵ�Ϊ��
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
