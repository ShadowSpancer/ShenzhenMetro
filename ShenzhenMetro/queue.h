typedef struct Queue {
/* Using a struct to represent the queue*/
    int front;	
    int rear;
    int size;			//The number of factor in the queue
    unsigned capacity;	//The capacity of the queue
    int* array;			//Using array as the representing method (because we don't know the size of array, we need to use dynamic array)
}Queue; 
 
struct Queue* createQueue(unsigned capacity) {
/* Creating a queue */
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));		//Allocating the storage to the queue
    queue->capacity = capacity;			//Giving the capacity
    queue->front = queue->size = 0; 	//Initial the size as 0
    queue->rear = capacity - 1;  		//because the [0] be included the capacity, hence the rear=capacity-1
    queue->array = (int*)malloc(queue->capacity * sizeof(int));			//Allocating the storage to the array, determine the size of array
    return queue;
}
  
int isFull(struct Queue* queue) {  
	return (queue->size == queue->capacity);  //If size of queue equal to capacity of queue, the queue is full
}

int isEmpty(struct Queue* queue) {  
	return (queue->size == 0);				  //If the size of queue equal to 0, the queue is empty
}
 
void enqueue(struct Queue* queue, int item) {
/* A function of adding an item into the queue */
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;	//Point to the next position of the rear, if the rear is at the end of the team, the remainder is 0, then the return to the head position
    queue->array[queue->rear] = item;					//Enter the item into the queue
    queue->size = queue->size + 1;						//Increasing the size 
    //printf("%d enqueued to queue\n", item);
}
 
int dequeue(struct Queue* queue) {
/* A function of removing an item from the queue */
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];				//Assigning the information to the item, from the position of pointing by front
    queue->front = (queue->front + 1)%queue->capacity;	//Point to the next position of the front
    queue->size = queue->size - 1;						//Decreasing the size
    return item;
}

void makeEmpty(struct Queue* queue) {
/* A function of making the queue empty */
	queue->size = 0;
	queue->front = 0;
	queue->rear = queue->capacity-1;
}

