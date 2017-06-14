//Circular Linked List


#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node* next;
};

void insertEmpty(struct node** lastptr, int data){
	
	if(*lastptr != NULL)
		return;
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data =data;
	temp->next = temp;
	*lastptr = temp;
}


void insertBeginning(struct node** lastptr, int data){
	if(*lastptr == NULL){
		insertEmpty(lastptr, data);
		return;
	}
		
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = (*lastptr)->next;
	(*lastptr)->next = temp;
}

void insertEnd(struct node** lastptr, int data){
	if(*lastptr == NULL){
		insertEmpty(lastptr, data);
		return;
	}
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = (*lastptr)->next;
	(*lastptr)->next = temp;
	(*lastptr) = temp;	
}

void insertBetween(struct node** lastptr, int data, int dataToInsert){
	if(*lastptr == NULL){
		insertEmpty(lastptr, data);
		return;	
	}
	
	struct node *temp;
	struct node *p=(*lastptr)->next;

	do {		
		if(p->data == data){
		    temp = (struct node*)malloc(sizeof(struct node));
			temp->data = dataToInsert;				
			temp->next = p->next;
			
			p->next = temp;			
			if(p==*lastptr){
				*lastptr =p;
			}
			return;			
		}
		p = p->next;
	}while(p!=(*lastptr)->next);	
}

void printList(struct node* last){
	
	if(*lastptr == NULL)
		return;
	struct node* temp = last->next;
	do {
		printf("%d",temp->data);
		temp = temp->next;
	} while(temp!=last->next);
}

int main(){
	struct node *last = NULL;
	
	insertEmpty(&last,3);
	insertBeginning(&last,1);
	insertEnd(&last,4);
	insertBetween(&last,1,2);
	
	printList(last);
}
