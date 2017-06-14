//circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

void insert(struct node** headptr, int data){
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	
	struct node* first = *headptr;
	
	if(*headptr == NULL){
		temp->next =temp;
		*headptr = temp;
		return;
	}
	
	do{
		if(first->next == *headptr){
			temp->next = first->next;
			first->next = temp;
			*headptr = temp;
			return;
		}
		first = first->next;
	}while(first!=*headptr);
}


void traverse(struct node* head){
	struct node* temp = head;
	if( head == NULL)
		return;
	do {
		printf("%d",temp->data);
		temp= temp->next;
	}while(temp!=head);
}

int main(){	
	struct node* head = NULL;
	
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	
	traverse(head);
}
