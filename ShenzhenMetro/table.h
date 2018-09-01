typedef int bool;
#define TRUE 1
#define FALSE 0 

typedef struct {
	int id; 
	bool known;
	int dist;
	int path;
}Table;

//Table T[TotalStation];

void InitTable(int VertexStart, Table *T) {
	int i;
	
	for(i=0;i<TotalStation;i++)
	{
		T[i].id = i;
		T[i].known = FALSE;
		T[i].dist = INT_MAX;
		T[i].path = 999;
	}
	T[VertexStart].dist = 0; 
}

void DisplayTable(Table *T) {
	int i; 
	printf("ID\tKnown\tDist\tPath\n");
	for(i=0;i<TotalStation;i++)
	{
		printf("%d\t%d\t%d\t%d\n",T[i].id,T[i].known,T[i].dist,T[i].path);
	}	
} 

