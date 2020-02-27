#include "sort.h"

void TestSort()
{
	int a[] = {1, 5, 3, 8, 7, 6};
	printf("ֱ�Ӳ�������");
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));

	printf("ϣ������");
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));


	printf("ѡ������");
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));

	printf("������");
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));

	printf("ð������");
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));

	printf("��������1��");
	QuickSort1(a, 0, sizeof(a) / sizeof(int)-1);
	PrintArry(a, sizeof(a) / sizeof(int));

	printf("��������2��");
	QuickSort2(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArry(a, sizeof(a) / sizeof(int));

	printf("��������3��");
	QuickSort3(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArry(a, sizeof(a) / sizeof(int));

	printf("��������ǵݹ飺");
	QuickSortNonR(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArry(a, sizeof(a) / sizeof(int));

	printf("�鲢����");
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));
  
    printf("�鲢�ǵݹ�����");
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));

	printf("��������");
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));
}


int main()
{
	TestSort();
	system("pause");
	
	return 0;
}
