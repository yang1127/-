#include "Stack.h"

void TestStack()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	while (!StackEmpty(&ps))
	{
		printf("%d ", StackTop(&ps));
		StackPop(&ps);
	}
	printf("\n");
	StackDestroy(&ps);
}

int main()
{
	TestStack();
	system("pause");
	return 0;
}
