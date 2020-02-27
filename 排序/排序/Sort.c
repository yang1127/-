#include "sort.h"
#include "Stack.h"

//插入排序
void InsertSort(int* a, int n) //直接插入排序
{
	//思路：在已排好的序列中插入数据，大于的数往后移动覆盖，插入的数要大于前一个或者小于后一个（插入a[0]不用比较前一个）
	//插入的数据的位置为a[0]-a[n-1],最多比较到n-2的位置
	//时间 O(n*n):最好O(n)、最坏O(n*n)， 空间 O(1) 稳定

	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1]; //要插入的数
		while (end >= 0) //=0 往原序列的头插入
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end]; //覆盖数
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;  //前面已排好序，直接插入最后一个位置
	}
}

void ShellSort(int* a, int n)  //哈希排序
{
	//思路：设置一个gap，gap的数值代表数据之间间隔gap，然后预排序，预排序完成后基本接近于排序
	//再进行一次插入排序
	//时间 O(n*1.3-n*2) 不稳定
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1; //设置间距，+1确保进行插入排序 gap = 1 表示直接插入排序

		for (int i = 0; i < n - gap; ++i) //当i走到n-1-gap进行最后比较数据交换
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end = end - gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void Swap(int* p1, int* p2)
{
	int x = *p1;
	*p1 = *p2;
	*p2 = x;
}

//选择排序
void SelectSort(int* a, int n) //选择排序
{
	//思路：每一次从待排序的数据元素中选出最小元素放到起始位置，选取最大元素放大序列最后，直到全部待排序的数据元素排完。
    //若选取的元素不是这组元素中的第一个和最后一个元素，则将它们与这组元素中的第一个和最后一个元素交换

	int begin = 0;
	int end = n - 1;
	int max_index, min_index; //index->指针
	max_index = min_index = 0;
	while (begin <= end)
	{
		for (int i = begin + 1; i < end; ++i)
		{
			if (a[i] > a[max_index])
				max_index = i; //将大的元素地址给与max，方可经行下一轮比较
			if (a[i] < a[min_index])
				min_index = i;

			Swap(&a[i], &a[max_index]); //&
			Swap(&a[i], &a[min_index]); //&
		}
		--end;
		++begin;
	}
}

void AdujustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1]) //选择小的孩子
			++child;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]); //交换数据
			parent = child; 
			child = parent * 2 + 1; //迭代
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n) //堆排序
{
	//思路：排升序要建大堆，排降序建小堆
	// 时间：O(N)、空间：O(1)、不稳定
	 
	for (int i = (n - 2) / 2; i >= 0; --i) //建堆
	{
		AdujustDown(a, n, i);
	}

	int end = n - 1; //堆排序
	while (end > 0)
	{
		Swap(&a[0], &a[end]); //*已建立大堆，将a[0]与a[end]交换，再经行堆调整
		AdujustDown(a, end, 0);
		--end;
	}
}

//交换排序
void BubbleSort(int* a, int n) //冒泡排序
{
	//思路：将较大的向序列的尾部移动，较小的向序列的前部移动
	// 时间复杂度：O(N^2) 、空间复杂度：O(1)、稳定性：稳定
	int end = n - 1;
	while (end > 0)
	{
		for (int i = 0; i < end; ++i)
		{
			if (a[i] > a[i + 1])
				Swap(&a[i], &a[i + 1]);
		}
		--end;
	}
}

int OneSort1(int* a, int left, int right)
{
	int key = a[right];
	int key_index = right;
	
	while (left < right)
	{
		while (left < right && a[left] <= key) //a[left] <= key,进入循环++，大于时出来与右指针所找的数经行交换
			++left;
		while (left < right && a[right] >= key)
			--right;

	    Swap(&a[left], &a[right]);

	    while (left > right) //防止溢出
		    ++left;
	    while (left < right)
		    --right;
	}

	Swap(&a[left], &a[key_index]); //left = right时，选取右key，则a[left] 与 key所指的数值交换
	
	return left;
}

void QuickSort1(int* a, int left, int right) //快速排序
{
	//思路：法一：左右指针法，在最左或最右选取一个key
	//左指针向左找大于key所对应的数，右指针找小于key所对应的数值，找到左右指针对应的数值交换
	//右边作key，先走左，后走右；左边为key，先走右，后走左；指针相遇时，left与右key交换、right与左key交换

	if (left > right)  //没有导致溢出
		return;

	int key_index = OneSort1(a, left, right); //区间分为三部分：[left, key_index-1] key [key_index + 1, right]
	QuickSort1(a, left, key_index-1);
	QuickSort1(a, key_index + 1, right);
}

//快排 时间：O(nlogn)  最坏情况：有顺序的情况下O(n^2）
//优化：<1>随机取key <2> 三数取中 <3>小区间插入

//三数取中
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[right])
	{
		if (a[right] < a[mid])
			return right;
		else if (a[left] < a[mid])
			return mid;
		else
			return left;
	}
	else
	{
		if (a[left] < a[mid])
			return left;
		else if (a[right] < a[mid])
			return mid;
		else
			return right;
	}
}


int OneSort2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);  //优
	Swap(&a[mid], &a[left]);                //化

	int key = a[right];  //找右key

	while (left < right)
	{
		while (left < right && a[left] <= key) //a[left] <= key,进入循环++
		{
			++left;
		}
		a[right] = a[left];

		while (left < right && a[right] >= key)
		{
		    --right;
		}
		a[left] = a[right];
	}
	a[left] = key; //指针相遇时

	return left;
}

