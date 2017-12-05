//Detect Cycle in a UnDirected Graph.

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph{
	int V;
	list<int> *adjNode;
	public:
		Graph(int V);
		void addEdge(int src,int dest);
		bool isCyclic(); 
};

Graph::Graph(int V){
	this->V = V;
	adjNode = new list<int>[V];
}

void Graph::addEdge(int src,int dest){
	adjNode[src].push_back(dest);
	adjNode[dest].push_back(src);
}

bool isCyclicUtil(int i,int visited[],int parent){
	
	visited[i] = 1;
	
	list<int>::iterator itr;
	
	for(itr=adjNode.begin();itr!=adjNode.end();itr++){
		if(!visited[*itr])
			isCyclicUtil(*itr,visited,i);
		else if(*itr!=i)
			return true;
	}
	
	return false;
}

Graph::isCyclic(){	
	int visited[V];
	
	int i;
	for(i=0;i<V;i++){
		visited[i] = 0;
	}
	
	for(i=0;i<V;i++){
		if(!visited[i])
			isCyclicUtil(i,visited,-1);
	}
}

int main(){
	Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 0);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
                   
    return 0;               
}

