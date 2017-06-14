//merge the given two linked list

// 5 10 15          2 3 20

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node {
	int data;
	struct node* next;
};

void push(struct node** headref,int data){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = (*headref);
	
	(*headref) = newnode;
}

void printList(struct node* headref){
	while(headref!=NULL){
		printf("%d",headref->data);
		headref = headref->next;
	}
}

void moveNode(struct node** dest, struct node** source){
	struct node* temp = *source;
	assert(*source!=NULL);
	*source = temp->next;
	
	temp->next =(*dest);
	(*dest) = temp;
	printf("\ntemp:%d",temp->data);
}

struct node* sortingMerge(struct node* head1,struct node* head2){		
	
	struct node dummy;
	struct node* tail = &dummy;
	dummy.next = NULL;
	
	if(head1 == NULL || head2 == NULL){
		return NULL;
	}

	
	while(head1!=NULL && head2!=NULL) {
		if(head1->data <= head2->data){			
			moveNode(&(tail->next),&head1);			
		//	printf("\nhead1:%d",head1->data);
		}
		else {	
			moveNode(&(tail->next),&head2);
		//	printf("\nhead2:%d",head2->data);
		}
		tail = tail->next;	
	}
	
	if(head1!=NULL){
		printf("\nhead1:%d",head1->data);
		tail->next = head1;		
	}
	
	if(head2!=NULL){
		printf("\nhead2:%d",head2->data);
		tail->next = head2;
	}
	return (dummy.next);
}	

int main(){
	struct node* head1=NULL;
	struct node* head2=NULL;
	struct node* headptr= NULL;
	
	push(&head1,15);
	push(&head1,10);
	push(&head1,5);	
	
	push(&head2,20);
	push(&head2,3);
	push(&head2,2);
	
	printf("\nList1: ");
	printList(head1);
	
	printf("\nList2: ");
	printList(head2);
		
 	headptr = sortingMerge(head1,head2);	
	
	printf("\nList: ");
	printList(headptr);
}
