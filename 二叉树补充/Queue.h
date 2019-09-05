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
	QueueNode* _front; // 队头
	QueueNode* _tail; // 队尾
}Queue;

void QueueInit(Queue* pq); //初始化
void QueueDestroy(Queue* pq); //销毁

QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* pq, QUDataType x); //入队
void QueuePop(Queue* pq); //出队

QUDataType QueueFront(Queue* pq); //取队头的数据
QUDataType QueueBack(Queue* pq); //取队尾的数据

bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
