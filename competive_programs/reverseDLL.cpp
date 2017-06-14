//reverse DLL.

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* prev;
	struct node* next;
};

void push(struct node** headref,int data){
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->prev = NULL;
	temp->next = (*headref);
	
	if((*headref)!=NULL){
		(*headref)->prev = temp;
	}
	
	(*headref) = temp;
}

void printList(struct node* temp){
	struct node* lastnode;
	printf("\n");
	while(temp!=NULL){
		printf("%d",temp->data);
		lastnode = temp;
		temp = temp->next;
	}
	printf("\n");
	while(lastnode!=NULL){
		printf("%d",lastnode->data);
		lastnode = lastnode->prev;
	}
}

void reverse(struct node** headref){ 
		struct node *temp =NULL;   	                        // NULL 10 8 4 2
	while(*headref!=NULL){								   //        2 4 8 10 NULL                         
		temp = (*headref)->prev;                           
		(*headref)->prev = (*headref)->next;
		(*headref)->next = temp;
		if(temp!=NULL){
			(*headref) = (*headref)->prev;
		}
	}
}

int main(){
	struct node* head = NULL;
	
  	push(&head, 2);
 	push(&head, 4);
  	push(&head, 8);
  	push(&head, 10);
	
	printList(head);
	
	reverse(&head);
	
	printf("\nReversed:");
	
	printList(head);	
}
