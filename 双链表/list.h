#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

// 带头双向循环链表增删查改实现
typedef int LTDataType;

typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

typedef struct List
{
	ListNode* _head;
}List;

void ListInit(List* plt); //初始化
void ListDestory(List* plt); //销毁

ListNode* BuyListNode(LTDataType x);
void ListPushBack(List* plt, LTDataType x); //尾插
void ListPopBack(List* plt); //尾删

void ListPushFront(List* plt, LTDataType x); //头插
void ListPopFront(List* plt); //头删

ListNode* ListFind(List* plt, LTDataType x); //查询
void ListInsert(ListNode* pos, LTDataType x); //在pos的前面进行插入
void ListErase(ListNode* pos); //删除pos位置的节点

int ListSize(List* plt);
int ListEmpty(List* plt);
void ListRemove(List* plt, LTDataType x); //移除
void ListPrint(List* plt); //打印
void ListTest();//测试