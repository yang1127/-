#include "Heap.h"

void HeapInit(Heap* hp, HPDataType* a, int n) //��ʼ����
{
	hp->_a = malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n); //�ȱ���hp->_a���ٽ�����Ŀռ�����a
	hp->_size = n;
	hp->_capacity = n;
	//������
	for (int i = (n - 1 - 1) / 2; i >= 0; --i) //n-1-1 �������ϣ�n-1Ϊ���һ��Ҷ�ӽڵ㣬��-1��2�����ҵ���Ҷ�ӽ��ĸ��ڵ�
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

void AdjustDown(HPDataType* a, size_t n, size_t parent) //���µ������丸�ڵ�������Һ���
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

void HeapDestory(Heap* hp) //�ͷ�
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
	while (child > 0)  //ע��ѭ������
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2; //ѭ����������Ϊparent>=0 ,��child=0ʱ����������
		}
		else
		{
			break;
		}
	}
}

void HeapPush(Heap* hp, HPDataType x) //����
{
	if (hp->_size == hp->_capacity) //�жϿռ�����
	{
		size_t newcapacity = hp->_capacity == 0 ? 2 : hp->_capacity * 2;
		hp->_a = (HPDataType*) realloc (hp->_a, sizeof(HPDataType)*newcapacity); //�ѾɵĿռ��ȸ�hp->_a
		hp->_capacity = newcapacity;
	} 
	hp->_a[hp->_size] = x;
	hp->_size++;
	AdjustUp(hp->_a, hp ->_size-1);
}


void HeapPop(Heap* hp) //ɾ��
{
	assert(hp->_size > 0);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0); //�Ӹ���ʼ���µ���
}

HPDataType HeapTop(Heap* hp) //��
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

void HeapSort(int* a, int n) // ������
{
	//����  �����
	for (int i = (n - 1 - 1) / 2; i >= 0; --i) //�±��ټ�һ
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

void HeapPrint(Heap* hp) //��ӡ
{
	for (size_t i = 0; i < hp->_size; ++i) 
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}