#pragma once

/*
	自实现链表
*/

//链表节点
struct Node
{
	Node* pNodePrev;
	Node* pNodeNext;
	void* pData;
};

//创建一个指定长度的链表，返回链表头
Node* CreateList(unsigned int amount);

//在指定位置前插入一个节点
//插入成功返回插入的Node*，否则返回null
//传入链表的头
Node* InsertNode(Node* pNodeHead, int index);

//删除指定位置的节点，若不存在返回false
//传入链表的头
bool RemoveNode(Node* pNodeHead, int index);

//删除整条链表，传入链表的头
void ClearList(Node* pNodeHead);