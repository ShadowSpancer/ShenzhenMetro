typedef int DataType;

typedef struct node {
	DataType data;
	struct node *next;
}ListNode;

//ListNode *head = NULL;
 
ListNode* newListNode(int e) {
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode)); 
	newNode->data = e;
	newNode->next = NULL;
	 
	return newNode;
}

ListNode* InsertNode(int e,ListNode *head) {
	ListNode *newNode = newListNode(e);
	newNode->next = head;
	head = newNode;
	
	return head;
}

void DisplayLinkedList(ListNode *head) {
	ListNode *temp = head;
	while(temp != NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->next;
	} 
} 

