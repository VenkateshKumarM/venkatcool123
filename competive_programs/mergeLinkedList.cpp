// Merge the Sorted Linked List.
// 5->10->15  2->3->20
// 2->3->5->10->15->20

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

void push(struct node** headref, int data){
	
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
// source { 1, 2, 3 }
// dest   { 1, 2, 3 }
// dest { 1, 1, 2, 3}
void moveNode(struct node** a,struct node** b){
	
	struct node* bref = *b;
	
	assert(b !=NULL);
	
	(*b)->data = (*a)->data;
	(*b)->next = bref; 
	
	*a = (*a)->next;
}

struct node* mergetList(struct node** a,struct node** b){
	
	struct node dummy;	
	
	struct node* tail = &dummy;
	dummy.next = NULL;
	
	while(1){
		if(*a == NULL){
			tail->next = *b;
		}
		else if(*b == NULL){
			tail->next = *a;
		}
		else {
			if((*a)->data <= (*b)->data){
				moveNode(&(tail->next),*a);
			}
			else {
				moveNode(&(tail->next),*b);
			}
		}
	}
	
	return dummy.next;
}

int main(){
	struct node* head1 = NULL;
	struct node* head2 = NULL;
	struct node* headptr = NULL;
		
	push(&head1, 15);
	push(&head1, 10);
	push(&head1, 5);
	
	push(&head2, 20);
	push(&head2, 3);
	push(&head2, 2);
	
	printf("List1:\n");
	printList(head1);
	
	printf("List2:\n");
	printList(head2);	
	
	headptr = mergeList(&head1,&head2);
	
	printList(headptr);
}

