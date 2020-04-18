#pragma once

//������

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��������
void InsertSort(int* a, int n); //ֱ�Ӳ�������
void ShellSort(int* a, int n);  //��ϣ����

void Swap(int* p1, int* p2);
//ѡ������
void SelectSort(int* a, int n); //��������
void AdujustDown(int* a, int n, int parent); //�����µ���
void HeapSort(int* a, int n); //������

//��������
void BubbleSort(int* a, int n); //ð������
int OneSort1(int* a, int left, int right); //һ��
void QuickSort1(int* a, int left, int right); //��������

int GetMidIndex(int* a, int left, int right); // ����ȡ��
int OneSort2(int* a, int left, int right); //һ��
void QuickSort2(int* a, int left, int right); //��������

int OneSort3(int* a, int left, int right); //һ��
void QuickSort3(int* a, int left, int right); //��������

void QuickSortNonR(int* a, int left, int right); //���ŷǵݹ�

//�鲢����1
void _MergeSort(int* a, int left, int right, int* tmp);
void MergeSort(int* a, int n); //�鲢����
void MergeSortNonR(int* a, int n); //�ǵݹ� �鲢����

//��������
void CountSort(int* a, int n);

void PrintArry(int* a, int n); //��ӡ
void TestSort();

void TestOP();//������