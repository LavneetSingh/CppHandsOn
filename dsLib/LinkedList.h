#pragma once
struct Node {
	void* info;
	Node* next;
};

void InsertAtFront(void* info);
void IncrementNodeCount();
void InsertAtEnd(void* info);
void InsertBefore(void* info, const void* beforeInfo);
//void InsertAfter(int info, int afterInfo);

//int DeleteNode(int info);
void DeleteList();

int GetNodeCount();
//int FindNode(int info);
void DisplayList();