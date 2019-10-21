Node* CreateNode(void* info);
Node* listHead;
void IncrementNodeCount();
int (*comparer)(const void* ob1, const void* ob2);