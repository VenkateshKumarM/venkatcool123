//Delete at position

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node** headref,int data){
	
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	
	newnode->data =data;
	newnode->next = (*headref);
	
	(*headref) = newnode;
}

void deletion(struct node** headref,int pos){
	
	struct node* temp =(*headref), *prevpos;
	
	if(pos ==0 && temp!=NULL){
		(*headref) =(*headref) ->next;
		free(temp);
		return;
	}
	
	while(temp!=NULL && pos>0){
		prevpos = temp;
		temp = temp->next;
		pos--;
	}
	
	if(temp == NULL){
		printf("position doesnt exist");
		return;
	}
	
	prevpos->next = temp->next;
	
	free(temp);
}

void printList(struct node* headref){
	while(headref!=NULL){
		printf("%d", headref->data);
		headref = headref ->next; 
	}
}

int main(){
	struct node* head =NULL;
	
	push(&head,4);	
	push(&head,3);
	push(&head,2);
	
	printList(head);
	
	deletion(&head,3);
	
	printf("\n");
	
	printList(head);
}
