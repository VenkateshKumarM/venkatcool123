//Queue Implementation Using stack.

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Stack {
	int data;
	struct Stack* next;
}; 

struct Queue {
	Stack* stack1;
	Stack* stack2;   
};

void enqueue(struct Stack** stack,int data){
	
	Stack* stack1 = (struct Stack*)malloc(sizeof(struct Stack));
	stack1->data = data;
	
	//temp->stack1->next = ((queue)->stack1 == NULL) ? NULL : (queue)->stack1;					
	
	if(*stack == NULL){
		stack1->next = NULL;
	} else {
		stack1->next = (*stack);
	}
	
	(*stack) = stack1;
}

int dequeue(struct Queue* queue){		

	if((queue)->stack2 == NULL && (queue)->stack1 == NULL)	
		return -1;	
	
	if((queue)->stack2 == NULL) {
	
	while((queue)->stack1 !=NULL ){
			
		int data = 	queue->stack1->data;
		
	//	cout<<"Data:"<<data;
		Stack* stack2 = (struct Stack*)malloc(sizeof(struct Stack));
			
		if(queue->stack2 == NULL){
			stack2->data = data;
			stack2->next = NULL;					
		}
		else {			
			stack2->data = data;
			stack2->next = (queue)->stack2;
				
		}
		
		queue->stack2 = stack2;
		(queue)->stack1 = (queue)->stack1->next;	
		
		}
	}

	int data = queue->stack2->data;				
	
	queue->stack2 = queue->stack2->next;
	
	return data;	
}

int main(){
	Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));	
	
	queue->stack1 = NULL;
	queue->stack2 = NULL;		
	
	enqueue(&queue->stack1,5);	
	enqueue(&queue->stack1,6);	
	enqueue(&queue->stack1,7);	
	enqueue(&queue->stack1,8);	

	cout<<"\nElement Removed"<<dequeue(queue);	
	
	enqueue(&queue->stack1,9);
	
	cout<<"\nElement Removed"<<dequeue(queue);
	
	enqueue(&queue->stack1,10);
	
	cout<<"\nElement Removed"<<dequeue(queue);	
	cout<<"\nElement Removed"<<dequeue(queue);
	cout<<"\nElement Removed"<<dequeue(queue);
	cout<<"\nElement Removed"<<dequeue(queue);	
	
	enqueue(&queue->stack1,11);
	cout<<"\nElement Removed"<<dequeue(queue);		
	
	return 0;
}
