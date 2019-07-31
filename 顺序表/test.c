#include "seqlist.h"

void SeqListtest()
{
	SeqList psl;
	SeqListInit(&psl, 10);
	SeqListPushBack(&psl, 1);
	SeqListPushBack(&psl, 2);
	SeqListPushBack(&psl, 3);
	SeqListPushBack(&psl, 4);
	SeqListPushBack(&psl, 5);
	SeqListPushBack(&psl, 6);
	SeqListPushBack(&psl, 7);
	SeqListPushBack(&psl, 8);
	SeqListPushBack(&psl, 9);
	SeqListPushFront(&psl, 0);

	SeqListInsert(&psl, 1, 16);
	SeqListErase(&psl, 2);
	SeqListRemove(&psl, 16);
	SeqListModify(&psl, 3, 10);

	SeqListBubbleSort(&psl);
	printf("%d\n", SeqListBinaryFind(&psl, 6));

	SeqListPrint(&psl);
	SeqListDestory(&psl);

	for (size_t i = 0; i < SeqListSize(&psl); ++i)
	{
		printf("%d ", SLSeqListAt(&psl, i));
	}
	printf("\n");

}

int main()
{
	SeqListtest();
	system("pause");
	return 0;
}
