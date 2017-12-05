// N Queen Problem

#include<iostream>
#define N 4

using namespace std;

bool isSafe(int sol[N][N],int row,int col){
	int i,j;
	
	for(i=0;i<col;i++){
		if(sol[row][i])
			return false;			
	}
	
	for(i=row,j=col;i>=0&&j>=0;i--,j--){
		if(sol[i][j])
			return false;
	}
	
	for(i=row,j=col;i<=N&&j>=0;i++,j--){
		if(sol[i][j])
			return false;
	}
	
	return true;
}

bool nQueenAlgo(int sol[N][N],int col){
	
	if(col == N)
		return true;
	
	int i;
	
	for(i=0;i<N;i++){			
		if(isSafe(sol,i,col)){
			sol[i][col] = 1;
			
			if(nQueenAlgo(sol,col+1))
				return true;
			
			sol[i][col] = 0;	
		}		
		
	}	
	
	return false;
}

int main(){
	int sol[N][N],i,j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			sol[i][j] = 0;
		}
	}
	
	cout<<nQueenAlgo(sol,0)<<"\n";
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;		
}
