typedef int DataType;

typedef struct node {
	DataType data;
	struct node *next;
}LinkNode;

//function of creating a new link node
LinkNode* newLinkNode(int e) {
	LinkNode *newNode = (LinkNode*)malloc(sizeof(LinkNode)); 
	if (NULL == newNode)
		exit(1);
	newNode->data = e;
	newNode->next = NULL;
	 
	return newNode;
}

//function of insert a new node to head node
void InsertNode(int e, LinkNode **head) {
	LinkNode *newNode = newLinkNode(e);
	newNode->next = *head;
	*head = newNode;
}

//function of print the link list
void DisplayLinkedList(LinkNode *head, int e) {
	LinkNode *temp = head;
	while(temp != NULL)
	{
		printf("%d-",temp->data);
		temp = temp->next;
	} 
	printf("%d",e);
} 

