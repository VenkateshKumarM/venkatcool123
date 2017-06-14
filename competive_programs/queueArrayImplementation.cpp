//Queue Array Implementation.

#include<stdio.h>
#include<stdlib.h>

struct Queue {
	int front;
	int rear;
	int size;
	unsigned capacity;
	int* array;
};


struct Queue* createQueue(unsigned capacity){
	
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;	
	queue->rear = queue->capacity - 1;
	queue->array = (int*)malloc(capacity * sizeof(int));
	
	return queue;	
} 

bool isFull(struct Queue* queue){
		return queue->size == queue->capacity;
}


bool isEmpty(struct Queue* queue){
		return queue->size == 0;
}


void enqueue(struct Queue* queue, int val){
	
	if(isFull(queue))
		return;
	
	queue->rear = (queue->rear+1) % queue->capacity;
	
	queue->size = queue->size+1;		
	
	queue->array[queue->rear] = val;	
	
	printf("%d enqueued to queue\n", queue->array[queue->rear]);
}

int dequeue(struct Queue* queue){
	
	if(isEmpty(queue))
		return -1;
		
	int item = queue->array[queue->front];	
		
	queue->front = (queue->front +1) % queue->capacity;
	
	queue->size = queue->size - 1;
			
	return item;		
}

int printFront(struct Queue* queue){	
	//printf("%d ", queue->front);
	
	//printf("%d ", queue->array[queue->front]);
	
	return queue->array[queue->front];
}

int printRear(struct Queue* queue){
	//printf("%d ", queue->rear);
	
	return queue->array[queue->rear];
}



int main(){
	struct Queue* queue = createQueue(4);
	
	enqueue(queue,2);
	
	enqueue(queue,3);
	
	enqueue(queue,4);
	
	enqueue(queue,5);
	
	printf("%d ", printFront(queue));
	
	printf("%d ", printRear(queue));
	
	dequeue(queue);
	
	printf("%d ", printFront(queue));
}
