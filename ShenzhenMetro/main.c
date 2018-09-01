#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "adjancencylist.h"
#include "dictionary.h"
#include "queue.h"
#include "linkedlist.h" 
#include "table.h"
#include "test.h"

/* The main menu */
void mainmenu(Graph *graph) {
	int s;
	printf("Please select what kind of service you need:");
	printf("\n1.Check the line\n2.Check the path between the start station and the end station\n3.Purchase a ticket");
	printf("\nSELECT: ");
	scanf("%d", &s);
	printf("\n");
	if(s<1 || s>3)	//Existing a slight problem at here, if input is a not the type of int, that will cause a death loop;
	{
		printf("please input a correct option id!\n\n");
		mainmenu(graph); 
	}
	else
		submenu(s, graph);		
} 

/* A sub-class menu */
void submenu(int q, Graph *graph) { 
	int i;
	int s,e;	//Initial the input of the start station and end station 

	switch(q)
	{
	case 1:
		printf("Which line you want to view:\n");
		printf("1.Line 1 ('Luohu' <---> 'Airport East')\n");
		printf("2.Line 2 ('Xinxiu' <---> 'Chiwan')\n");
		printf("3.Line 3 ('Shuanglong' <---> 'Yitian')\n");
		printf("4.Line 4 ('Qinghu' <---> 'Futian Checkpoint')\n");
		printf("5.Line 5 ('Huangbeiling' <---> 'Qianhaiwan')\n");
		printf("6.Line 7 ('Tiaan' <---> 'Xili Lake')\n");
		printf("7.Line 9 ('Wenjin' <---> 'Hongshuwan South')\n");
		printf("8.Line 11 ('Futian' <---> 'Bitou')\n");
		printf("0.Return to the main menu\n");
		printf("SELECT: ");
		scanf("%d", &q);
		printf("\n");	
		if(q==0)
			mainmenu(graph);
			
			switch(q)
			{
				case 1:
					printf("1.Line 1 ('Luohu' <---> 'Airport East')\n");
					for(i=0;i<30;i++)
					{
						printf("ID: %d,  Station: %s", line1[i].id, line1[i].name); 
					}
					printf("Input 0 and click enter to return main menu: ");
					scanf("%d", &q);
					if(q==0)
					{
						printf("\n");
						mainmenu(graph);
					}  
					break;
				case 2:
					printf("2.Line 2 ('Xinxiu' <---> 'Chiwan')\n");
					for(i=0;i<29;i++)
					{
						printf("ID: %d,  Station: %s", line2[i].id, line2[i].name); 
					} 
					printf("Input 0 and click enter to return main menu: ");
					scanf("%d", &q);
					if(q==0)
					{
						printf("\n");
						mainmenu(graph);
					}
 					break;
				case 3:
					printf("3.Line 3 ('Shuanglong' <---> 'Yitian')\n");
					for(i=0;i<30;i++)
					{
						printf("ID: %d,  Station: %s", line3[i].id, line3[i].name); 
					} 
					printf("Input 0 and click enter to return main menu: ");
					scanf("%d", &q);
					if(q==0)
					{
						printf("\n");
						mainmenu(graph);
					}  					
					break;
				case 4:
					printf("4.Line 4 ('Qinghu' <---> 'Futian Checkpoint')\n");
					for(i=0;i<15;i++)
					{
						printf("ID: %d,  Station: %s", line4[i].id, line4[i].name); 
					} 
					printf("Input 0 and click enter to return main menu: ");
					scanf("%d", &q);
					if(q==0)
					{
						printf("\n");
						mainmenu(graph);
					} 
					break;
				case 5:
					printf("5.Line 5 ('Huangbeiling' <---> 'Qianhaiwan')\n");
					for(i=0;i<27;i++)
					{
						printf("ID: %d,  Station: %s", line5[i].id, line5[i].name); 
					} 
					printf("Input 0 and click enter to return main menu: ");
					scanf("%d", &q);
					if(q==0)
					{
						printf("\n");
						mainmenu(graph);
					}	
					break;
				case 6:
					printf("6.Line 7 ('Tiaan' <---> 'Xili Lake')\n");
					for(i=0;i<28;i++)
					{
						printf("ID: %d,  Station: %s", line7[i].id, line7[i].name); 
					} 
					printf("Input 0 and click enter to return main menu: ");
					scanf("%d", &q);
					if(q==0)
					{
						printf("\n");
						mainmenu(graph);
					}  
					break;
				case 7:
					printf("7.Line 9 ('Wenjin' <---> 'Hongshuwan South')\n");
					for(i=0;i<22;i++)
					{
						printf("ID: %d,  Station: %s", line9[i].id, line9[i].name); 
					} 
					printf("Input 0 and click enter to return main menu: ");
					scanf("%d", &q);
					if(q==0)
					{
						printf("\n");
						mainmenu(graph);
					}  
					break;
				case 8:
					printf("8.Line 11 ('Futian' <---> 'Bitou')\n");
					for(i=0;i<18;i++)
					{
						printf("ID: %d,  Station: %s", line11[i].id, line11[i].name);
					} 
					printf("Input 0 and click enter to return main menu: ");
					scanf("%d", &q);
					if(q==0)
					{
						printf("\n");
						mainmenu(graph);
					}  
					break;
			}
		break;
	case 2: 
		printf("Find the path\n");
		printf("Please input start station (ID): ");
		scanf("%d", &s); 
		printf("Please input end station (ID): ");
		scanf("%d", &e); printf("\n");
		//BFS Algorithm
		if(s==e)
		{
			printf("could not input same start station and end station\n");
			mainmenu(graph);
		}
		else if(s<0 || s>165 || e<0 || e>165)
		{
			printf("please input a correct station id!\n");
		}
		else
			BFS(graph, s, e, q); 
		break;
	case 3:
		printf("Buy you ticket\n");
		printf("Please input start station (ID): ");
		scanf("%d", &s); 
		printf("Please input end station (ID): ");
		scanf("%d", &e); printf("\n");
		//BFS Algorithm
		if(s==e)
		{
			printf("could not input same start station and end station\n");
			mainmenu(graph);
		}
		else if(s<0 || s>165 || e<0 || e>165)
		{
			printf("please input a correct station id!\n");
		}
		else
			BFS(graph, s, e, q);
		break;
	default:
		printf("Please input a correct option!");
		printf("\n1.Check the line\n2.Check the path\n3.Purchase a ticket");
		break; 
	}
} 

