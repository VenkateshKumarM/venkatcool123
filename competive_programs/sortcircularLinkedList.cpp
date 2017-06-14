//sort circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};


void printList(struct node* last){
	
	if((last)==NULL)
		return;
	
	struct node* temp = last->next;
	do {
		printf(" %d",temp->data);
		temp = temp->next;
	}while(temp!=last->next);
}

void insert(struct node** last,int data){
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
		
	if((*last)==NULL){
		temp->next = temp;
		(*last) = temp;
		return;
	}	
	
	struct node* first = (*last)->next;	
	struct node *prev = (*last);			
			
	do {
		if(first->data>data){
			temp->next = first;
			prev->next = temp;
			return;
		}
		prev = prev->next;	
		first = first->next;		
	} while(first != (*last)->next);				
	
	//prev = first ->next;
	first->next = temp;
	temp->next = prev->next;	
	(*last) = temp;	
	return;	
}



int main(){
	struct node* last = NULL;
	
	insert(&last,12);
	insert(&last,56);
	insert(&last,2);
	insert(&last,11);
	insert(&last,15);	
	insert(&last,7);
	insert(&last,1);
	insert(&last,1);	
	insert(&last,0);
	insert(&last,57);
	
	printList(last);
}
