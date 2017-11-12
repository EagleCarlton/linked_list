#include "stdafx.h"
#include "Node.h"
Node *Get_node(Type item, Node *prev0, Node *next0)
{//生成一个节点，返回此节点指针
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("Memory allocation failure!");
		exit(1);
	}
	p->data = item;
	p->prev = prev0;
	p->next = next0;
	return p;
}
Type Get_data(Node *current)
{//取节点中data成员的值
	return current->data;
}
Node *Get_prev(Node *current)
{//取节点中prev成员的值
	return current->prev;
}
Node *Get_next(Node *current)
{//取节点中next成员的值
	return current->next;
}
void Set_data(Node *current, Type item)
{//给节点中的data成员赋值
	current->data = item;
}
