#include "sort.h"

void TestSort()
{
	int a[] = {1, 5, 3, 8, 7, 6};
	printf("÷±Ω”≤Â»Î≈≈–Ú£∫");
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));

	printf("œ£∂˚≈≈–Ú£∫");
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));


	printf("—°‘Ò≈≈–Ú£∫");
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));

	printf("∂—≈≈–Ú£∫");
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));

	printf("√∞≈›≈≈–Ú£∫");
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));

	printf("øÏÀŸ≈≈–Ú1£∫");
	QuickSort1(a, 0, sizeof(a) / sizeof(int)-1);
	PrintArry(a, sizeof(a) / sizeof(int));

	printf("øÏÀŸ≈≈–Ú2£∫");
	QuickSort2(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArry(a, sizeof(a) / sizeof(int));

	printf("øÏÀŸ≈≈–Ú3£∫");
	QuickSort3(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArry(a, sizeof(a) / sizeof(int));

	printf("øÏÀŸ≈≈–Ú∑«µ›πÈ£∫");
	QuickSortNonR(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArry(a, sizeof(a) / sizeof(int));

	printf("πÈ≤¢≈≈–Ú£∫");
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));
  
    printf("πÈ≤¢∑«µ›πÈ≈≈–Ú£∫");
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));

	printf("º∆ ˝≈≈–Ú£∫");
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));
}


int main()
{
	TestSort();
	system("pause");
	
	return 0;
}
