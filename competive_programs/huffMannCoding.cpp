//Huffmann Coding

#include<iostream>
#include<stdlib.h>

#define MAX 25

using namespace std;

struct minHeapNode {
	char ch;
	int data;
	struct minHeapNode* left;
	struct minHeapNode* right;
};

struct minHeap {
	int size;
	unsigned capacity;
	struct minHeapNode** array;
};

struct minHeapNode* createNode(char a,int data){
	
	struct minHeapNode* minheapnode = (struct minHeapNode*)malloc(sizeof(struct minHeapNode));
	
	minheapnode->ch = a;
	minheapnode->data = data;
	
	minheapnode->left = minheapnode->right = NULL;
	
	return minheapnode;
}

void swap(struct minHeapNode** a,struct minHeapNode** b){
	
	struct minHeapNode* temp;
	temp = *a;
	*a = *b;
	*b = temp;
	
}

struct minHeap* minHeapify(struct minHeap* minheap){
	
	int i, size = minheap->size-1, left, right, smallest;	
	
/*	cout<<"Before\n";
	
	for(i=0;i<=size;i++)
		cout<<minheap->array[i]->data<<" "; */
	
	for(i=(size-1)/2;i>=0;i--){
		
		left = 2*i+1;
		right = 2*i+2;
		smallest = i;
		
		if((left>0) && (left<minheap->size) &&(minheap->array[left]->data < minheap->array[i]->data)){
			smallest = left;	
		}
		if((right>0) && (right<minheap->size) &&(minheap->array[right]->data < minheap->array[smallest]->data)){
			smallest = right;
		}		
		
	//	cout<<"\nswapbefore:"<<minheap->array[i]->data;
		if(smallest != i){
			swap(&minheap->array[i],&minheap->array[smallest]);
			minHeapify(minheap);
		}		
	//	cout<<"\nswapafter:"<<minheap->array[i]->data; 
	}
	
/*	cout<<"After\n";
	
	for(i=0;i<=size;i++)
		cout<<minheap->array[i]->data<<" "; */
	
	return minheap;
}


struct minHeap* createMinHeap(char arr[],int data[],int size){
	
	struct minHeap* minheap = (struct minHeap*)malloc(sizeof(struct minHeap));
	
	minheap->size =0;
	minheap->capacity = size;
	
	minheap->array = (struct minHeapNode**)malloc(minheap->capacity * sizeof(struct minHeapNode*));
	
	int i;
	
	for(i=0;i<size;i++){
		minheap->array[i] = createNode(arr[i],data[i]);
	}
	
	minheap->size =  size;
	
	minHeapify(minheap);
	
	return minheap;
}

bool isOneSize(struct minHeap* minheap){
		//cout<<"\nSize:"<<minheap->size;
		return minheap->size == 1;
}

struct minHeapNode* extractMin(struct minHeap* minheap){
	
	struct minHeapNode* temp = minheap->array[0];
	
	//cout<<"\n"<<temp->data;
	
	minheap->array[0] = minheap->array[minheap->size-1];
	
	--minheap->size;
	
	minHeapify(minheap);
	
	return temp;
}

void insertMinHeap(struct minHeap* minheap,struct minHeapNode* top){
	
	++minheap->size;	
	int i= minheap->size-1;
	
	while(i>0 && minheap->array[(i-1)/2]->data > top->data){		
			minheap->array[i] = minheap->array[(i-1)/2];
			i = (i-1)/2;		
	}	
	
	minheap->array[i] = top; 
		
/*	cout<<"\nAfter:";
	for(i=0;i<minheap->size;i++)
		cout<<minheap->array[i]->data<<" ";  */
	
}

struct minHeapNode* buildHuffmanCoding(char arr[],int data[],int size){
	
	struct minHeapNode *left,*right,*top;
	
	struct minHeap *minheap = createMinHeap(arr,data,size);
	
	int i;
	
	while(!isOneSize(minheap)){
							
		left = extractMin(minheap);	
		right = extractMin(minheap);		
		
		top = createNode('$',left->data+right->data);
		
		top->left = left;
		top->right = right;
		
	//	cout<<"\nTop:"<<top->data;
		
		insertMinHeap(minheap,top);				
	}
	
	return extractMin(minheap);
}

bool isLeaf(struct minHeapNode* root){	
	return (root->left == NULL)&&(root->right == NULL);
}

void printArr(int arr[],int top){
	int i;
	
	for(i=0;i<top;i++){
		cout<<arr[i];
	}
}

void printCodes(struct minHeapNode* root, int arr[], int top){
	
	if(root->left){
		arr[top] = 0;
		printCodes(root->left,arr,top+1);
	}
	
	if(root->right){
		arr[top] = 1;
		printCodes(root->right,arr,top+1);
	}
	
	if(isLeaf(root)){
		cout<<"\n";
		cout<<root->ch<<": ";
		printArr(arr,top);
	}
}

int main(){
	
	char arr[] = {'a','b','c','d','e','f'};
	int freq[] = {5,9,12,13,16,45};
	
	int array[MAX], top=0;
	
	struct minHeapNode* minheapnode;
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
//	cout<<"Size:"<<size;
	
	minheapnode = buildHuffmanCoding(arr,freq,size);	
	
	printCodes(minheapnode,array,top);
	
	return 0;
}
