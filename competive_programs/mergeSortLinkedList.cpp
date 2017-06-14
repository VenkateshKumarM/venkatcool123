//merge Sort For Linked List:

// 5 10 15 2 3 20

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

struct node* mergeSort(struct node** head){
	
	struct node* headref = *head;
	
	if(headref ==NULL || headref->next == NULL){
		return;
	}
	
	struct node* first = NULL;
	struct node* second = NULL;
	
	splitList(headref,&first,&second);
	mergeSort(&first);
	mergeSort(&second);
	*head = sortList(&first,&second);
}

void splitList(struct node* headref,struct node** first,struct node** second){
	struct node* fast, *slow;
	slow = headref;
	fast = (headref)->next;
	
	if(headref == NULL || headref->next =NULL){
		*first = hearef;
		*second = NULL;
		return;
	}
	
	while(fast!=NULL){
		fast = fast->next;
		if(fast!=NULL){
			fast = fast->next;
			slow = slow->next;
		}
	}
	
	*first = headref;
	*second = slow->next;
	 slow->next = NULL;
}

struct node* sortList(struct node** first,struct node** second){
		struct node* result =NULL;
	
		if(*first == NULL){
			result = *second;
			return result;
		}
		else if(*second == NULL){
			result = *first;
			return result;
		}			
			if((*first)->data <= (*second)->data){
				result = *first;
				result->next = sortList((*first)->next,*second);				
			}
			else {
				result = *second;
				result->next = sortList(*first,(*second)->next);			
			}				
			return (result);
}

int main(){
	struct node* head1=NULL;
	struct node* headptr= NULL;
	
	push(&head,15);
	push(&head,10);
	push(&head,5);	
	
	push(&head,20);
	push(&head,3);
	push(&head,2);
	
	printf("\nList1: ");
	printList(head);
		
 	mergeSort(&head);	
	
	printf("\nList: ");
	printList(head);
}

