// Print a Binary Tree in Vertical Order. HashMap.

/*    	  1
        /   \
       2      3
      / \    /  \
     4   5  6   7
               / \
              8   9 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};


struct Node* createNode(int data){
	
	struct Node* newNode = new Node();	
	newNode->data = data;	
	newNode->left = newNode->right = NULL;	
	return newNode;
}

void printVerticalOrder(struct Node* node,int hd,map<int,vector<int> > &m){
	
	m[hd].push_back(node->data);
	
	if(node->left != NULL)
		printVerticalOrder(node->left,hd-1,m);
	
	if(node->right != NULL)
		printVerticalOrder(node->right,hd+1,m);
}

void verticalOrder(struct Node* node){
	
	//cout<<root->data;
	
	map<int,vector<int> > m;
	
	int hd = 0;
	
	printVerticalOrder(node,hd,m);	
	
	map<int,vector<int> > :: iterator itr;
	
	for(itr = m.begin();itr!=m.end();itr++){
		
		for(int i=0;i<itr->second.size();i++){
			cout<<itr->second[i] << " ";		
		}
			cout << endl;
	}
}

int main(){
	
	struct Node* root = createNode(1);
	
	root->left = createNode(2);	
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);	
	root->right->right = createNode(7);
	root->right->right->left = createNode(8);
	root->right->right->right = createNode(9);
	
	verticalOrder(root);
	
	return 0;
} 
