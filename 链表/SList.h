#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

// ���� ����ͷ ��ѭ��
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

void SListInit(SList* plt); //��ʼ��
void SListDestroy(SList* plt); // ����

//SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plt, SLTDataType x); //β��
void SListPushFront(SList* plt, SLTDataType x); //ͷ��

void SListPopBack(SList* plt); //βɾ
void SListPopFront(SList* plt); //ͷɾ

SListNode* SlistFind(SList* plt, SLTDataType x); //����

void SListInsertAfter(SListNode* pos, SLTDataType x);// ��pos�ĺ�����в��� 
void SListEraseAfter(SListNode* pos); // ��pos�ĺ�����в���

void SListRemove(SList* plt, SLTDataType x); //�Ƴ�
void SListPrint(SList* plt); //��ӡ

void TestSList1();
void TestSList2();