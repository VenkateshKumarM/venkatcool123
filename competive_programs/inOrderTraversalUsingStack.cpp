//Inorder Traversal Using Stack.

/* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */

#include<stdio.h>
#include<stdlib.h>

struct t_node {
	int data;
	t_node *left;
	t_node *right;	
};

struct s_node {
	t_node* tnode;
	s_node* next;
};

struct t_node* newNode(int data){
	
	struct t_node* newnode = (struct t_node*)malloc(sizeof(struct t_node));
	
	newnode->data = data;	
	newnode->left = NULL;
	newnode->right = NULL;
	
	return newnode;
}

bool isEmpty(struct s_node** snode){	
	return (*snode) == NULL ? true:false;
}

void push(struct s_node** snode,struct t_node* temp){
	
	struct s_node* stacknode = (struct s_node*)malloc(sizeof(struct s_node));
	
	stacknode->tnode = temp;
	stacknode->next = (*snode);
	 
	(*snode) = stacknode;
}


struct t_node* pop(struct s_node** snode){
	struct t_node* tempnode = (*snode)->tnode;
	
	(*snode) = (*snode)->next;
	
	return tempnode;	
}


void inOrderTraversalUsingStack(struct t_node* tnode){
	
	struct t_node* current = tnode;
	struct s_node* snode = NULL;
	
	bool flag = 1;
	int elem;
	
	while(flag){
		
		if(current != NULL){			
			push(&snode,current);
			
		//	printf("%d ",current->data);
			
			current = current->left;
		}
		else if(!isEmpty(&snode)){		
			
			struct t_node* tempnode = pop(&snode);
			
			printf("%d ",tempnode->data);

			current = tempnode->right;
		}
		else {
			flag =0;
		}		
	}	
}

int main(){
	struct t_node* tnode;	
	
	tnode = newNode(1);	
	tnode->left = newNode(2);	
	tnode->right = newNode(3);	
	tnode->left->left = newNode(4);	
	tnode->left->right = newNode(5);
	
	inOrderTraversalUsingStack(tnode);
}

