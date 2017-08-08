//BST Insertion.

#include<iostream>
#include<stdlib.h>

using namespace std;
struct bstNode {
	int data;
	struct bstNode *left;
	struct bstNode *right; 
};

struct bstNode* createNode(int data){
	
	struct bstNode* node = (struct bstNode*)malloc(sizeof(struct bstNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

struct bstNode* insert(struct bstNode* root,int data){
	
	if(root == NULL){
		root = createNode(data);			
	}
	else if(data <= root->data){
		root->left = insert(root->left,data);
	}
	else {
		root->right = insert(root->right,data);
	}
	return root;	
}

bool search(struct bstNode* root, int data){
	
	if(root == NULL){
		return false;
	}
	else if(root->data == data){
		return true;
	}
	else if(data <= root->data){
		return search(root->left,data);
	}
	else {
		return search(root->right,data);
	}
}

int inOrder(struct bstNode* root){
	
	if(root->left !=NULL){
		inOrder(root->left);
	}
	
	int data = root->data;
	free(root);
	return data;
}

bool deletion(struct bstNode* root,int data){
	
	if(root == NULL){
		return false;
	}
	else if(root->data == data){
		if((root->left && root->right) == NULL){
			free(root);		
		}
		else if(root->right == NULL){
			root = root->left;
			free(root->left);
		}
		else if(root->left == NULL){
			root = root->right;
			free(root->right);
		}
		else {
			root->data = inOrder(root->right);	
			root = root->right; 
		}	
			return true;	
	}
	else if(data < root->data){
		return deletion(root->left,data);
	}
	else {
		return deletion(root->right,data);
	}
}

int main(){	
	struct bstNode* root = NULL;
	
	root = insert(root,5);	
	root = insert(root,6);
	root = insert(root,7);
	root = insert(root,8);
	root = insert(root,9);
	
	if(search(root,7)){
		cout<<"Found";
	}
	else {
		cout<<"Not Found";
	}
	
	cout<<deletion(root, 10);
}
