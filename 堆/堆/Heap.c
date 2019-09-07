#include "Heap.h"

void HeapInit(Heap* hp, HPDataType* a, int n) //初始化堆
{
	hp->_a = malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n); //先保存hp->_a，再将申请的空间给予给a
	hp->_size = n;
	hp->_capacity = n;
	//构建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i) //n-1-1 从下往上，n-1为最后一个叶子节点，再-1除2可以找到该叶子结点的父节点
	{
		AdjustDown(hp->_a, hp->_size, i); 
	}
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType x = *p1;
	*p1 = *p2;
	*p2 = x;
}

void AdjustDown(HPDataType* a, size_t n, size_t parent) //向下调整，其父节点大于左右孩子
{
	size_t child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapDestory(Heap* hp) //释放
{
	if (hp->_a)
	{
		free(hp->_a);
		hp->_a = NULL;
		hp->_size = 0;
		hp->_capacity = 0;
	}
}

void AdjustUp(HPDataType*a, size_t  child)
{
	size_t parent =  (child - 1) / 2;
	while (child > 0)  //注意循环条件
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2; //循环条件不能为parent>=0 ,当child=0时，出现问题
		}
		else
		{
			break;
		}
	}
}

void HeapPush(Heap* hp, HPDataType x) //插入
{
	if (hp->_size == hp->_capacity) //判断空间是满
	{
		size_t newcapacity = hp->_capacity == 0 ? 2 : hp->_capacity * 2;
		hp->_a = (HPDataType*) realloc (hp->_a, sizeof(HPDataType)*newcapacity); //把旧的空间先给hp->_a
		hp->_capacity = newcapacity;
	} 
	hp->_a[hp->_size] = x;
	hp->_size++;
	AdjustUp(hp->_a, hp ->_size-1);
}


void HeapPop(Heap* hp) //删除
{
	assert(hp->_size > 0);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0); //从根开始往下调整
}

HPDataType HeapTop(Heap* hp) //根
{
	assert(hp->_size > 0);
	return hp->_a[0];
}

size_t HeapSize(Heap* hp) 
{
	return hp->_size;
}

bool HeapEmpty(Heap* hp)
{
	return hp->_size == 0;
}

void HeapSort(int* a, int n) // 堆排序
{
	//升序  建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i) //下标再减一
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void HeapPrint(Heap* hp) //打印
{
	for (size_t i = 0; i < hp->_size; ++i) 
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}