void FareCalculator (Table *T,int s, int e) {
	int i;
	void *cs,*ce;
	double fare;
	for(i=0;i<TotalStation;i++)
	{
		if(T[i].id == s)
		{
			cs = &sd[i];
		}	
		else if(T[i].id == e)
		{
			ce = &sd[i];
			if(T[i].dist <= 13)
			{
				fare = 2 + (T[i].dist - 1);
			}
			else
				fare = 14;
		}
		else
			continue;	
	}
	printf("========================================\n");
	printf(" WELCOME TO SHENZHEN METRO!\n");
	printf(" Your ticket is:\n"); 
	printf(" -From: %s -To: %s",cs,ce);
	printf(" At least %d stops are required\n", T[e].dist);
	printf(" The price of ticket is %f(Yuan)\n",fare);	
	printf("========================================\n");
} 

void ShortestPath(Table *T, int e, LinkNode **head) {
	while(T[e].path != 999)
	{
		InsertNode(T[e].path, head);
		e = T[e].path;
	}	
}

void BFS(Graph *graph, int start, int end, int q) {
	int s = start, e = end;
	int V, W;
	
	LinkNode *head = NULL;
	Table T[TotalStation]; InitTable(s,T);
	AdjNode *p = NULL; 
	Queue *Q = NULL;
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
			if(T[W].dist == INT_MAX)
			{
				T[W].dist = T[V].dist + 1;
				T[W].path = V;
				enqueue(Q,W);
			} 
			p = p->next;
		} 
	}
	
	if(q==3)	 	
		FareCalculator(T,s,e);
	else if(q==2)
	{
		ShortestPath(T,e,&head);
		DisplayLinkedList(head);
	}

	
//	DisplayTable(T);	//Function for viewing the entire table, you can eliminate the the symbol of annotation for checking the whole table

//	DisposeQueue(Q);	//This function did not be created, coming soon	
}

