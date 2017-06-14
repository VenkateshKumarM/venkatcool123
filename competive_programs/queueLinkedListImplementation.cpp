//Queue LinkedList Implementation

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct Qnode {	
	struct node* front, *rear;
};

struct Qnode* createQueue(){
	struct Qnode* qnode = (struct Qnode*)malloc(sizeof(struct Qnode));
	
	qnode->front = qnode->rear = NULL;
	
	return qnode;
}

struct node* createNode(int key){
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	
	temp->data = key;	
	temp->next = NULL;
	
	return temp;
}


void enqueue(struct Qnode* qnode, int key){
	
	struct node* temp = createNode(key);
	
	if(qnode->front == NULL){		
	//	printf("%d ", key);
		qnode->front = qnode->rear = temp;
		return;
	}	
	
//	printf("%d ", key);
	qnode->rear->next = temp;
	qnode->rear = temp;
} 

void dequeue(struct Qnode* qnode){
	
	if(qnode->front == NULL){
		printf("NULL");
		return;
	}
		
	qnode->front = qnode->front->next;
	
	if(qnode->front == NULL)
		qnode->rear = NULL;
}

void printList(struct Qnode* qnode){
	struct node* temp = qnode->front;
	
	printf("\n");
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

int main(){
	struct Qnode *qnode = createQueue();
	
	enqueue(qnode,1);
	enqueue(qnode,2);	
	enqueue(qnode,3);
	
	printList(qnode);
	
	dequeue(qnode);
	
	enqueue(qnode,1);
	
	printList(qnode);
}
