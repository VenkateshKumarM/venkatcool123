//BFS for a Graph

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph {
	int V;
	list<int> *adj;
	public:
		Graph(int V);
		void addEdge(int v,int w);
		void BFS(int s);
};

Graph::Graph(int v){
	this->V = v;
	*adj =  new list<int>[V];
}

void Graph::addEdge(int v,int w){
	adj[v].push_bach(w);
}

void Graph::BFS(int s){
	
	int visited[V];
	
	int i;
	
	for(i=0;i<V;i++){
		visited[i]=0;
	}
	
	list<int> queue;
		
	visited[s] = 1;
	
	queue.push_back(s);
	
	list<int>::iterator itr;
	
	cout<<"BFS: ";
	
	while(!queue.empty()){	
	
		s = queue.front();
		cout<<s<<" ";
		
		queue.pop_front();
		
		for(itr=adv[s].begin();itr!=adv[s].end();itr++){		
			if(visited[*itr]!=1){
				visited[*itr] =1 ;
				queue.push_back(*itr);	
			}				
		}				
	}
}

int main(){	
	Graph g(5);
	
	g.addEdge(0,1);	
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
	
	g.BFS(2);
	return 0;
} 
