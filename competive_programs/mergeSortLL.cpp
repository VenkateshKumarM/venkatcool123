#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

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

void mergeSort(struct node** head){
	
	struct node* headref = *head;
	struct node* a;
	struct node* b;
	
	if(head == NULL || head->next == NULL){
		return;
	}
	
	split(headref,&a,&b);	
	mergeSort(&a);
	mergeSort(&b);
	*head = merge(a,b);
}

struct node* merge(struct node *a,struct node *b){
	
	struct node* res=NULL;
	
	if(a == NULL)
		return (b);
	else if(b == NULL)
		return (a);
	
	if(a->data <= b->data){
		res = a;		
		res->next = merge(a->next,b);
	}
	else {
		res = b;
		res->next =	merge(a,b->next);
	}
	return res;
}


void split(struct node* headref,struct node** a,struct node** b){
	
	struct node *slow, *fast;
	
	if(h == NULL || h->next == NULL){
		*a = headref;
		*b = NULL;
	}
	else {		
	slow = headref;
	fast = headref->next;
	
	while(fast!=NULL){
		fast = fast->next;
		if(fast!=NULL){
			slow = slow->next;
			fast = fast->next;
		}
	}
	
	*a= *headref;
	*b= slow->next;	
	slow->next = NULL;
	}
}

int main(){
	struct node* head = NULL;
		
	push(&head, 15);
	push(&head, 10);
	push(&head, 5);
	
	push(&head, 20);
	push(&head, 3);
	push(&head, 2);
	
	printf("List1:\n");
	printList(head);	
	
	headptr = mergeSort(&head);
	
	printf("Merged List:\n");
	printList(headptr);
}
