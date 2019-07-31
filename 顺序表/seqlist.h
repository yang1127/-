#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType * array; //ָ��̬���ٵ�����
	size_t size; //��Ч���ݵĸ���
	size_t capacity; //�����ռ��С
}SeqList;

void SeqListInit(SeqList* psl, size_t capacity); //��ʼ��
void SeqListDestory(SeqList* psl); //����

void CheckCapacity(SeqList* psl); //����
void SeqListPushBack(SeqList* psl, SLDataType x); //β��
void SeqListPopBack(SeqList* psl); //βɾ

void SeqListPushFront(SeqList* psl, SLDataType x); //ͷ��
void SeqListPopFront(SeqList* psl); //ͷɾ

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x); //ĳλ�ò���
void SeqListErase(SeqList* psl, size_t pos); //ĳλ��ɾ��
void SeqListPrint(SeqList* psl); //��ӡ

size_t SeqListSize(SeqList* psl); //ͨ������ȥ���ƣ�����ͨ���ṹ��
size_t SeqListFind(SeqList* psl, SLDataType x); //��ѯ
SLDataType SLSeqListAt(SeqList* psl, size_t pos);//����posλ�õ�ֵ

void SeqListRemove(SeqList* psl, SLDataType x); //�Ƴ�
void SeqListModify(SeqList* psl, size_t pos, SLDataType x); //�޸�
void SeqListBubbleSort(SeqList* psl); //ð������
int SeqListBinaryFind(SeqList* psl, SLDataType x); // ���ֲ��� Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)

void SeqListtest();