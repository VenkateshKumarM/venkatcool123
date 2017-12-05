//Hamiltonian Cycle --- Backtracking

#include<iostream>

#define V 5
using namespace std;


bool isSafe(bool graph[V][V],int path[V],int pos,int p){
	
	int i;
	
	if(graph[pos][path[p-1]] == 0 ){
		return false;
	}
	
	for(i=0;i<p;i++){
		if(path[i]==pos)
			return false;
	}
	
	return true;
}


bool hamCycleUtil(bool graph[V][V],int path[V],int v){
	
	int i;
	
	if(v == V){		
		cout<<"v";
		if(graph[path[0]][path[v-1]] ==1)	
			return true;
		else
			return false;			
	}
	
	for(i=1;i<V;i++){
		
		if(isSafe(graph,path,i,v)){		
			path[v] = i;
			
			if(hamCycleUtil(graph,path,v+1))
				return true;
			
			path[v] = -1;
		}
	}
	
	return false;
}

void printSol(int path[V]){
	int i;
	
	for(i=0;i<V;i++){
		cout<<path[i]<<" ";
	}
	
	cout<<path[0];
}

void hamCycle(bool graph[V][V]){
	
	int i,path[V];
	
	for(i=0;i<V;i++){
		path[i] = -1;
	}
	
	path[0] = 0;
	
	if(hamCycleUtil(graph,path,1)){
		printSol(path);
	}
	else {
		cout<<"False"<<"\n";		
	}
	
}


int main(){
	   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)-------(4)    */
   bool graph1[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
 
    // Print the solution
    hamCycle(graph1);
 
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)       (4)    */
    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };
 
    // Print the solution
    hamCycle(graph2);
 
    return 0;
}


