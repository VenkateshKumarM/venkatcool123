//Dequeue Implementation

// Insert Front
// Insert Rear
// delete Front
// delete Rear

// getFront.
// getRear.
// isEmpty.
// isFull

#include<stdio.h>
#include<stdlib.h>

struct Qnode {
	int data;
	struct Qnode* next;
};

struct Queue {
	struct Qnode *front, *rear;
};

struct Queue* createQueue(){
	
	struct Queue* queue = (struct Queue*)malloc(sizeof(Queue));
	
	queue->front = (struct Qnode*)malloc(sizeof(Qnode));
	
	queue->rear = (struct Qnode*)malloc(sizeof(Qnode));
	
	return queue;
}

struct Qnode* createNode(int data){
	struct Qnode* temp = (struct Qnode*)malloc(sizeof(Qnode));
	
	temp->data = data;
	temp->next = NULL;
	
	return temp;
} 

bool isEmpty(struct Queue* queue){
		
	if(queue->front == NULL)	
		return true;
}

void insertFront(struct Queue* queue, int data){
	
	struct Qnode* temp = createNode(data);
	
	if(isEmpty(queue)){			
		printf("true..");
		queue->front = temp;
		queue->rear = temp;		
		return;			
	}
	
	temp->next = queue->front;
	
	queue->front = temp;
	
}

void printList(struct Queue* queue){
	struct Qnode* qnode = queue->front;
	
	while(qnode != NULL){
		printf("%d",qnode->data);
		qnode = qnode->next;
	}
}

int main(){	
	struct Queue *queue = createQueue();
	
	insertFront(queue,1);
	
	insertFront(queue,2);	
	
	printList(queue);
}
