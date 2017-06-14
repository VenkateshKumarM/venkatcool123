#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

void push(struct node** head,int data){
	struct node* newnode = (struct node*)malloc((sizeof(struct node)));
	newnode->data = data;
	newnode->next = (*head);
	(*head) = newnode;
}

void printList(struct node* headref){
	while(headref!=NULL){
		printf("%d",headref->data);
		headref = headref->next;
	}
}

struct node* reverse(struct node* head, int key){
	
	struct node* current = head;
	struct node* prev = NULL;
	struct node* next =NULL;
	
	int count=0;
	while(current!=NULL && count<key){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	
	if(next!=NULL)
		head->next = reverse(next,key);
	
	return prev;
}

int main(){
	struct node* head = NULL;
	
	push(&head,9);
	push(&head,8);	
	push(&head,7);
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	
	printf("\nList:");
	printList(head);
	
	head = reverse(head,3);

	printf("\nList:");
	printList(head);									
}
