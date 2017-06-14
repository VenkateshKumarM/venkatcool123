//Sorted Insert Circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

void insert(struct node** head,struct node* temp){

	struct node* current = (*head);
	
	if((*head) == NULL){
		temp->next = temp;
		(*head) = temp;
	}
	else if(current->data>temp->data){
		while(current->next!=(*head))
			current = current->next;
		
		current->next = temp;
		temp->next = (*head);	
		(*head) = temp;
	}
	else{
		while(current->next!=(*head)&&(current->next->data<temp->data))
			current = current->next;
			
		temp->next =  current->next;
		current->next = temp;	
	}	
}

void printList(struct node* headref){
	if(headref == NULL) return;
	
	struct node* temp = headref;
	do {
		printf("%d ",temp->data);
		temp = temp->next;
	} while(temp!= headref);
}


int main(){
	struct node* head = NULL;
	int arr[] = {12, 56, 2, 11, 1, 90};
  	int list_size, i;
	
	list_size = sizeof(arr)/sizeof(arr[0]);
	
	for(i=0;i<list_size;i++){
		struct node* temp = (struct node*)malloc(sizeof(struct node));	
		temp->data = arr[i];	
		insert(&head,temp);
	}
	
	printList(head);	
}
