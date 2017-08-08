//Sorted Huffman coding

#include<iostream>
#include<stdlib.h>

#define MAX 15

using namespace std;
struct QueueNode {
	int data;
	char ch;
	struct QueueNode* left, *right;
}; 

struct Queue {
	int size, front, rear;
	struct QueueNode** array;
};

struct Queue* createEnqueue(int size){
	
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	
	queue->array = (struct QueueNode**)malloc(size * sizeof(struct QueueNode));
	
	queue->front = queue->rear = -1;
	
	queue->size = size;
	
	return queue;
}

struct QueueNode* createNode(char ch,int data){
	
	struct QueueNode* queueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	
	 queueNode->ch = ch;
	 queueNode->data = data;
	 
	 queueNode->left = queueNode->right = NULL;
	 
	 return queueNode;
};

bool isEmpty(struct Queue* queue){
	return queue->front == -1; 
}

struct QueueNode* deQueue(struct Queue* queue){
	
	struct QueueNode* queueNode = queue->array[queue->front];
	
	if(queue->front == queue->rear){
		queue->front = queue->rear =-1;
	}
	else {
		++queue->front;	
	}		
	
	return queueNode;
}

void enQueue(struct Queue* queue,struct QueueNode* top){
	
	if(queue->front == -1){
		++queue->front;
		++queue->rear;
		queue->array[queue->front] = top;
	}
	else {
		queue->array[++queue->rear] = top;
	}
	
}

bool isOneSize(struct Queue* queue){
	
	return queue->size == 1;
}


struct QueueNode* findMin(struct Queue* firstQueue,struct Queue* secondQueue){
	
		if(isEmpty(secondQueue)){
		//	cout<<"\n1front:"<<firstQueue->front;
			return deQueue(firstQueue);
		}
				
		if(isEmpty(firstQueue)){
		//	cout<<"\n2front:"<<secondQueue->front;
			return deQueue(secondQueue);	
		}		
		
		if(!isEmpty(firstQueue) && !isEmpty(secondQueue)){
					
			if(firstQueue->array[firstQueue->front]->data < secondQueue->array[secondQueue->front]->data){
			//	cout<<"\n3front:"<<firstQueue->front;
				return deQueue(firstQueue);					
			}				
			
		//	cout<<"\n4front:"<<secondQueue->front;
			return deQueue(secondQueue);					
		}	
}

struct QueueNode* buildHuffmanTree(char arr[],int data[],int size){
	
	struct Queue* firstQueue, *secondQueue;
	
	firstQueue = createEnqueue(size);
	secondQueue = createEnqueue(size);
	
	int i;
	for(i=0;i<size;i++)
		firstQueue->array[i] = createNode(arr[i],data[i]); 
	
	firstQueue->size = size-1;	
	firstQueue->front = 0;
	firstQueue->rear = size-1;
/*	for(i=0;i<size;i++)
		cout<<firstQueue->array[i]->data<<" ";	*/
	
//	cout<<isEmpty(firstQueue);
//	cout<<isOneSize(secondQueue);
		
	while(!isEmpty(firstQueue)&&!isOneSize(secondQueue)){
		
		struct QueueNode* top, *left, *right;
		
		cout<<"\n";
		
		left = findMin(firstQueue,secondQueue);
		right = findMin(firstQueue,secondQueue);
		
		//cout<<"Left:"<<left->data;
		//cout<<"Right:"<<right->data;
		
		top = createNode('$',left->data+right->data);
		
		top->left = left;
		top->right = right;			
		
		enQueue(secondQueue,top);
	}
	
	return deQueue(secondQueue);
}

void printArr(int arr[],int top){
	int i;
	for(i=0;i<top;i++){
		cout<<arr[i];
	}
}

bool isLeafNode(struct QueueNode* queueNode){
	return (queueNode->left == NULL && queueNode->right == NULL);
}


void printCode(struct QueueNode* queueNode,int arr[],int top){
	
	if(queueNode->left != NULL ){
		arr[top] = 0;
		printCode(queueNode->left,arr,top+1);
	}
	
	if(queueNode->right != NULL){
		arr[top] = 1;
		printCode(queueNode->right,arr,top+1);
	}
	
	if(isLeafNode(queueNode)){
		cout<<"\n";
		cout<<queueNode->ch<<":";
		printArr(arr,top);
	}
	
}

void inOrderTraversal(struct QueueNode* queueNode){

	if(queueNode->left != NULL){
		inOrderTraversal(queueNode->left);			
	}	
	
	cout<<queueNode->data<<" ";
	
	if(queueNode->right != NULL){
		inOrderTraversal(queueNode->right);
	}				
	
}

void preOrderTraversal(struct QueueNode* queueNode){
		
	cout<<queueNode->data<<" ";
	
	
	if(queueNode->left != NULL){
		preOrderTraversal(queueNode->left);			
	}	
			
	if(queueNode->right != NULL){
		preOrderTraversal(queueNode->right);
	}				
	
}

void postOrderTraversal(struct QueueNode* queueNode){
	
	if(queueNode->left != NULL)
		postOrderTraversal(queueNode->left);	
	
	if(queueNode->right != NULL)
		postOrderTraversal(queueNode->right);
		
	cout<<queueNode->data<<" ";	
}


int main(){
	char arr[] = {'a','b','c','d','e','f'};
	int freq[] = {5,9,12,13,16,45};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	int a[MAX];
	
	struct QueueNode* queueNode;
	
	queueNode = buildHuffmanTree(arr,freq,size);

//	postOrderTraversal(queueNode);
	
//	cout<<queueNode->left->data;
	
	printCode(queueNode,a,0);
	
	return 0;
}
