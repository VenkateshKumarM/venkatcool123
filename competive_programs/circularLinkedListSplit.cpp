//circular linked list split

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};


void insert(struct node** last,int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	
	if(*last == NULL){
		temp->next = temp;
		*last = temp;
		return;	
	}
	
	temp->next = (*last)->next;
	(*last)->next = temp;	
}


struct node* split(struct node** last){
	
	if((*last)==NULL || (*last)->next==(*last))
		return NULL;
	
	struct node* first = (*last)->next;
	struct node* second = (*last)->next;	
	
	while(second->next !=(*last)->next && second->next->next!=(*last)->next){
		first = first->next;
		second = second->next->next;
	}
	
	second = first ->next;
	
	first->next = (*last)->next;
		
	(*last)->next = second;
	
	return first;
}

void printList(struct node* last){
	
	if((last)==NULL)
		return;
	
	struct node* temp = last->next;
	do {
		printf(" %d",temp->data);
		temp = temp->next;
	}while(temp!=last->next);
}

int main() {
	struct node* last =NULL;
	struct node* first =NULL;
					
	printList(last);			
	
	first = split(&last);
	
	if(first!=NULL && last!=NULL){
	printf("\n");
	printList(first);
	
	printf("\n");
	printList(last);	
	}
}
