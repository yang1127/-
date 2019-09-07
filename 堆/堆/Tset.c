#include "Heap.h"

void TestHeap() 
{
	int a[] = { 7, 5 , 2, 0, 6, 8, 3, 9, 1 };
	Heap hp;
	HeapInit(&hp,  a, sizeof(a) / sizeof(int));
	HeapPrint(&hp);

	HeapPush(&hp, 12);
	HeapPush(&hp, -1);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);
	printf("%d\n", HeapTop(&hp));
	HeapTop(&hp);
	HeapPrint(&hp);
}

void TestHeap1() 
{
	int a[] = { 7, 5 , 2, 0, 6, 8, 3, 9, 1 };
	HeapSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	//TestHeap();
	TestHeap1();
	system("pause");
	return 0;
}
