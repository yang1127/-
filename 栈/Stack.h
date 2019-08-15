#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	size_t _top; // ջ��
	size_t _capacity; // ����
}Stack;

void StackInit(Stack* ps); //��ʼ��
void StackDestroy(Stack* ps); //����

void StackPush(Stack* ps, STDataType x); //��ջ
void StackPop(Stack* ps); //��ջ

STDataType StackTop(Stack* ps); //ջ������
bool StackEmpty(Stack* ps); //ջ��
size_t StackSize(Stack* ps);  //ջ����

void TestStack();