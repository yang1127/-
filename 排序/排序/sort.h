#pragma once

//以升序

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//插入排序
void InsertSort(int* a, int n); //直接插入排序
void ShellSort(int* a, int n);  //哈希排序

void Swap(int* p1, int* p2);
//选择排序
void SelectSort(int* a, int n); //快速排序
void AdujustDown(int* a, int n, int parent); //堆向下调整
void HeapSort(int* a, int n); //堆排序

//交换排序
void BubbleSort(int* a, int n); //冒泡排序
int OneSort1(int* a, int left, int right); //一趟
void QuickSort1(int* a, int left, int right); //快速排序

int GetMidIndex(int* a, int left, int right); // 三数取中
int OneSort2(int* a, int left, int right); //一趟
void QuickSort2(int* a, int left, int right); //快速排序

int OneSort3(int* a, int left, int right); //一趟
void QuickSort3(int* a, int left, int right); //快速排序

void QuickSortNonR(int* a, int left, int right); //快排非递归

//归并排序1
void _MergeSort(int* a, int left, int right, int* tmp);
void MergeSort(int* a, int n); //归并排序
void MergeSortNonR(int* a, int n); //非递归 归并排序

//计数排序
void CountSort(int* a, int n);

void PrintArry(int* a, int n); //打印
void TestSort();

void TestOP();//测性能