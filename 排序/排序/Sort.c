#include "sort.h"
#include "Stack.h"

//��������
void InsertSort(int* a, int n) //ֱ�Ӳ�������
{
	//˼·�������źõ������в������ݣ����ڵ��������ƶ����ǣ��������Ҫ����ǰһ������С�ں�һ��������a[0]���ñȽ�ǰһ����
	//��������ݵ�λ��Ϊa[0]-a[n-1],���Ƚϵ�n-2��λ��
	//ʱ�� O(n*n):���O(n)���O(n*n)�� �ռ� O(1) �ȶ�

	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1]; //Ҫ�������
		while (end >= 0) //=0 ��ԭ���е�ͷ����
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end]; //������
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;  //ǰ�����ź���ֱ�Ӳ������һ��λ��
	}
}

void ShellSort(int* a, int n)  //��ϣ����
{
	//˼·������һ��gap��gap����ֵ��������֮����gap��Ȼ��Ԥ����Ԥ������ɺ�����ӽ�������
	//�ٽ���һ�β�������
	//ʱ�� O(n*1.3-n*2) ���ȶ�
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1; //���ü�࣬+1ȷ�����в������� gap = 1 ��ʾֱ�Ӳ�������

		for (int i = 0; i < n - gap; ++i) //��i�ߵ�n-1-gap�������Ƚ����ݽ���
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

//ѡ������
void SelectSort(int* a, int n) //ѡ������
{
	//˼·��ÿһ�δӴ����������Ԫ����ѡ����СԪ�طŵ���ʼλ�ã�ѡȡ���Ԫ�طŴ��������ֱ��ȫ�������������Ԫ�����ꡣ
    //��ѡȡ��Ԫ�ز�������Ԫ���еĵ�һ�������һ��Ԫ�أ�������������Ԫ���еĵ�һ�������һ��Ԫ�ؽ���

	int begin = 0;
	int end = n - 1;
	int max_index, min_index; //index->ָ��
	max_index = min_index = 0;
	while (begin <= end)
	{
		for (int i = begin + 1; i < end; ++i)
		{
			if (a[i] > a[max_index])
				max_index = i; //�����Ԫ�ص�ַ����max�����ɾ�����һ�ֱȽ�
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
		if (child + 1 < n && a[child] < a[child + 1]) //ѡ��С�ĺ���
			++child;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]); //��������
			parent = child; 
			child = parent * 2 + 1; //����
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n) //������
{
	//˼·��������Ҫ����ѣ��Ž���С��
	// ʱ�䣺O(N)���ռ䣺O(1)�����ȶ�
	 
	for (int i = (n - 2) / 2; i >= 0; --i) //����
	{
		AdujustDown(a, n, i);
	}

	int end = n - 1; //������
	while (end > 0)
	{
		Swap(&a[0], &a[end]); //*�ѽ�����ѣ���a[0]��a[end]�������پ��жѵ���
		AdujustDown(a, end, 0);
		--end;
	}
}

//��������
void BubbleSort(int* a, int n) //ð������
{
	//˼·�����ϴ�������е�β���ƶ�����С�������е�ǰ���ƶ�
	// ʱ�临�Ӷȣ�O(N^2) ���ռ临�Ӷȣ�O(1)���ȶ��ԣ��ȶ�
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
		while (left < right && a[left] <= key) //a[left] <= key,����ѭ��++������ʱ��������ָ�����ҵ������н���
			++left;
		while (left < right && a[right] >= key)
			--right;

	    Swap(&a[left], &a[right]);

	    while (left > right) //��ֹ���
		    ++left;
	    while (left < right)
		    --right;
	}

	Swap(&a[left], &a[key_index]); //left = rightʱ��ѡȡ��key����a[left] �� key��ָ����ֵ����
	
	return left;
}

void QuickSort1(int* a, int left, int right) //��������
{
	//˼·����һ������ָ�뷨�������������ѡȡһ��key
	//��ָ�������Ҵ���key����Ӧ��������ָ����С��key����Ӧ����ֵ���ҵ�����ָ���Ӧ����ֵ����
	//�ұ���key�������󣬺����ң����Ϊkey�������ң�������ָ������ʱ��left����key������right����key����

	if (left > right)  //û�е������
		return;

	int key_index = OneSort1(a, left, right); //�����Ϊ�����֣�[left, key_index-1] key [key_index + 1, right]
	QuickSort1(a, left, key_index-1);
	QuickSort1(a, key_index + 1, right);
}

//���� ʱ�䣺O(nlogn)  ��������˳��������O(n^2��
//�Ż���<1>���ȡkey <2> ����ȡ�� <3>С�������

//����ȡ��
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
	int mid = GetMidIndex(a, left, right);  //��
	Swap(&a[mid], &a[left]);                //��

	int key = a[right];  //����key

	while (left < right)
	{
		while (left < right && a[left] <= key) //a[left] <= key,����ѭ��++
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
	a[left] = key; //ָ������ʱ

	return left;
}

