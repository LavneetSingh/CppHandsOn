struct Node {
	void* info;
	Node* next;
};

// callback function for node comparison
extern int (*comparer)(const void* ob1, const void* ob2);

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