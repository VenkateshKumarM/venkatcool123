//graph Coloring

#include<iostream>

#define V 4
using namespace std;

bool isSafe(int graph[V][V],int col[V],int v,int c){
	
	int i;
	
	for(i=0;i<V;i++){
		if(graph[v][i] && c == col[i])
			return false;
	}
		
	return true;
}



bool isGraphColor(int graph[V][V], int col[V], int m, int v){

	int i;
		
	if(v == V)
		return true;
	else {
		
		for(i=1;i<=m;i++){
		
		if(isSafe(graph,col,v,i)){
			col[v] = i;
			if(isGraphColor(graph,col,m,v+1))
				return true;
			col[v] = 0;
			}
		}
		
		return false;
	}
}


void printSol(int col[V]){
	int i;
	
	for(i=0;i<V;i++){
		cout<<col[i];		
	}
		
}


bool graphColoring(int graph[V][V], int m){
	
	int col[V],i;
	
	for(i=0;i<V;i++){
		col[i] = 0;
	}
	
	if(isGraphColor(graph,col,m,0)) {
		printSol(col);
		return true;
	}		
	else 
		return false;
	
}


int main(){
	/* Create following graph and test whether it is 3 colorable
      (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */
    int graph[V][V] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3; // Number of colors
    graphColoring (graph, m);
    return 0;
}
