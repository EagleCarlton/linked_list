#pragma once
#include "Node.h"
typedef struct
{
	Node *head;
	Node *tail;
	int size;
}List;
void Init(List *L);//建空表
Node *Begin(List *L);//取链表左闭右开区域的左边界
Node *End(List *L);//取右边界
Node *Insert(List *L, Node *current, Type item);//在指针current指向的位置插入item
Node *Erase(List *L, Node *current);//把指针current指向的节点删除
Type *Front_pointer(List *L);//取数据首节点中data成员的指针
Type Front_data(List *L);//取数据首节点中data成员的值
Type *Back_pointer(List *L);//取数据尾节点data成员的指针
Type Back_data(List *L);//取数据尾节点data成员的值
void Push_front(List *L, Type item);//在数据首节点前插入item
void Push_back(List *L, Type item);//在数据尾节点后插入item
void Pop_front(List *L);//删除数据首节点
void Pop_back(List *L);//删除数据尾节点
int Size(List *L);//取数据节点个数
int Empty(List *L);//判空
void Clear(List *L);//清表释放数据节点空间，成为空表
void Free(List *L);//释放所有节点空间
void display_list(Node *first, Node *last);//输出链表
