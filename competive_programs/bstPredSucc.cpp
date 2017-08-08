// predecessor and successor
       
#include<stdlib.h>
#include<iostream>

struct bstNode {
	int data;
	struct bstNode* left, *right;
};

struct bstNode* newNode(int data){	
	struct bstNode* node = (struct bstNode*)malloc(sizeof(struct bstNode));	
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}

struct bstNode* createNode(struct bstNode* root, int data){
	
	if(root == NULL){
		root = newNode(data);
	}
	else if(data < root->data){
		root->left = createNode(root->left,data);
	}
	else {
		root->right = createNode(root->right,data);
	}
	
	return root;
}

void findPreSuc(struct bstNode* root,struct bstNode* pred,struct bstNode* succ,int key){
	if(root->data == key){		
		if(root->left != NULL){
			struct bstNode* temp = root->left;
			while(temp->right != NULL){
				temp =  temp->right;
			}
			pred = temp;
		}
		if(root->right != NULL){
			struct bstNode* temp = root->left;
			while(temp->left != NULL){
				temp =  temp->left;
			}
			succ = temp;
		}		
		return;
	}
	if(key<root->data){
		succ = root;
		findPreSuc(root->left,pred,succ,key);
	}
	if(key>root->data){
		pred = root;
		findPreSuc(root->left,pred,succ,key);
	}
	
}

 /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

int main(){
	
	struct bstNode* root = NULL;
	int key = 65; 
	
	root = createNode(root,50);
	root = createNode(root,30);
	root = createNode(root,70);
	root = createNode(root,20);
	root = createNode(root,40);
	root = createNode(root,60);
	root = createNode(root,80);
	
	struct bstNode* pred = NULL;
	struct bstNode* succ = NULL;
	
	findPreSuc(root,pre,succ,key)
	
	if(pred != NULL){
		cout<<pred->data;
	} 
	if(succ != NULL){
		cout<<succ->data;
	}
	return 0;
}       
