//Reverse Linked List

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

void push(struct node** headref, int data) {
	
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = (*headref);
	
	(*headref) =newnode;
}

void reverse(struct node** headref) {
	
	if(*headref == NULL || (*headref)->next == NULL)
		return;
	
	struct node* previous = NULL;
	struct node* current = *headref;
	struct node* after = NULL;
//	struct node* temp =NULL;
	
	while(current!=NULL){
		after = current -> next;
		current -> next = previous;
		previous = current;
		current = after;
	}
	*headref = previous;
}

void printList(struct node* headref){
	printf("\n");
	while(headref!=NULL){
		printf("%d",headref->data);
		headref = headref -> next;
	}
}

int main(){
	struct node* head = NULL;
	
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	
	printList(head);
	
	reverse(&head);
	printList(head);	
}
