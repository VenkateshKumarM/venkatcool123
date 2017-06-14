// 5 6 3 = 365
// 8 4 2 = 248
// 3 1 6 = 613

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

struct node* addNum(struct node** head1,struct node** head2){
	struct node* temp1 = *head1;
	struct node* temp2 = *head2;
	struct node* head3 =NULL;
	
	int res=0,temp=0;
	
	while(temp1!=NULL && temp2!=NULL){
		res = temp+temp1->data+temp2->data;
		
		if(res>=10){
			res = res%10;				
			temp=1;
		}
		else {
			temp=0;
		}			
		printf("\nhead=%d",res);
		push(&head3,res);
		
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	
	while(temp1!=NULL){
		res = temp + temp1->data;
		printf("\nhead=%d",res);
		if(res>=10){
			res = res%10;				
			temp=1;
		}
		else {
			temp=0;
		}
		push(&head3,res);
		temp1 = temp1->next;
	}
	
	while(temp2!=NULL){
		printf("\nhead=%d",res);
		res = temp + temp2->data;
		if(res>=10){
			res = res%10;				
			temp=1;
		}
		else {
			temp=0;
		}
		push(&head3,res);
		temp2 = temp2->next;		
	}	
	if(temp!=0){
		push(&head3,temp);
	}
	return head3;	
}


void printList(struct node* node){
	printf("\n");
	while(node!=NULL){
		printf("%d",node->data);
		node = node->next;
	}
}

struct node* reverse(struct node* headref){
	struct node* prev = NULL;
	struct node* current = headref;
	struct node* next;
	
	while(current!=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

int main() {
	struct node* head1 = NULL;
	struct node* head2 = NULL;
	struct node* head3 = NULL;
	
	push(&head1,7);
	push(&head1,5);
	push(&head1,9);
//	push(&head1,4);
//	push(&head1,6);
	
/*	push(&head1,5);
	push(&head1,6);
	push(&head1,3); */
	
	printList(head1);
	
	push(&head2,8);
	push(&head2,4);
	push(&head2,2);
	
	printList(head2);
	
	head1 = reverse(head1);
	printList(head1);
	head2 = reverse(head2);	
	printList(head2);
	
	head3 = addNum(&head1,&head2);
	printList(head3);
	
	printf("\n");

	//head3 = reverse(head3);
	//printList(head3);
	
}