int main(int argc, char *argv[]) {		
	FILE *fp = NULL;		//Initialing a object of FILE 
	int i = 0;				//Creating a factor of loop
	int j = 0;				//Creating a factor of loop
	//int len = 0;			//Testing the length of array content 
	
/* Loading a station dictionary */
	printf("Loading the dictionary of the station......\n"); 
	fp = fopen("file\\Metro.txt","r");
	if (!fp)
		return -1;
	while (!feof(fp))
	{
		fgets(sd[i++].name,50,fp);
	}
	fclose(fp);		//Closing the FILE stream 
/* Loading a station dictionary */

/* Loading the station of each line and mapping from name to id */
/* Tips: this section can add a Queue to avoid double loop that will cause time complexity equal to O(n^2) 
   especially some extreme situation, such as the inner loop was be performed until reach the [i]==165 */
	printf("Mapping from name to id for each station of each line......\n"); 
	//Mapping the line 1	
	fp = fopen("file\\Line1.txt","r");
	i=0;			//Initialing the factor of loop
	if (!fp)
		return -1;
	while (!feof(fp))
	{
		fgets(line1[i++].name,50,fp);
	}
	fclose(fp);
	for(j=0; j<30; j++)
	{
		line1[j].line=1;
		for(i=0; i<TotalStation; i++)
		{
			if(strcmp(sd[i].name,line1[j].name)==0)
			{
				line1[j].id = i;
				break;
			}
		}
	}
	
	//Mapping the line 2
	fp = fopen("file\\Line2.txt","r");
	i=0;			//Initialing the factor of loop
	if (!fp)
		return -1;
	while (!feof(fp))
	{
		fgets(line2[i++].name,50,fp);
	}
	fclose(fp);
	for(j=0; j<29; j++)
	{
		line2[j].line=2;
		for(i=0; i<TotalStation; i++)
		{
			if(strcmp(sd[i].name,line2[j].name)==0)
			{
				line2[j].id = i;
				break;
			}
		}
	}
	
	//Mapping the line 3
	fp = fopen("file\\Line3.txt","r");
	i=0;			//Initialing the factor of loop
	if (!fp)
		return -1;
	while (!feof(fp))
	{
		fgets(line3[i++].name,50,fp);
	}
	fclose(fp);
	for(j=0; j<30; j++)
	{
		line3[j].line=3;
		for(i=0; i<TotalStation; i++)
		{
			if(strcmp(sd[i].name,line3[j].name)==0)
			{
				line3[j].id = i;
				break;
			}
		}
	}
	
	//Mapping the line 4
	fp = fopen("file\\Line4.txt","r");
	i=0;			//Initialing the factor of loop
	if (!fp)
		return -1;
	while (!feof(fp))
	{
		fgets(line4[i++].name,50,fp);
	}
	fclose(fp);
	for(j=0; j<15; j++)
	{
		line4[j].line=4;
		for(i=0; i<TotalStation; i++)
		{
			if(strcmp(sd[i].name,line4[j].name)==0)
			{
				line4[j].id = i;
				break;
			}
		}
	}
	
	//Mapping the line 5
	fp = fopen("file\\Line5.txt","r");
	i=0;			//Initialing the factor of loop
	if (!fp)
		return -1;
	while (!feof(fp))
	{
		fgets(line5[i++].name,50,fp);
	}
	fclose(fp);
	for(j=0; j<27; j++)
	{
		line5[j].line=5;
		for(i=0; i<TotalStation; i++)
		{
			if(strcmp(sd[i].name,line5[j].name)==0)
			{
				line5[j].id = i;
				break;
			}
		}
	}
	
	//Mapping the line 7
	fp = fopen("file\\Line7.txt","r");
	i=0;			//Initialing the factor of loop
	if (!fp)
		return -1;
	while (!feof(fp))
	{
		fgets(line7[i++].name,50,fp);	
	}
	fclose(fp);
	for(j=0; j<28; j++)
	{
		line7[j].line=7;
		for(i=0; i<TotalStation; i++)
		{
			if(strcmp(sd[i].name,line7[j].name)==0)
			{
				line7[j].id = i;
				break;
			}
		}
	}
	
	//Mapping the line 9
	fp = fopen("file\\Line9.txt","r");
	i=0;			//Initialing the factor of loop
	if (!fp)
		return -1;
	while (!feof(fp))
	{
		fgets(line9[i++].name,50,fp);		
	}
	fclose(fp);
	for(j=0; j<22; j++)
	{
		line9[j].line=9;
		for(i=0; i<TotalStation; i++)
		{
			if(strcmp(sd[i].name,line9[j].name)==0)
			{
				line9[j].id = i;
				break;
			}
		}
	}
	
	//Mapping the line 11
	fp = fopen("file\\Line11.txt","r");
	i=0;			//Initialing the factor of loop
	if (!fp)
		return -1;
	while (!feof(fp))
	{
		fgets(line11[i++].name,50,fp);		
	}
	fclose(fp);
	for(j=0; j<18; j++)
	{
		line11[j].line=11;
		for(i=0; i<TotalStation; i++)
		{
			if(strcmp(sd[i].name,line11[j].name)==0)
			{
				line11[j].id = i;
				break;
			}
		}
	}
	printf("Loading success......\nMapping success......\nWelcome to Shenzhen Metro System!\n");
/* Loading the station of each line and mapping from name to id */	

/* Generating a new graph */
	int V = TotalStation;
	Graph *graph = newGraph(V);

	for(i=0; i<29; i++)
	{
		j=i+1;
		connectNodes(graph, line1[i].id, line1[j].id);
	} 
	for(i=0; i<28; i++)
	{
		j=i+1;
		connectNodes(graph, line2[i].id, line2[j].id);
	} 
	for(i=0; i<29; i++)
	{
		j=i+1;
		connectNodes(graph, line3[i].id, line3[j].id);
	} 
	for(i=0; i<14; i++)
	{
		j=i+1;
		connectNodes(graph, line4[i].id, line4[j].id);
	} 
	for(i=0; i<26; i++)
	{
		j=i+1;
		connectNodes(graph, line5[i].id, line5[j].id);
	} 
	for(i=0; i<27; i++)
	{
		j=i+1;
		connectNodes(graph, line7[i].id, line7[j].id);
	} 
	for(i=0; i<21; i++)
	{
		j=i+1;
		connectNodes(graph, line9[i].id, line9[j].id);
	}
	for(i=0; i<17; i++)
	{
		j=i+1;
		connectNodes(graph, line11[i].id, line11[j].id);
	}  
	//printf("\n"); 
	//printGraph(graph);
/* Generating a new graph */
	
	//testing();
	printf("\n");
	mainmenu(graph);
		
	return 0;
}
