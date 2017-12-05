//Longest Path in a Directed Acyclic Graph

#include<iostream>
#include<bits/stdc++.h>
#include<stack>

#define NINF INT_MIN

using namespace std;

class AdjNode {
	int V;
	int W;
	public:
		AdjNode(int v,int w){
			V = v;
			W = w;
		}		
		int getV(){
			return V;
		}
		int getW(){
			return W;
		}
};

class Graph {
	int V;
	list<AdjNode> *listNode;	
	public:	
		Graph(int V);
		void addEdge(int src,int dest,int weight);
		void topologicalSort(int i,bool* visited,stack<int> &stack);
		void findDistance(int s);		
};

Graph::Graph(int V){
	this->V = V;
	listNode = new list<AdjNode>[V];
}

void Graph::addEdge(int src,int dest,int weight){	
	AdjNode adjNode(dest,weight);
	listNode[src].push_back(adjNode);
}


void Graph::topologicalSort(int i,bool* visited,stack<int> &Stack){
	
	visited[i] = true;
	
	list<AdjNode>::iterator itr;
	
	for(itr = listNode[i].begin(); itr!= listNode[i].end(); itr++){	
		AdjNode node = *itr;
		if(!visited[node.getV()])			
			topologicalSort(node.getV(),visited,Stack);
	}		
	
	Stack.push(i);
}

void Graph::findDistance(int s){
	
	stack<int> Stack;
	bool *visited = new bool[V];
	
	int i;
	
	for(i=0;i<V;i++){
		visited[i] = false;
	}
	
	for(i=0;i<V;i++){
		if(!visited[i])
			topologicalSort(i,visited,Stack);
	}
	
	int dist[V];
	
	for(i=0;i<V;i++)
		dist[i] = NINF;
	
	dist[s] = 0;
	
/*	for(i=0;i<V;i++){
		cout<<dist[i];
	}*/	
	
	while(Stack.empty() == false){
		int u = Stack.top();
		//cout<<u<< " ";
		Stack.pop();
		
		list<AdjNode>::iterator itr;
		
		if(dist[u] != NINF){
		
		for(itr = listNode[u].begin();itr!=listNode[u].end();itr++){			
			if(dist[itr->getV()] < dist[u]+itr->getW()){
				dist[itr->getV()] = dist[u]+itr->getW();
			}
		}		
		}
	}
		
	for(i=0;i<V;i++){
			dist[i] == NINF?cout<<"INF ":cout<<dist[i]<<" ";
		}	

}

int main(){
	Graph g(6);
	
	g.addEdge(0,1,5);
	g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
	
	g.findDistance(1);
	
	return 0;
}
