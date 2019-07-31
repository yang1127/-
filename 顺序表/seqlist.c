#include "seqlist.h"

void SeqListInit(SeqList* psl, size_t capacity) //��ʼ��
{
	assert(psl);
	psl->capacity = capacity;
	psl->array = (SLDataType *)malloc(capacity * sizeof(SLDataType));
	assert(psl->array);
	psl->size = 0;
}

void SeqListDestory(SeqList* psl) //����
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

void CheckCapacity(SeqList* psl) //����
{
	assert(psl);
	if (psl->size == psl->capacity) //��ʾ����
	{
		//psl->capacity = psl->capacity * 2;
		//psl->array = (SLDataType *) realloc (psl->array, psl->capacity * sizeof(SLDataType)); //realloc��һ������Ϊ���൱��malloc

		size_t newcapacity = (psl->capacity == 0) ? 4 : psl->capacity * 2;
		psl->array = realloc(psl->array, sizeof(SLDataType)*newcapacity);
		psl->capacity = newcapacity;
	} 
}

void SeqListPushBack(SeqList* psl, SLDataType x) //β��
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;

	//SeqListInsert(psl, psl->size, x);
}

void SeqListPopBack(SeqList* psl) //βɾ
{
	assert(psl && psl->size >0);
	--psl->size;

	//SeqListErase(psl, psl->size-1);
}

void SeqListPushFront(SeqList* psl, SLDataType x) //ͷ��
{
	assert(psl);
	CheckCapacity(psl);
	size_t end = psl->size; //��Ϊsize-1 �����Ϊ��>= end�����ݽ���end+1
	while (end > 0)
	{
		psl->array[end] = psl->array[end - 1]; //ԭ��˳������ݾ������ƶ�һ��λ��
		--end;
	}
	psl->array[0] = x; //�ٽ�array[0]����
	psl->size++;

	//SeqListInsert(psl, 0, x);
}

void SeqListPopFront(SeqList* psl) //ͷɾ
{
	assert(psl || psl->size);

	//int i;
	//psl->size--;
	//for (i = 0; i < psl->size; ++i)
	//{
	//	psl->array[i] = psl->array[i + 1];
	//}

	size_t start = 1;
	while (start < psl->size) //size-1 ��ǰ��������
	{
		psl->array[start - 1] = psl->array[start];
		++start;
	}
	--psl->size;

	SeqListErase(psl, 0);
}

void SeqListPrint(SeqList* psl) //��ӡ
{
	assert(psl);
	int i;
	for (i = 0; i < psl->size; ++i)
	{
		printf("%d ", psl->array[i]);
	}
	putchar('\n');
}

size_t SeqListSize(SeqList* psl)  //Ŀ�ģ���ȥ�����ṹ��
{
	assert(psl);
	return psl->size;
}

size_t SeqListFind(SeqList* psl, SLDataType x) //��ѯ
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

//int SeqListFind(SeqList* psl, SLDataType x)//����
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

SLDataType SLSeqListAt(SeqList* psl, size_t pos) //����posλ�õ�ֵ
{
	assert(psl);
	return psl->array[pos];
}

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)//��λ�ò�������
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

	size_t end = psl->size; //��Ϊsize-1ʱ��>,��end��pos�Ķ���Ϊint���� �޷���--ʱ��С�ĵ���0��ʱ��
	while (end > pos)  //��posλ��֮�����������Ų��
	{
		psl->array[end] = psl->array[end - 1];
		--end;
	}
	psl->array[pos] = x;
	psl->size++;
}

void SeqListErase(SeqList* psl, size_t pos) //��λ��ɾ��
{
	assert(psl && pos < psl->size);
	//psl->size--;
	//int i;
	//for (i = pos; i < psl->size; ++i)
	//{
	//	psl->array[i] = psl->array[i + 1];
	//}

	size_t start = pos + 1; //���Ʊ߽���������ֹԽ��
	while (start < psl->size)
	{
		psl->array[start - 1] = psl->array[start];
		++start;
	}
	psl->size--;
}

void SeqListRemove(SeqList* psl, SLDataType x) //ɾ������x���������
{
	int pos = SeqListFind(psl, x);
	if (pos >= 0)
	{
		SeqListErase(psl, pos);
	}
}

void SeqListModify(SeqList* psl, size_t pos, SLDataType x) //��posλ�õ������滻Ϊx
{
	assert(psl && pos < psl->size);

	psl->array[pos - 1] = x;
}

void SeqListBubbleSort(SeqList* psl)//ð������  �O(n^2)�����O(n)
{
	assert(psl);
	SLDataType tmp;
	size_t end = psl->size;

	//����
	while (end > 1) //end = 2 Ϊ��ֹ��������ֻʣһ����ʱ�����ٽ���
	{
        //һ��
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

int SeqListBinaryFind(SeqList* psl, SLDataType x) // Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
{
	assert(psl);
	size_t left = 0;
	size_t right = psl->size - 1; //[left, right] -1 <= ��[left, right) <
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
