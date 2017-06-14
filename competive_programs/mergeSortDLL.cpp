//mergeSort DLL

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* prev;
	struct node* next;
};

void push(struct node** head, int data){
	
	struct node* newnode = (struct node*)malloc(sizeof(struct node));

	newnode->data = data;
	newnode->next = (*head);
	newnode->prev = NULL;
	
	if((*head)!=NULL)
		(*head)->prev = newnode;
	
	(*head) = newnode;	
}


void printList(struct node* node){
	printf("\n");
	while(node!=NULL){
		printf("%d",node->data);
		node = node->next;
	}	
}

struct node* split(struct node* headref){
	struct node* slow= headref, *fast = headref;
	while(fast->next && fast->next->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	struct node* second = slow->next;
	slow->next = NULL;
	return second;
}

struct node* merge(struct node* first,struct node* second){
	if(first == NULL)
		return second;
	if(second == NULL)
		return first;
	if(first->data <second->data){
		first->next = merge(first->next,second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	}
	else {
		second->next = merge(first,second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}
}

struct node* mergeSort(struct node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	struct node* second = split(head);
	mergeSort(head);
	mergeSort(second);
	return merge(head,second);
}

int main(){
	struct node* head=NULL;
	
	push(&head,5);
	push(&head,3);
	push(&head,1);
	push(&head,2);
	push(&head,4);
	
	printList(head);
	
	head = mergeSort(head);
	
	printList(head);
}
