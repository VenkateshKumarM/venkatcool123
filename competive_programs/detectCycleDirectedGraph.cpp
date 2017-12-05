//Detect Cycle in a Directed Graph.

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph{
	int V;
	list<int>* adjList;
	bool isCyclicUtil(int visited[], int recStack[],int i);
	public:
		Graph(int V);
		void addEdge(int src,int dest);
		bool isCyclic();		
};

Graph::Graph(int V){
	this->V = V;
	adjList = new list<int>[V];
}

void Graph:: addEdge(int src,int dest){
	adjList[src].push_back(dest);
}

bool Graph:: isCyclicUtil(int visited[], int recStack[],int i){
	
	if(visited[i] == false){
		
		visited[i] = true;
		recStack[i] = true;
		
		list<int>::iterator itr;
		
		for(itr=adjList[i].begin();itr!=adjList[i].end();itr++){
			if(!visited[*itr] && isCyclicUtil(visited,recStack,*itr))
				return true;
			else if(recStack[*itr])
				return true;
		}
	}
	
	recStack[i] = false;
	return false;
}


bool Graph::isCyclic(){

	int visited[V],recStack[V],i;
	
	for(i=0;i<V;i++) {
		visited[i]=0;
		recStack[i]=0;
	}
	
	for(i=0;i<V;i++){
		if(isCyclicUtil(visited,recStack,i))
			return true;
	}	
	
	return false;
}

int main(){
	Graph g(4);
	
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	
	cout<<g.isCyclic();
	
	return 0;
}
