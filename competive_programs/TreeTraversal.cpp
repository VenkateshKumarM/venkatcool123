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

struct t_node* newNode(int data){
	
	struct t_node* newnode = (struct t_node*)malloc(sizeof(struct t_node));
	
	newnode->data = data;	
	newnode->left = NULL;
	newnode->right = NULL;
	
	return newnode;
}

void inOrder(struct t_node* node){
	if(node == NULL)
		return;
	inOrder(node->left);
	printf("%d",node->data);
	inOrder(node->right);
}

void preOrder(struct t_node* node){
	
	if(node == NULL)
		return;
		
	printf("%d",node->data);
	
	preOrder(node->left);
	preOrder(node->right);	
	
}

void postOrder(struct t_node* node){
	
	if(node == NULL)
		return;
	
	postOrder(node->left);
	postOrder(node->right);
	
	printf("%d",node->data);
}

int main() {
	
	struct t_node* tnode;	
	tnode = newNode(1);	
	tnode->left = newNode(2);	
	tnode->right = newNode(3);	
	tnode->left->left = newNode(4);	
	tnode->left->right = newNode(5);
	
	inOrder(tnode);
	
	printf("\n");	
	preOrder(tnode);	
	printf("\n");	
	postOrder(tnode);
}
