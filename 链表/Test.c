#include "SList.h"

void TestSList1()
{
	SList lt;
	SListInit(&lt);
	SListPushBack(&lt, 1);
	SListPushBack(&lt, 2);
	SListPushBack(&lt, 3);
	SListPushBack(&lt, 4);
	SListPushFront(&lt, 0);
	SListPrint(&lt);

	SListPopBack(&lt);
	SListPopBack(&lt);
	SListPopBack(&lt);
	SListPrint(&lt);

	SListPopFront(&lt);
	SListPopFront(&lt);
	SListPrint(&lt);
}

void TestSList2()
{
	SList lt;
	SListInit(&lt);
	SListPushBack(&lt, 1);
	SListPushBack(&lt, 2);
	SListPushBack(&lt, 3);
	SListPushBack(&lt, 2);
	SListPushBack(&lt, 4);
	SListPushBack(&lt, 2);
	SListPrint(&lt);

	SListNode* pos = SlistFind(&lt, 3);
	SListInsertAfter(pos, 30);
	SListPrint(&lt);

	SListEraseAfter(pos);
	SListPrint(&lt);

	SListRemove(&lt, 2);
	SListPrint(&lt);
}

int main()
{
	TestSList1();
	TestSList2();
	system("pause");
	return 0;
}