void BFS(Graph *graph, int start, int end, int q) {
	int s = start, e = end;
	int V, W;
	
	LinkNode *head = NULL;
	AdjNode *p = NULL; 
	Queue *Q = NULL;
	
	Table T[TotalStation]; InitTable(s,T);
	Q = createQueue(TotalStation); makeEmpty(Q);
	enqueue(Q,s);
	
	while(!isEmpty(Q))
	{
		V = dequeue(Q);
		T[V].known = TRUE;
		
		p = graph->list[V].head;
		while(p != NULL)
		{
			W = p->pos;
			if(T[W].dist == Infinity)	//Infinity is INT_MAX, it was be defined at head file "table.h"
			{
				T[W].dist = T[V].dist + 1;
				T[W].path = V;
				enqueue(Q,W);
			} 
			p = p->next;
		} 
	}
	
	if(q==3)	 	
		FareCalculator(T, s, e);
	else if(q==2)
	{
		ShortestPath(T, e, &head);
		DisplayShortestPath(head, e);
	}
	
//	DisplayTable(T);	//Function for viewing the entire table, you can eliminate the the symbol of annotation for checking the whole table
//	DisposeQueue(Q);	//This function did not be created, coming soon	
}

void FareCalculator (Table *T, int s, int e) {
	float initialFare = 2;
	float eachStationFare = 0.5;
	float maximalFare = 14;
	double fare;
	int i;
	void *cs, *ce;
	
	for(i=0; i<TotalStation; i++)
	{
		if(T[i].id == s)
			cs = &sd[i];
		else if(T[i].id == e)
		{
			ce = &sd[i];
			if(T[i].dist <= 13)
				fare = initialFare + (T[i].dist * eachStationFare);
			else
				fare = maximalFare;
		}
		else
			continue;	
	}
	printf("============================================\n");
	printf(" WELCOME TO SHENZHEN METRO!\n");
	printf(" Your ticket is:\n"); 
	printf(" -From: %s  -To: %s", cs, ce);
	printf(" \n At least %d stops are required\n", T[e].dist);
	printf(" The price of ticket is %0.2f(Yuan)\n", fare);	
	printf("============================================\n");
} 

void ShortestPath(Table *T, int e, LinkNode **head) {
	int InitialPath = 999; 
	while(T[e].path != InitialPath)
	{
		InsertNode(T[e].path, head);
		e = T[e].path;
	}	
}

void DisplayShortestPath(LinkNode *head, int e) {
	printf("The shortest path is:\n"); 
	LinkNode *temp = head;
	while(temp != NULL)
	{
		printf("%d.%s",temp->data,sd[temp->data].name);
		temp = temp->next;
		printf(" -> "); 
	} 
	printf("%d.%s\n",e,sd[e].name);	
}

