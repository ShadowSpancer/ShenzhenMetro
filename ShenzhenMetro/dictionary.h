#define TotalStation 166 

typedef struct {
/* A struct for storage of the information of whole station */
	char name[50]; 
}StationDictionary;

typedef struct {
/* A struct for storage of the information of each station of each line */
	char name[50];
	int line;
	int id; 
	//bool transfer;
}Station;

StationDictionary sd[TotalStation];		//A dictionary of shenzhen metro system, that as the index be used for mapping from name to id
Station line1[30], line2[29], line3[30], line4[15], line5[27], line7[28], line9[22], line11[18]; 		//Each line of Shenzhen metro system
