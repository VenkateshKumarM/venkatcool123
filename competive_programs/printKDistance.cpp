//Print nodes at k distance from root

/*   		1
          /   \
        2      3
      /  \    /
    4     5  8 
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* createNode(int data){
	
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
}

void printDistance(struct node* node,int k){
	if(node == NULL){
		return;
	}
	else if(k == 0){
		printf("%d ",node->data);
		return;
	}
	printDistance(node->left,k-1);
	printDistance(node->right,k-1);
}

int main(){
	
	struct node* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	
	root->left->left = createNode(4);
	root->left->right = createNode(5);	
	root->right->left = createNode(8);
	
	printDistance(root,2);
	
	return 0;
}
