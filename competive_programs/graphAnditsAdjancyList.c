//	Graph and its Adjacency list representation

#include<stdio.h>
#include<stdlib.h>

struct AdjNode {
	int data;
	struct AdjNode* next;
};

struct AdjList {
	struct AdjNode* head;
};

struct Graph {
	int V;
	struct AdjList* adjList;
};

struct Graph* createGraph(int V){
	
	struct Graph* graphList = (struct Graph*) malloc(V*sizeof(struct Graph));

	int i;
	
	for(i=0;i<V;i++){
		graphList[i].adjList = (struct AdjList*) malloc(sizeof(struct AdjList));
		graphList[i].adjList->head =NULL;
	}
	
	return graphList;
}

struct AdjNode* createAdjNode(int data){
	struct AdjNode* adjNode = (struct AdjNode*)malloc(sizeof(struct AdjNode));
	
	adjNode->data = data;
	adjNode->next = NULL;
	
	return adjNode;
}

void createNode(struct Graph* graphList,int src,int dest){
	
	graphList[src].V = src;
	struct AdjNode* adjnode = createAdjNode(dest);
	
	adjnode->next = graphList[src].adjList->head;
	
	graphList[src].adjList->head = adjnode;
	
	
	graphList[dest].V = dest;
	adjnode = createAdjNode(src);
		
	adjnode->next = graphList[dest].adjList->head;
	
	graphList[dest].adjList->head = adjnode; 	
}

void printAdjancyList(struct Graph* graphList, int V){
	
	int i;
	
	printf("Graph Representation:");
	
	for(i=0;i<V;i++){
		
		printf("\n %d ->",i);
		
		struct AdjNode* head = graphList[i].adjList->head;				
		
		while(head!=NULL){
			printf("%d ", head->data);
			head = head->next;
		}
		
	}
}

int main(){
	int V =5;
	
	struct Graph* graphList = createGraph(V);
	
	createNode(graphList,0,1);
	
    createNode(graphList, 0, 4);
    createNode(graphList, 1, 2);
    createNode(graphList, 1, 3);
    createNode(graphList, 1, 4);
    createNode(graphList, 2, 3);
    createNode(graphList, 3, 4);
	
	
	printAdjancyList(graphList,V);
	return 0;
}
