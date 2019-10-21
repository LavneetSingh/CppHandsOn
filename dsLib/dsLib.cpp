// dsLib.cpp : Defines the functions for the static library.
//

#include <iostream>
#include "LinkedList.h"
#include "LLImpl.h"
using namespace std;
//int (*comparer)(const void* ob1, const void* ob2) = nullptr;
void (*display)(const void* ob) = nullptr;

void SetComparer(int (*param)(const void* ob1, const void* ob2))
{
	comparer = param;
}
Node* CreateNode(void* info)
{
	Node* newOne = new Node;
	newOne->info = info;
	newOne->next = nullptr;

	if (listHead == nullptr)
	{
		listHead = new Node;
		listHead->info = 0;
		listHead->next = nullptr;
	}

	return newOne;
}

void InsertAtFront(void* info)
{
	auto node = CreateNode(info);
	node->next = listHead->next;
	listHead->next = node;
	IncrementNodeCount();
}

void IncrementNodeCount()
{
	auto i = (int)listHead->info;
	listHead->info = (void*)++i;
}

void InsertAtEnd(void* info)
{
	Node* n = CreateNode(info);
	Node* t = listHead;
	for (int i = 0; t->next != nullptr; i++)
		t = t->next;
	t->next = n;
	IncrementNodeCount();
}

void InsertBefore(void* info, const void* beforeInfo)
{
	Node* n = CreateNode(info);
	Node* prev = nullptr;
	Node* t = listHead->next;
	for (int i = 0; t != nullptr; i++) {
		if (comparer(t->info, beforeInfo) == 0)
			break;
		prev = t;
		t = t->next;
	}
	prev->next = n;
	n->next = t;
	IncrementNodeCount();
}
//
//void InsertAfter(int info, int afterInfo)
//{
//	Node* n = CreateNode(info);
//	Node* t = listHead;
//	for (int i = 0; i < listHead->info; i++) {
//		if (t->info == afterInfo)
//			break;
//		t = t->next;
//	}
//	n->next = t->next;
//	t->next = n;
//	listHead->info++;
//}

//int DeleteNode(int info)
//{
//	Node* prev = nullptr;
//	Node* t = listHead;
//	for (int i = 0; i < listHead->info && t->info != info; i++) {
//		prev = t;
//		t = t->next;
//	}
//	if (t->next == nullptr && t->info != info)
//		return -1;
//
//	prev->next = t->next;
//	auto val = t->info;
//	delete t;
//	listHead->info--;
//
//	return val;
//}
void DeleteList()
{
	Node* remaining = nullptr;
	Node* del = listHead;
	for (int i = 0; del->next != nullptr; i++) {
		remaining = del->next;
		delete del;
		del = remaining;
	}
}

int GetNodeCount()
{
	return reinterpret_cast<int>(listHead->info);
}
//int FindNode(int info)
//{
//	int found = 0;
//	Node* currentNode = listHead;
//	for (int i = 0; i < listHead->info; i++) {
//		currentNode = currentNode->next;
//		if (currentNode->info == info) {
//			found = 1;
//			break;
//		}
//	}
//	return found;
//}

void DisplayList()
{
	Node* c = listHead;
	for (int i = 0; c->next != nullptr; i++) {
		c = c->next;
		display(c->info);
	}
	cout << endl;
	cout << endl;
}