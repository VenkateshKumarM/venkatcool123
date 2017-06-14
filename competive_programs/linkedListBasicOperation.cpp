//push, append, insertAfter()

#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node {
	int data;
	struct node* next;
};

void push(struct node** head,int data){
	
	struct node* newnode = (struct node *)malloc(sizeof(struct node));
	
	newnode->data = data;	
	newnode->next = *head;	
	(*head) = newnode;	
}

void printList(struct node* n){
	while(n!=NULL){
		printf("%d",n->data);
		n= n->next;
	}
}

void insertAfter(struct node* prev,int data){
	
	if(prev == NULL){
		printf("the previous node is null");
		return;
	}
	
	struct node* newnode = (struct node *)malloc(sizeof(struct node));	
	newnode->data =data;	
	newnode->next = prev->next;	
	prev->next = newnode;	
}

void append(struct node** head,int data){
	
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	
	newnode->data =data;
	
	newnode->next = NULL;
	
	if(*head == NULL){
		*head = newnode;
		return;
	}
	
	struct node *last = *head;
	
	while(last->next!=NULL){
		last= last->next;
	}
	
	last->next = newnode;
}

int main(){
	struct node* head = NULL;
	
	push(&head,2);
	push(&head,3);	
	insertAfter(head->next,4);	
	printList(head);
	printf("\n");
	append(&head,5);
	printList(head);
}






