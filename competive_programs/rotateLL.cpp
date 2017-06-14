#include<stdio.h>
#include<stdlib.h>

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

int length(struct node* headptr,int len) {
	if(headptr==NULL)
		return len;	
	length(headptr->next,++len);
}

struct node* rotateList(struct node* headptr,int len,int k){
	if(len==0 || k ==0 || k == len){
		return headptr;	
	}	
	else if(k>len) {
		printf("Enter value less than length:");
		return NULL;
	}
	else {
		struct node* currenthead = headptr;
		struct node* newhead;
		
		while(k>0){
			if(k==1){
				newhead = headptr->next;
				headptr->next=NULL;
			}
			headptr = headptr->next;
			k--;
		}	
		
		struct node* temp = newhead;
		
		while(temp->next!=NULL){
			temp = temp->next;
		}		
		temp->next = currenthead;
		return newhead;	
	}	
}

void printList(struct node* node){
	printf("\n");
	while(node!=NULL){
		printf("%d ",node->data);
		node = node->next;
	}
}

 
int main() {
	struct node* head = NULL, *newhead;
	
	int len=0,k;
	
	push(&head,60);
	push(&head,50);
	push(&head,40);
	push(&head,30);
	push(&head,20);
	push(&head,10);
	
	len = length(head,0);
	
	printf("hw many times rotate:");
	scanf("%d",&k);	
//	printf("%d",len);	
	newhead = rotateList(head,len,k);
	printList(newhead);
}
