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
	size_t _top; // 栈顶
	size_t _capacity; // 容量
}Stack;

void StackInit(Stack* ps); //初始化
void StackDestroy(Stack* ps); //销毁

void StackPush(Stack* ps, STDataType x); //入栈
void StackPop(Stack* ps); //出栈

STDataType StackTop(Stack* ps); //栈顶数据
bool StackEmpty(Stack* ps); //栈空
size_t StackSize(Stack* ps);  //栈长度

void TestStack();