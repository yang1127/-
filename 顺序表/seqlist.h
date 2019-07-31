#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType * array; //指向动态开辟的数组
	size_t size; //有效数据的个数
	size_t capacity; //容量空间大小
}SeqList;

void SeqListInit(SeqList* psl, size_t capacity); //初始化
void SeqListDestory(SeqList* psl); //销毁

void CheckCapacity(SeqList* psl); //增容
void SeqListPushBack(SeqList* psl, SLDataType x); //尾插
void SeqListPopBack(SeqList* psl); //尾删

void SeqListPushFront(SeqList* psl, SLDataType x); //头插
void SeqListPopFront(SeqList* psl); //头删

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x); //某位置插入
void SeqListErase(SeqList* psl, size_t pos); //某位置删除
void SeqListPrint(SeqList* psl); //打印

size_t SeqListSize(SeqList* psl); //通过函数去控制，而不通过结构体
size_t SeqListFind(SeqList* psl, SLDataType x); //查询
SLDataType SLSeqListAt(SeqList* psl, size_t pos);//访问pos位置的值

void SeqListRemove(SeqList* psl, SLDataType x); //移除
void SeqListModify(SeqList* psl, size_t pos, SLDataType x); //修改
void SeqListBubbleSort(SeqList* psl); //冒泡排序
int SeqListBinaryFind(SeqList* psl, SLDataType x); // 二分查找 要求：时间复杂度：O(N) 空间复杂度 O(1)

void SeqListtest();