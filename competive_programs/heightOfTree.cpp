

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};	

struct node* newNode(int data){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}

/*		1
	   / \
	  2   3
	 / \
	4   5	*/
	
int heightOfTree(struct node* root){	
 if (root==NULL) 
       return 0;
   else
   {
       int lDepth = heightOfTree(root->left);
       int rDepth = heightOfTree(root->right);
 	
 	   printf("\nlDepth=%d",lDepth);
 	   printf(" rDepth=%d",rDepth);
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
}

void preOrder(struct node* root){
	
	if(root == NULL)
		return;
	printf("%d",root->data);
	
	preOrder(root->left);
	preOrder(root->right);
}

int main(){
	struct node* root = newNode(1);
	
	root->left = newNode(2);
	root->right = newNode(3);
	
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
 	preOrder(root);
 	
 	printf("\nheightOfTree = %d",heightOfTree(root));
	
	return 0;
}
