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

void HeapInit(Heap* hp, HPDataType* a, int n); //��ʼ����
void Swap(HPDataType*p1, HPDataType*p2); //����
void AdjustUp(HPDataType*a, size_t  child); //���ϵ���
void AdjustDown(HPDataType*a, size_t n, size_t root); //���µ���
void HeapDestory(Heap* hp); //�ͷ�

void HeapPush(Heap* hp, HPDataType x); //����
void HeapPop(Heap* hp); //ɾ��

HPDataType HeapTop(Heap* hp);
size_t HeapSize(Heap* hp);
bool HeapEmpty(Heap* hp);

void HeapSort(int* a, int n); // ������
void HeapPrint(Heap* hp); //��ӡ

void TestHeap();
void TestHeap1();
