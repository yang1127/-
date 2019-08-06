#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

// ��ͷ˫��ѭ��������ɾ���ʵ��
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

void ListInit(List* plt); //��ʼ��
void ListDestory(List* plt); //����

ListNode* BuyListNode(LTDataType x);
void ListPushBack(List* plt, LTDataType x); //β��
void ListPopBack(List* plt); //βɾ

void ListPushFront(List* plt, LTDataType x); //ͷ��
void ListPopFront(List* plt); //ͷɾ

ListNode* ListFind(List* plt, LTDataType x); //��ѯ
void ListInsert(ListNode* pos, LTDataType x); //��pos��ǰ����в���
void ListErase(ListNode* pos); //ɾ��posλ�õĽڵ�

int ListSize(List* plt);
int ListEmpty(List* plt);
void ListRemove(List* plt, LTDataType x); //�Ƴ�
void ListPrint(List* plt); //��ӡ
void ListTest();//����