#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph{
	int V;
	list<int>* adjList;
	public:
		Graph(int V);
		void addEdge(int src,int dest);
		int isCyclic();
};

Graph::Graph(int V){
	this->V = V;
	adjList = new list<int>[V]; 
}

void addEdge(int src, int dest){
	adjList[src].push_back(dest);
}

void isCyclicUtil(int i, int visited[], int recStack[]){
	
	if(visited[i]==false){
		visited[i]=true;
		recStack[i]= true;
		
		AdjList::iterator itr;
		
		for(itr= adjList.begin();itr!=adjList.end();itr++){
			
			if(!visited[*itr] && isCyclicUtil(*itr, visited, recStack))
				return true;
			else if(recStack[i])
				return true;
				
		}
		
	}
	else {
		recStack[i]= false;
		return false;
	}
}

Graph::isCyclic(){
	
	int visited[V], recStack[V];
	
	for(i=0;i<V;i++){
		visited[i] = false;
		recStack[i] = false;		
	}
	
	for(i=0;i<V;i++){
		if(isCyclicUtil(i,visited,recStack))
			return true;
	}
	
	return false;
}

int main(){
	
	Graph g(4);
	
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,0);
	
	cout<<g.isCyclic();
	
	return 0;
}