void QuickSort2(int* a, int left, int right) //��������
{
	//˼·���������ڿӷ��������������ѡȡһ��key��ȡ����λ����ֵ�����ÿ�
	//��ָ�������Ҵ���key����Ӧ�������ҵ��������ǿӣ��Լ���λ��Ϊ�¿ӣ���ָ����С��key����Ӧ����ֵ��ͬ��
	//�ұ���key�������󣬺����ң����Ϊkey�������ң�������ָ������ʱ��left��λ�÷�����key��right��λ�÷���key

	if (left > right)  //û�е������
		return;

	int key_index = OneSort2(a, left, right); //�����Ϊ�����֣�[left, key_index-1] key [key_index + 1, right]
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
		++cur;  //a[cur] > a[right] ������
	}
	++prev;
	Swap(&a[prev], &a[right]);
	return prev;
}

void QuickSort3(int* a, int left, int right) //��������
{
	//˼·��������ǰ��ָ�뷨����������key������������ָ��һǰprev һ��cur
	//curָ���left��ʼ��������key��ľ͹��˵�����keyС�ģ���ͣ������prev++
	//�ж�prev��cur�Ƿ���ȣ��������ȣ��ͽ�����ֵ���н���
	//prev:��1��curû���ҵ���key�������++cur��++prev�������һ��λ
	//��2��cur�ҵ���key�������cur��prev�໥������cur��prev֮����λΪ����key����
	//���һ�˵���keyλ�ã�prev��key��Ӧ�����������keyС�ģ���������key����ߣ���key��Ķ���key���ұ�

	if (left > right)  //û�е������
		return;

	int key_index = OneSort3(a, left, right); 
}

void QuickSortNonR(int* a, int left, int right) //�ǵݹ�
{
	Stack st;
	StackInit(&st);
	StackPush(&st, left);
	StackPush(&st, right);

	while (!StackEmpty(&st))  //ջ��Ϊ��
	{
		int end = StackTop(&st);
		StackPop(&st);
		int begin = StackTop(&st);
		StackPop(&st);

		int key_index = OneSort3(a, begin, end); //�����Ϊ�����֣�[left, key_index-1] key [key_index + 1, right]

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
	//�ֽ�
	if (left == right) //������ֻ����������
		return;
	int mid = left + (right - left) / 2;
	_MergeSort(a, left, mid, tmp);  //���仮��[left, mid] ��[mid+1, right]
	_MergeSort(a, mid + 1, right, tmp);

	//�ϲ�
	//����֮�����򣬹鲢
	int begin1 = left; int end1 = mid;
	int begin2 = mid + 1; int end2 = right;
	int  i = left; //tmp

	//begin1��end1��begin2��end2 ��������
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

	memcpy(a + left, tmp + left, sizeof(int)*(i - left)); //ԭ��Ŀ�ꡢ��С��right-left+1�������ÿ��С����

}

void MergeSort(int* a, int n) //�鲢����
{
	//ʱ�临�Ӷȣ�O��nlogn�����ռ临�Ӷȣ�O��n�����ȶ��ԣ��ȶ�
	//˼·�������㷨���ȷֽ��ٺϲ����ݹ�Ľ����������,ÿ���������ּ����ݹ�����Լ���ֱ��"left<right"��һ����������ʱ
	//��"left==right"ʱ����ʱֻ��һ��Ԫ�أ���Ȼ������ģ������ٽ�����һ���ϲ���

	int* tmp = (int*)malloc(sizeof(int)*n); //�ϲ�ʱ���Ȱ����ŵ�tmp�����У���������ٸ��ǵ�ԭ���飬ֱ�����һ����ɼ��������
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

void MergeSortNonR(int* a, int n) //�ǵݹ� �鲢���� ʱ�临�Ӷȣ� O��nlogn��
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	
	int gap = 1; //ÿ��һ��һ���鲢
	while (gap <= n) //����ÿ�ι鲢�Ĵ�С
	{
		for (int begin = 0; begin < n; begin += 2 * gap)  //��Ҫȥ��ͼ
		{
			//[begin, begin+gap-1] [begin+gap��begin+2*gap -1]  ���ƺñ����䡢������
			int begin1 = begin, end1 = begin + gap - 1;
			if (end1 >= n - 1) //�߽�
			{
				end1 = n - 1;
			}

			int begin2 = begin + gap, end2 = begin + 2 * gap - 1;
			if (end2 >= n - 1)
			{
				end2 = n - 1;
			}

			int  i = begin1; //tmp

			//begin1��end1��begin2��end2 ��������
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
	//˼·��ͳ����ͬԪ�س��ִ���������ͳ�ƵĽ�������л��յ�ԭ����������
	int max = a[0], min = a[0];
	for (int i = 0; i < n; ++i) //�������е�max��min
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

	int range = max - min + 1; //����������Ĵ�С
	int* counta = (int*)malloc(sizeof(int)*(max - min)); 
	memset(counta, 0, sizeof(int)*range);

	//ͳ�ƴ���
	for (int i = 0; i < n; ++i)
	{
		counta[a[i] - min]++;
	}

	//����
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