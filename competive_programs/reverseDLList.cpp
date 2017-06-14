//reverse DLL

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* prev;
	struct node* next;
};

void push(struct node** headref,int data){
	
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = (*headref);
	newnode->prev = NULL;
	
	if((*headref) != NULL)
		(*headref)->prev = newnode;
	
	(*headref) = newnode;	
}

void reverse(struct node** headref){
	
	struct node* current = *headref;
	struct node* temp;
	
	while(current!=NULL){
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}	
	
	if(temp!=NULL)
		*headref = temp->prev;
}

void printList(struct node* node){
	printf("\n");
	while(node!=NULL){
		printf("%d",node->data);
		node = node->next;
	}
}

int main(){
	struct node* head = NULL;
	
	push(&head,3);
	push(&head,2);
	push(&head,1);
	
	printList(head);
	
	reverse(&head);
	
	printList(head);
}
