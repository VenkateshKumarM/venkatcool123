//A program to check if a binary tree is BST or not

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct bstNode {
	int data;
	struct bstNode *left;
	struct bstNode *right;
};

struct bstNode* createNode(int data){
	struct bstNode* bstnode = (struct bstNode*)malloc(sizeof(struct bstNode));
	
	bstnode->data = data;
	bstnode->left = NULL;
	bstnode->right = NULL;
	
	return bstnode;
}


struct bstNode* insertBST(struct bstNode* root, int data){
	
	if(root == NULL){
		root = createNode(data);		
	}
	
	else if(data < root->data){
		root->left = insertBST(root->left, data);
	}
	
	else {
		root->right = insertBST(root->right, data);		
	}
	
	return root;
}

bool checkBST(struct bstNode* temp,int data,int ch){
	
	if(temp->left != NULL){
		treeTraversal(temp->left,temp->data,"l");
	}
	
	if(data < temp->data)
		return false;
	
	if(temp->right != NULL){
		treeTraversal(temp->right,temp->data,"r");
	}	
}


int main(){	
	struct bstNode* root = NULL;
	
	root = insertBST(root,8);
	
	root = insertBST(root,3);
	root = insertBST(root,10);
	root = insertBST(root,1);
	root = insertBST(root,6);
	root = insertBST(root,14);
	root = insertBST(root,4);
	root = insertBST(root,7);
	root = insertBST(root,13);					
	
	cout<<checkBST(root,root->data,"r");
	
	return 0;
}
