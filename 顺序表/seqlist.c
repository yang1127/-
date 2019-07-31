#include "seqlist.h"

void SeqListInit(SeqList* psl, size_t capacity) //初始化
{
	assert(psl);
	psl->capacity = capacity;
	psl->array = (SLDataType *)malloc(capacity * sizeof(SLDataType));
	assert(psl->array);
	psl->size = 0;
}

void SeqListDestory(SeqList* psl) //销毁
{
	assert(psl);
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->size = 0;
		psl->capacity = 0;
	}
}

void CheckCapacity(SeqList* psl) //增容
{
	assert(psl);
	if (psl->size == psl->capacity) //表示已满
	{
		//psl->capacity = psl->capacity * 2;
		//psl->array = (SLDataType *) realloc (psl->array, psl->capacity * sizeof(SLDataType)); //realloc第一个参数为空相当于malloc

		size_t newcapacity = (psl->capacity == 0) ? 4 : psl->capacity * 2;
		psl->array = realloc(psl->array, sizeof(SLDataType)*newcapacity);
		psl->capacity = newcapacity;
	} 
}

void SeqListPushBack(SeqList* psl, SLDataType x) //尾插
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;

	//SeqListInsert(psl, psl->size, x);
}

void SeqListPopBack(SeqList* psl) //尾删
{
	assert(psl && psl->size >0);
	--psl->size;

	//SeqListErase(psl, psl->size-1);
}

void SeqListPushFront(SeqList* psl, SLDataType x) //头插
{
	assert(psl);
	CheckCapacity(psl);
	size_t end = psl->size; //若为size-1 下面改为：>= end的数据交给end+1
	while (end > 0)
	{
		psl->array[end] = psl->array[end - 1]; //原来顺序表数据均往后移动一个位置
		--end;
	}
	psl->array[0] = x; //再将array[0]置入
	psl->size++;

	//SeqListInsert(psl, 0, x);
}

void SeqListPopFront(SeqList* psl) //头删
{
	assert(psl || psl->size);

	//int i;
	//psl->size--;
	//for (i = 0; i < psl->size; ++i)
	//{
	//	psl->array[i] = psl->array[i + 1];
	//}

	size_t start = 1;
	while (start < psl->size) //size-1 向前覆盖数据
	{
		psl->array[start - 1] = psl->array[start];
		++start;
	}
	--psl->size;

	SeqListErase(psl, 0);
}

void SeqListPrint(SeqList* psl) //打印
{
	assert(psl);
	int i;
	for (i = 0; i < psl->size; ++i)
	{
		printf("%d ", psl->array[i]);
	}
	putchar('\n');
}

size_t SeqListSize(SeqList* psl)  //目的：不去操作结构体
{
	assert(psl);
	return psl->size;
}

size_t SeqListFind(SeqList* psl, SLDataType x) //查询
{
	assert(psl);
	for (size_t i = 0; i < psl->size; ++i)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//int SeqListFind(SeqList* psl, SLDataType x)//查找
//{
//	assert(psl);
//	int i;
//	for (i = 0; i < psl->size; ++i)
//	{
//		if (psl->array[i] == x)
//		{
//			return i;
//		}
//	}
//	return -1;
//}

SLDataType SLSeqListAt(SeqList* psl, size_t pos) //访问pos位置的值
{
	assert(psl);
	return psl->array[pos];
}

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)//按位置插入数据
{
	assert(psl && pos <= psl->size);
	CheckCapacity(psl);

	//int i;
	//for (i = psl->size - 1; i >= pos; --i)
	//{
	//	psl->array[i + 1] = psl->array[i];
	//}
	//psl->array[pos] = x;
	//psl->size++;

	size_t end = psl->size; //若为size-1时，>,将end、pos的定义为int类型 无符号--时，小心等于0的时候
	while (end > pos)  //把pos位置之后的数据往后挪动
	{
		psl->array[end] = psl->array[end - 1];
		--end;
	}
	psl->array[pos] = x;
	psl->size++;
}

void SeqListErase(SeqList* psl, size_t pos) //按位置删除
{
	assert(psl && pos < psl->size);
	//psl->size--;
	//int i;
	//for (i = pos; i < psl->size; ++i)
	//{
	//	psl->array[i] = psl->array[i + 1];
	//}

	size_t start = pos + 1; //控制边界条件、防止越界
	while (start < psl->size)
	{
		psl->array[start - 1] = psl->array[start];
		++start;
	}
	psl->size--;
}

void SeqListRemove(SeqList* psl, SLDataType x) //删除含有x里面的数据
{
	int pos = SeqListFind(psl, x);
	if (pos >= 0)
	{
		SeqListErase(psl, pos);
	}
}

void SeqListModify(SeqList* psl, size_t pos, SLDataType x) //将pos位置的数据替换为x
{
	assert(psl && pos < psl->size);

	psl->array[pos - 1] = x;
}

void SeqListBubbleSort(SeqList* psl)//冒泡排序  最坏O(n^2)、最好O(n)
{
	assert(psl);
	SLDataType tmp;
	size_t end = psl->size;

	//多趟
	while (end > 1) //end = 2 为终止条件、当只剩一个数时则不用再交换
	{
        //一趟
		for (size_t i = 1; i < end; ++i) 
	    {
		    if (psl->array[i-1] > psl->array[i])
		    {
			    tmp = psl->array[i-1];
			    psl->array[i-1] = psl->array[i];
			    psl->array[i] = tmp;
		    }
	    }
		--end;
	}
}

int SeqListBinaryFind(SeqList* psl, SLDataType x) // 要求：时间复杂度：O(N) 空间复杂度 O(1)
{
	assert(psl);
	size_t left = 0;
	size_t right = psl->size - 1; //[left, right] -1 <= 、[left, right) <
	size_t mid;
	while (left <= right)
	{
		mid = left + (right - left)/ 2; //(right - left) >> 1
		if (psl->array[mid] < x)
		{
			left = mid + 1;
		}
		else if (psl->array[mid] > x)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
