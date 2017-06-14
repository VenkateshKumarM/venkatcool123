//Deletion of Linked Linst

// 2 3 4

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

void push(struct node** head,int data){
		
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	
	newnode->data = data;
	newnode->next = (*head);
	
	*head = newnode;
}

void deletion(struct node** headref, int data){
	
	printf("\n");
	struct node* temp= *headref, *prev;
	
	if(temp != NULL && temp->data == data){
		(*headref) = (*headref)->next;
		free(temp);
		return;
	}
	
	while(temp != NULL && temp->data != data){
		prev = temp;
		temp = temp->next;
	}
	
	if(temp == NULL){
		printf("Number is not found!!");
		return;
	}		
		
	prev->next = temp->next;
	free(temp);			
}

void printList(struct node* headref){
	while(headref!=NULL){
		printf("%d",headref->data);
		headref = headref->next;
	}
}

int main(){
	struct node* head = NULL;
	
	push(&head,4);
	push(&head,3);	
	push(&head,2);
	
	printList(head);
	
	deletion(&head,4);	
	
	printf("\n");
	printList(head);
	
}
