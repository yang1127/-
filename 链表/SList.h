#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

// 单向 不带头 不循环
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType	_data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plt); //初始化
void SListDestroy(SList* plt); // 销毁

//SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plt, SLTDataType x); //尾插
void SListPushFront(SList* plt, SLTDataType x); //头插

void SListPopBack(SList* plt); //尾删
void SListPopFront(SList* plt); //头删

SListNode* SlistFind(SList* plt, SLTDataType x); //查找

void SListInsertAfter(SListNode* pos, SLTDataType x);// 在pos的后面进行插入 
void SListEraseAfter(SListNode* pos); // 在pos的后面进行插入

void SListRemove(SList* plt, SLTDataType x); //移除
void SListPrint(SList* plt); //打印

void TestSList1();
void TestSList2();