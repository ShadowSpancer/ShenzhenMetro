//This Section is design for testing the function of loading info, this section can be comment out.
//You can customize this section base on your needs 
void testing() { 
	int i,j; 
	/* 
	for (i=0; i<28; i++)
	{
		printf("Line:%d, Id:%d, Name: %s\n",line11[i].line ,line11[i].id ,line11[i].name); 
	} 
	printf("\n\n");
	*/ 
		 
	printf("\n\n\n\nList of dictionary:\n\n");	
	for (j = 0; j<166; j++)
	{
		printf("ID:%d, Station: %s\n",j,sd[j]); //Display(Test) the whole stops name of shenzhen metro 
	} 
} 

