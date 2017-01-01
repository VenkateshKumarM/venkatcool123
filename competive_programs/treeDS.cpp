#include <iostream>

using namespace std;

struct node{
	int item;
	struct node *left;
	struct node *right;
};

struct node* newNode(int item){
	struct node *node = (struct node*)malloc(sizeof(struct node));
	node->item = item
	node->left = NULL;
	node->right = NULL; 
	return (node);
} 

int main(){
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left ->left = newNode(4);
	return 0;
}
