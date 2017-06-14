#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* prev;
	struct node* next;
};

//push at the front
//2

void push(struct node** headref,int data){
	
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = (*headref);
	
	if(*headref!=NULL){
		(*headref)->prev = newnode;	
	}
	
	(*headref) = newnode;	
}

//insertAfter
// 2 3 1

void insertAfter(struct node* noderef,int data){
	
	if(noderef == NULL){
		printf("previous node should not be NULL");
		return;
	}
	
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->prev = noderef;	
	
	newnode->next = noderef->next;

	
	if(noderef->next!=NULL){
		noderef->next->prev = newnode;		
	}
	
	noderef->next = newnode;
}

//append at the last

void append(struct node** headref,int data){
	
	struct node* last = *headref;
	
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data =data;
	newnode->next = NULL;
	
	if(*headref == NULL){
		newnode->prev =NULL; 
		*headref = newnode;
		return;
	}
	
	while(last->next!=NULL){
		last = last->next;
	}
	
	last->next = newnode;
	newnode->prev = last;
}

//insertBefore

void insertBefore(struct node** headref,int data){
	if(*headref == NULL){
		printf("the previous node should not be null");
		return;
	}
	
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = *headref;
	
	if((*headref)->prev == NULL){
		newnode->prev = NULL;
		(*headref) = newnode;
		return;
	}
		
	(*headref)->prev->next = newnode;	
	newnode->prev = (*headref)->prev;		
	
}

//printList

void printList(struct node* headref){
	while(headref!=NULL){
		printf("%d",headref->data);
		headref = headref->next;
	}
}

int main(){
	struct node* head = NULL;
	push(&head,1);
	push(&head,2);
	push(&head,4);
		
	insertAfter(head->next,3);
	
	append(&head,5);
	append(&head,6);
	
	insertBefore(&head,7);
		
	printList(head);
}

