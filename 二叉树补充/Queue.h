#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>
#include "BinaryTree.h"

typedef BTNode* QUDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front; // ��ͷ
	QueueNode* _tail; // ��β
}Queue;

void QueueInit(Queue* pq); //��ʼ��
void QueueDestroy(Queue* pq); //����

QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* pq, QUDataType x); //���
void QueuePop(Queue* pq); //����

QUDataType QueueFront(Queue* pq); //ȡ��ͷ������
QUDataType QueueBack(Queue* pq); //ȡ��β������

bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
