typedef struct AdjNode {
/* Defines an adjacency list node */
	int pos;
	struct AdjNode *next;
}AdjNode;

typedef struct AdjList {
/* Defines a adjacency list */	
	struct AdjNode *head;
}AdjList;

typedef struct Graph {
/* Defines a Graph */ 
	int V;
	struct AdjList *list;
}Graph;

AdjNode* newAdjNode(int pos) {
/* Creating a new adjacency list node */
	AdjNode *newNode = (AdjNode*)malloc(sizeof(AdjNode));
	newNode -> pos = pos;
	newNode -> next = NULL;
	return newNode;
}

Graph* newGraph(int V) {
/* Defines a new graph */
	int i = 0;
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	graph -> V = V;
	graph -> list = (AdjList*)malloc(V * sizeof(AdjList));
	
	//Each adjacency next is be set to NULL
	for (i = 0; i < V; ++i)
		graph -> list[i].head = NULL;

	return graph;
}

void connectNodes(Graph *graph, int a, int b) {
/* Connects a node a with node b */

	//Adding a edge from a to b
	AdjNode *newNode = newAdjNode(b);
	newNode -> next = graph->list[a].head;
	graph -> list[a].head = newNode;
	
	//Adding a edge from b to a
	newNode = newAdjNode(a);
	newNode -> next = graph->list[b].head;
	graph -> list[b].head = newNode;	
}

void printGraph(Graph *graph) {
/* Prints out the graph in adjacency list form */
	int v; 
	//Moves down the graph list
	for (v = 0; v < graph->V; ++v)
	{
		struct AdjNode *p = graph -> list[v].head;
		printf("List at vertex %d:\nhead ", v);
		while (p)
		{
			printf("-> %d", p->pos);
			p = p -> next;
		}
		printf("\n");
	}
}
