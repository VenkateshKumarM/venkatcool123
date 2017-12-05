//DFS of Graph

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
o
class Graph {
	int V;
	list<int> *adj;
	list<int> visited;
	public:
		Graph(int V);
		void addEdge(int v,int w);
		void DFS(int s);
		void DFSUtil(int s);
};

Graph::Graph(int V){
	this->V = V;
	*adj = new list<int>[V];
}

Graph::addEdge(int v,int w){	
	adj[v].push_back(w);
}

Graph::DFSUtil(int s){
	
	cout<<s<<" ";
		
	visited[s] = 1;
	
	list<int>::iterator itr;
	
	for(itr=adj[s].begin();itr!=adj[s].end;itr++){
		if(!visited[*itr])
			DFSUtil(*itr);
	}
}

Graph::DFS(int s){
	int i;
	
	for(i=0;i<V;i++){
		visited[i] = 0;
	}
	
	cout<<"DFS:";
	
	DFSUtil(s,visited);
}


int main(){
	Graph g(5);
	
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,3);	
	g.addEdge(2,1);
	g.addEdge(3,1);
	g.addEdge(3,4);	
	g.addEdge(4,1);
	g.addEdge(4,3);		
	g.addEdge(4,0);
	
	return 0;	
}
