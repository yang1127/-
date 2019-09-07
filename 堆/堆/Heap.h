#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n); //初始化堆
void Swap(HPDataType*p1, HPDataType*p2); //交换
void AdjustUp(HPDataType*a, size_t  child); //向上调整
void AdjustDown(HPDataType*a, size_t n, size_t root); //向下调整
void HeapDestory(Heap* hp); //释放

void HeapPush(Heap* hp, HPDataType x); //插入
void HeapPop(Heap* hp); //删除

HPDataType HeapTop(Heap* hp);
size_t HeapSize(Heap* hp);
bool HeapEmpty(Heap* hp);

void HeapSort(int* a, int n); // 堆排序
void HeapPrint(Heap* hp); //打印

void TestHeap();
void TestHeap1();
