//Swapping of nodes in Linked List

#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node {
	int data;
	struct node* next;
};

void push(struct node** head,int data){	
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	
	newnode->data = data;
	newnode->next = (*head);
	
	(*head) = newnode;
}

void printList(struct node* headref){
		printf("\n");
	while(headref !=NULL){
		printf("%d",headref->data);
		headref = headref->next;
	}
}

void swap(struct node** headref,int data1,int data2){
	if(data1==data2)
		return;
		
	struct node* prevnode1 =NULL,*prevnode2=NULL,*currentnode1 =*headref, *currentnode2=*headref;
	
	while(currentnode1!=NULL && currentnode1->data != data1){
		prevnode1 = currentnode1;
		currentnode1 = currentnode1->next;
	}	
	
	while(currentnode2!=NULL && currentnode2->data != data2){
		prevnode2 = currentnode2;
		currentnode2 = currentnode2 -> next;
	}
	
	if(currentnode1 == NULL || currentnode2 == NULL){
		printf("Not found!");
		return;
	}
	
	if(prevnode1!=NULL)
		prevnode1->next = currentnode2;
	else
		*headref = currentnode2;
		
	if(prevnode2!=NULL)
		prevnode2->next = currentnode1;
	else
		*headref = currentnode1;
		
	
	struct node* temp = currentnode1->next;
	currentnode1->next = currentnode2->next;
	currentnode2->next = temp;	
			
}


int main(){
	struct node* head = NULL;
		
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	printList(head);	
	swap(&head,4,5);
	printList(head);
}
