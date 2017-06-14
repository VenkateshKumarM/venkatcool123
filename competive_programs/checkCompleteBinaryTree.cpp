

/* Let us construct the following Binary Tree which
      is not a complete Binary Tree
            1
          /   \
         2     3
        / \     \
       4   5     6
    */

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 50 

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data){
	
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
}



struct node** createQueue(int* front,int* rear){
	
	struct node** queue = (struct node**)malloc(sizeof(struct node*)*MAX_SIZE);
	
	*front = *rear =0;
	
	return queue;
}

void enQueue(struct node** queue,int* rear,struct node* node){
	
	queue[*rear] = node;
	
	(*rear)++;
}

struct node* dequeue(struct node** queue, int* front){
	
	(*front)++;
	
	return queue[(*front)-1];
	
}


bool isQueueEmpty(int* front,int* rear){
	
	return *front == *rear;
}


bool isCompleteBT(struct node* root){
	
	if(root == NULL)
		return true;
	
	int front, rear;	
	struct node** queue = createQueue(&front,&rear);
	
	bool flag = false;
	
	enQueue(queue,&rear,root);
	
	while(!isQueueEmpty(&front,&rear)){
		
		struct node* tempnode = dequeue(queue,&front);
		
		if(tempnode->left != NULL){
			
			if(flag)
				return false;
			
			enQueue(queue,&rear,tempnode->left);
		}
		else
			flag = true;
		
		if(tempnode->right != NULL){
			
			if(flag)
				return false;
			
			enQueue(queue,&rear,tempnode->right);
		}
		else
			flag = true;
	}
	return true;
}
int main(){
	
	struct node* root = newNode(1);
	
	root->left = newNode(2);
	root->right = newNode(3);
	
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	root->right->right = newNode(6);
	
	if(isCompleteBT(root)){
		printf("Complete BT");
	}
	else{
		printf("InComplete BT");
	}
	
}