void QuickSort2(int* a, int left, int right) //快速排序
{
	//思路：法二：挖坑法，在最左或最右选取一个key，取掉该位置数值，设置坑
	//左指针向左找大于key所对应的数，找到的数覆盖坑，自己的位置为新坑，右指针找小于key所对应的数值，同理
	//右边作key，先走左，后走右；左边为key，先走右，后走左；指针相遇时，left坑位置放入右key、right坑位置放左key

	if (left > right)  //没有导致溢出
		return;

	int key_index = OneSort2(a, left, right); //区间分为三部分：[left, key_index-1] key [key_index + 1, right]
	QuickSort2(a, left, key_index - 1);
	QuickSort2(a, key_index + 1, right);
}

int OneSort3(int* a, int left, int right)
{
	int key = a[right];
	int cur = left;
	int prev = left - 1;
	while (cur < right)
	{
		if (a[cur] < a[right] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;  //a[cur] > a[right] 继续走
	}
	++prev;
	Swap(&a[prev], &a[right]);
	return prev;
}

void QuickSort3(int* a, int left, int right) //快速排序
{
	//思路：法三：前后指针法，在右设置key，在左设两个指针一前prev 一后cur
	//cur指针从left开始，遇到比key大的就过滤掉，比key小的，就停下来，prev++
	//判断prev和cur是否相等，如果不相等，就将两个值进行交换
	//prev:（1）cur没有找到比key大的数，++cur，++prev，两相差一个位
	//（2）cur找到比key大的数，cur与prev相互交换，cur与prev之间差的位为大于key的数
	//最后一趟到达key位置，prev与key对应的数交换后比key小的，都留在了key的左边，比key大的都在key的右边

	if (left > right)  //没有导致溢出
		return;

	int key_index = OneSort3(a, left, right); 
}

void QuickSortNonR(int* a, int left, int right) //非递归
{
	Stack st;
	StackInit(&st);
	StackPush(&st, left);
	StackPush(&st, right);

	while (!StackEmpty(&st))  //栈不为空
	{
		int end = StackTop(&st);
		StackPop(&st);
		int begin = StackTop(&st);
		StackPop(&st);

		int key_index = OneSort3(a, begin, end); //区间分为三部分：[left, key_index-1] key [key_index + 1, right]

		if (begin < key_index - 1) 
		{
			StackPush(&st, begin);
			StackPush(&st, key_index - 1);
		}

		if (key_index + 1 < end)
		{
			StackPush(&st, key_index + 1);
            StackPush(&st, end);
		}
	}
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	//分解
	if (left == right) //子问题只左右两个数
		return;
	int mid = left + (right - left) / 2;
	_MergeSort(a, left, mid, tmp);  //区间划分[left, mid] 、[mid+1, right]
	_MergeSort(a, mid + 1, right, tmp);

	//合并
	//左右之间有序，归并
	int begin1 = left; int end1 = mid;
	int begin2 = mid + 1; int end2 = right;
	int  i = left; //tmp

	//begin1、end1、begin2、end2 超出跳出
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	memcpy(a + left, tmp + left, sizeof(int)*(i - left)); //原、目标、大小（right-left+1）但针对每个小区间

}

void MergeSort(int* a, int n) //归并排序
{
	//时间复杂度：O（nlogn）、空间复杂度：O（n）、稳定性：稳定
	//思路：分治算法：先分解再合并，递归的解各个子问题,每个子问题又继续递归调用自己，直到"left<right"这一条件不满足时
	//即"left==right"时，此时只有一个元素，显然是有序的，这样再进行下一步合并。

	int* tmp = (int*)malloc(sizeof(int)*n); //合并时，先把数放到tmp数组中，经排序后再覆盖到原数组，直到最后一趟完成即排序完成
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

void MergeSortNonR(int* a, int n) //非递归 归并排序 时间复杂度： O（nlogn）
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	
	int gap = 1; //每次一个一个归并
	while (gap <= n) //设置每次归并的大小
	{
		for (int begin = 0; begin < n; begin += 2 * gap)  //主要去画图
		{
			//[begin, begin+gap-1] [begin+gap，begin+2*gap -1]  控制好闭区间、开区间
			int begin1 = begin, end1 = begin + gap - 1;
			if (end1 >= n - 1) //边界
			{
				end1 = n - 1;
			}

			int begin2 = begin + gap, end2 = begin + 2 * gap - 1;
			if (end2 >= n - 1)
			{
				end2 = n - 1;
			}

			int  i = begin1; //tmp

			//begin1、end1、begin2、end2 超出跳出
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[i++] = a[begin1++];
				}
				else
				{
					tmp[i++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[i++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[i++] = a[begin2++];
			}
		}
		memcpy(a, tmp, sizeof(int)*n);
		gap *= 2;
	}
	
	free(tmp);
}

void CountSort(int* a, int n)
{
	//思路：统计相同元素出现次数，根据统计的结果将序列回收到原来的序列中
	int max = a[0], min = a[0];
	for (int i = 0; i < n; ++i) //找数组中的max、min
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	int range = max - min + 1; //开辟新数组的大小
	int* counta = (int*)malloc(sizeof(int)*(max - min)); 
	memset(counta, 0, sizeof(int)*range);

	//统计次数
	for (int i = 0; i < n; ++i)
	{
		counta[a[i] - min]++;
	}

	//排序
	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		while (counta[i]--)
		{
			a[j++] = i + min;
		}
	}
}

void PrintArry(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}