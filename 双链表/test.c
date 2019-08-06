#include "list.h"

void ListTest() //≤‚ ‘
{
	ListNode s;
	ListInit(&s);
	ListPushBack(&s, 1);
	ListPushBack(&s, 2);
	ListPushBack(&s, 3);
	ListPushBack(&s, 4);
	ListPopBack(&s, 4);
	ListPrint(&s);
}

int main()
{
	ListTest();
	system("pause");
	return 0;
}