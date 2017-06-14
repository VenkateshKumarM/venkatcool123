#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* prev;
	struct node* next;
};


void push(struct node** head,int data){
	
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = (*head);
	
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

void swap(int* i,int* j){
	int temp = *i;
	*i = *j;
	*j = temp;
}

struct node* partition(struct node* head, struct node* last){        
	struct node* i = head->prev;         // 3 1 4 2 5	
	struct node* j = head;               // 1 3 4 2 5
	int pivot = last->data;
	
	printf("\n%d",pivot);
	for(j=head;j!=last;j=j->next){
		if(j->data<=pivot){
			i= (i == NULL)?head:i->next;
			printf("\n%d",i->data);
			printf("\n%d",j->data);
			swap(&(i->data),&(j->data));		
		}
	}
	i= (i == NULL)?head:i->next;
	swap(&(i->data),&(j->data));
	
	printList(head);
	return i;
}


void _quickSort(struct node* head, struct node* last){
	if(head!=NULL && last!=NULL && head!=last){
		struct node* pi = partition(head,last);
		_quickSort(head,pi->prev);
		_quickSort(pi->next,last);
	}
}


void quickSort(struct node* head){
	if(head == NULL || head->next == NULL)
		return;
	struct node* last = head;
	while(last->next!=NULL){
		last = last->next;
	}
	_quickSort(head,last);
}

int main(){
	struct node* head=NULL;

	push(&head,5);	
	push(&head,2);
	push(&head,4);	
	push(&head,1);
	push(&head,3);
	
	printList(head);	
	
	quickSort(head);
	
	printList(head);		
}
