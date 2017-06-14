//Queue Implementation

#include<stdio.h>
#include<stdlib.h>


struct Queue {
	int front;
	int rear;
	int capacity;
	int* array;
};

struct Queue* createQueue(int capacity){
	
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	
	queue->capacity = capacity;
	
	queue->rear = -1;
	
	queue->front = -1;
	
	queue->array = (int*)malloc(capacity * sizeof(int));
	
	if(queue->array != NULL)
		return queue;
	
	return NULL;
}


struct Queue* insert(struct Queue* queue, int data){
	
	if(queue->front > queue->capacity){
		printf("Overflow...");
		return queue;
	}
		
	
	if((queue)->rear == -1)
		++(queue)->front;
	
	queue->array[++queue->rear] = data;
	
	return queue;
}

void printList(struct Queue* queue){
	int i;
	
	for(i=0;i<=queue->front;i++)
		printf("%d",queue->array[i]);
}

struct Queue* dequeue(struct Queue* queue){
	
}

int main(){	
	
	struct Queue *queue = createQueue(5);	
	
	queue = enqueue(queue,2);	
	queue = enqueue(queue,3);	
	queue = enqueue(queue,4);
	
	queue = dequeue(queue);
	printList(queue);
	
	return 0;
} 
