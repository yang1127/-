#include "Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->_a != NULL)
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_capacity = ps->_top = 0;
	}
}


void StackPush(Stack* ps, STDataType x) //入栈
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 2 : ps->_capacity * 2; // newcapacity = ps->_capacity *= 2;
		ps->_a = (STDataType*)realloc(ps->_a, newcapacity * sizeof(STDataType));
		ps->_capacity = newcapacity;
	}

	ps->_a[ps->_top] = x; // 在栈顶的位置加数据
	ps->_top++;
}

void StackPop(Stack* ps) //出栈
{
	assert(ps);
	if (ps && ps->_top > 0) //栈里要有数据
	{
		--ps->_top;
	}
}

STDataType StackTop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	return ps->_a[ps->_top - 1];
}

bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0; //0为空
}

size_t StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}