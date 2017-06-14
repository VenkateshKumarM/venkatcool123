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
//	struct node* lastnode= NULL;
	printf("\n");
	while(temp!=NULL){
		printf("%d",temp->data);
		//lastnode = temp;
		temp = temp->next;
	}
	printf("\n");
/*	while(lastnode!=NULL){
		printf("%d",lastnode->data);
		lastnode = lastnode->prev;
	}*/
}

void deletion(struct node** headref,int data){
	struct node* temp=NULL;
	int count=0;	
	temp= (*headref);
	
	if((*headref)->data == data){

		(*headref) = (*headref)->next;
		if((*headref)!=NULL)
			(*headref) -> prev = NULL;	

		free(temp);
	}
	else {
		
		while(temp->data!=data){
			temp = temp->next;
			count =1;
		}
		
		if(count){
		
		temp->prev->next = temp->next;
		
		if(temp->next!=NULL){
			temp->next->prev = temp->prev;
		}
		
		free(temp);
		}
		else {
			printf("Not Found!!");
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
	
	deletion(&head,10);
	deletion(&head,4);
	deletion(&head,2);
	deletion(&head,2);
			
	//if(head!=NULL)
		printList(head);	
}
