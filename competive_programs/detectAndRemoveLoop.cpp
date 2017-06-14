#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* newNode(int data){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
	
	return newnode;
}

void printList(struct node* node){
	while(node!=NULL){
		printf("%d",node->data);
		node = node->next;
	}
}


/*void removeLoop(struct node* loopptr,struct node* headref){
	struct node* ptr1 = headref;
	struct node* ptr2;
	
	//printf("\nloopptr",loopptr->data);
	//printf("\nheadref",ptr1->data);
	
	while(1){
		ptr2 = loopptr;
		
		while(ptr2->next!=loopptr && ptr2->next!=ptr1)
			ptr2 = ptr2->next;
			
		if(ptr2->next == ptr1)
			break;
			
		ptr1 = ptr1->next;		
	}
	ptr2->next = NULL;
}*/

/*
void removeLoop(struct node* loopptr,struct node* headref){
	struct node* ptr1 = loopptr;
	struct node* ptr2 = loopptr;
	
	int k=1,i;
	
	while(ptr1->next!=ptr2){
		ptr1 = ptr1->next;
		k++;
	}	
	
	ptr1=headref;
	ptr2=headref;
	
	for(i=0;i<k;i++){
		ptr2 = ptr2->next;
	}
	
	while(ptr2!=ptr1){
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	
	ptr2 = ptr2->next;
	
	while(ptr2->next!=ptr1){
		ptr2 = ptr2->next;		
	}
	
	ptr2->next =NULL;
}*/


int detectAndRemoveLoop(struct node* headref){
	struct node* slowptr,*fastptr;
	slowptr = headref;
	fastptr = headref->next;
	
	while(slowptr && fastptr && fastptr->next){
		if(slowptr == fastptr){
			printf("Loop Found");
			break;
		//	removeLoop(slowptr,headref);
		//	return 1;
		}
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;

	}
	
	if(slowptr == fastptr)
	{
		slowptr = headref;
		while(fastptr->next!=slowptr){
				slowptr =slowptr->next;
				fastptr =fastptr->next;
		}
		fastptr->next = NULL;
	}
	return 0;
}


int main()
{
	struct node* head = newNode(5);
	head->next = newNode(6);
	head->next->next = newNode(7);
	head->next->next->next = newNode(8);
	head->next->next->next->next = newNode(9);
	head->next->next->next->next->next = newNode(10);
	
	printList(head);
	
	head->next->next->next->next->next->next = head->next;
	
	detectAndRemoveLoop(head);

	printList(head);	
}
