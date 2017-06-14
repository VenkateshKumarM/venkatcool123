// Length of Linked List Using Recursion

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

int length(struct node* headref){
	
	if(headref == NULL)
		return 0;
		
	return 1+length(headref->next);
}

int main(){
	struct node* head = NULL;
	
	int l;
	
	push(&head,3);
	push(&head,2);
	push(&head,1);
	push(&head,1);
		
	l=length(head);
	printf("Length=%d",l);
}
