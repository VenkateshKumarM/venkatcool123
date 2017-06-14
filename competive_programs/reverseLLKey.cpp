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

int printList(struct node* headref){
	int count =0;
	while(headref!=NULL){
		printf("%d",headref->data);
		headref = headref->next;
		count++;
	}
	return count;
}

void reverseList(struct node** head,int k,int c){
	int temp = k;
	struct node* headref = *head;
	struct node* prev;
	struct node* tempnode;
	struct node* t;
	while(c>0){
		if(temp>c){
			temp=c;	
		}
		while(temp>0){
			*head = (*head)->next;
			temp--;
		}	
		prev = *head;
		printf("prev=%d",prev->data);
		while(temp>0){
			tempnode = headref->next;
			headref->next = prev;		
			prev = headref;			
			if(tempnode!=NULL)			
				headref = tempnode;
			temp--;		
		}
		temp+=k;
		c-=k;
	}
	printList(headref);
}

int main(){
	struct node* head=NULL;
	int count =0,key;
	push(&head,8);
	push(&head,7);
	push(&head,6);	
	push(&head,5);		
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);	
		
	printf("\nList: ");
	count =printList(head);	

    printf("Enter Key:");
    scanf("%d",&key);
    
 	reverseList(&head,key,count);	
	
}
