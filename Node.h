#pragma once
#include "stdlib.h"
typedef int Type;
typedef struct Node
{
	Type data;
	struct Node *prev;
	struct Node *next;
}Node;
Node *Get_node(Type item, Node *prev0, Node *next0);//生成一个节点
Type Get_data(Node *current);//取节点中data成员的值
Node *Get_prev(Node *current);//取节点中prev成员的值
Node *Get_next(Node *current);//取节点中next成员的值
void Set_data(Node *current, Type item);//给节点中data成员赋值
