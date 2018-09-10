typedef int bool;
#define TRUE 1
#define FALSE 0
#define Infinity INT_MAX   

typedef struct {
	int id; 
	bool known;
	int dist;
	int path;
}Table;

//Initialize Table 
void InitTable(int VertexStart, Table *T) {
	int i;
	int InitialPath = 999; 
	for(i=0;i<TotalStation;i++)
	{
		T[i].id = i;				//update id
		T[i].known = FALSE;			//Set status of column known as unknown 
		T[i].dist = Infinity;		//Set status of column distance as infinity 
		T[i].path = InitialPath;	//Set status of path as 999
	}
	T[VertexStart].dist = 0; 
}

//Function of displaying the table
void DisplayTable(Table *T) {
	int i; 
	printf("ID\tKnown\tDist\tPath\n");
	for(i=0;i<TotalStation;i++)
		printf("%d\t%d\t%d\t%d\n",T[i].id,T[i].known,T[i].dist,T[i].path);
} 

