// 链表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "List.h"

int main()
{
	int i, item;
	Node *current;
	List L;
	Init(&L);
	printf("Input 10 integers:\n");
	for (i = 0; i < 10; ++i)
	{
		scanf_s("%d", &item);
		Push_back(&L, item);
	}

	current = Begin(&L);
	current = Get_next(current);
	printf("The second:\n");
	printf("%d\n", Get_data(current));

	current = Get_prev(current);
	printf("The first:\n");
	printf("%d\n", Get_data(current));

	Erase(&L, current);
	printf("After erasing the first:\n");
	display_list(Begin(&L), End(&L));

	Pop_back(&L);
	printf("After erasing the last:\n");
	display_list(Begin(&L), End(&L));

	printf("The first and the last:\n");
	printf("%d\n", Front_data(&L));
	printf("%d\n", Back_data(&L));

	printf("Update the first and the last:\n");
	*Front_pointer(&L) = 100;
	*Back_pointer(&L) = 200;
	display_list(Begin(&L), End(&L));
	Free(&L);

	return 0;
}

