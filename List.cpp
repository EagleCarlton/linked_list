#include "stdafx.h"
#include "List.h"
void Init(List *L)
{//建空表
	L->head = (Node *)malloc(sizeof(Node));
	if (L->head == NULL)
	{
		printf("HeadMemory allocation failure!");
		exit(1);
	}
	L->head->next = L->head->prev = NULL;
	L->tail = (Node *)malloc(sizeof(Node));
	if (L->tail == NULL)
	{
		printf("TailMemory allocation failure!");
		exit(1);
	}
	L->tail->next = L->tail->prev = NULL;
	L->head->next = L->tail;
	L->tail->prev = L->head;
	L->size = 0;
}
Node *Begin(List *L)
{//取链表左闭右开区域的左边界
	return L->head->next;
}

Node *End(List *L)
{//取右边界
	return L->tail;
}
Node *Insert(List *L, Node *current, Type item)
{//在指针current指向的位置插入item
	Node *p = current;
	L->size++;
	p->prev->next = Get_node(item, p->prev, p);
	p->prev = p->prev->next;
	return p->prev;
}
Node *Erase(List *L, Node *current)
{//把指针current指向的节点删除
	Node *p = current;
	Node *re = p->next;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
	L->size--;
	return re;
}
Type *Front_pointer(List *L)
{//取数据首节点中data成员的指针
	Node *current = L->head->next;
	return &(current->data);
}
Type Front_data(List *L)
{//取数据首节点中data成员的值
	Node *current = L->head->next;
	return current->data;
}
Type *Back_pointer(List *L)
{//取数据尾节点data成员的指针
	Node *current = L->tail->prev;
	return &(current->data);
}
Type Back_data(List *L)
{//取数据尾节点data成员的值
	Node *current = L->tail->prev;
	return current->data;
}
void Push_front(List *L, Type item)
{//在数据首节点前插入item
	Insert(L, Begin(L), item);
}
void Push_back(List *L, Type item)
{//在数据尾节点后插入item
	Insert(L, End(L), item);
}
void Pop_front(List *L)
{//删除数据首节点
	Erase(L, Begin(L));
}
void Pop_back(List *L)
{//删除数据尾节点
	Erase(L, Get_prev(End(L)));
}
int Size(List *L)
{//取数据节点个数
	return L->size;
}
int Empty(List *L)
{//判空
	return L->size == 0;
}
void Clear(List *L)
{//清表释放数据节点空间，成为空表
	while (!Empty(L))
		Pop_front(L);
	L->size = 0;
}
void Free(List *L)
{//释放所有节点空间
	Clear(L);
	free(L->head);
	free(L->tail);
}
void display_list(Node *first, Node *last)
{//输出链表
	for (; first != last; first = Get_next(first))
		printf("%d\t", Get_data(first));
	printf("\n");
}
