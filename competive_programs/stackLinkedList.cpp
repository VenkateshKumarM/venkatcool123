// Stack Linked List Implementation

//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;
struct node {
	int data;
	struct node* next;
};

struct node* newnode(int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}



void push(struct node** root,int data){
	
	struct node* temp = newnode(data);
	
	if(*root == NULL){
		*root = temp;
		return;
	}
	
	temp->next = (*root);
	(*root) = temp;	
}

void pop(struct node** root){
	if(*root == NULL){
		cout<<"Empty";
		return;
	}
	struct node *temp = (*root);
	(*root) = (*root)->next;
	cout<<temp->data<<" ";
	free(temp);
}

int peek(struct node* stack){
	if(stack == NULL)
		return 0;
	return stack->data;	
}

void printList(struct node* stack){
	if(stack!=NULL){
		printf("%d ",stack->data);
		stack = stack->next;
	}
}
int main(){
	struct node* stack = NULL;
	push(&stack,2);
	push(&stack,1);
	
	printList(stack);
	
//	pop(&stack);
//	cout<<peek(stack);
}
