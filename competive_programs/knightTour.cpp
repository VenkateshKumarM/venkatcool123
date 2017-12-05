// The Knight’s tour problem

#include<iostream>
#include<bits/stdc++.h>
#define N 8

using namespace std;

bool isSafe(int x,int y,int sol[][N]){	
	return ((x>=0) && (x<N) && (y>=0) && (y<N) && sol[x][y] == -1);
}


bool tourKnight(int x,int y,int movei,int sol[N][N],int moveX[N],int moveY[N]){

	int k,nextX,nextY;
//	cout<<"a";
//	cout<<movei;
	
	if(movei == N*N)
		return true;
	
	for(k=0;k<8;k++){
		nextX = x + moveX[k];
		nextY = y + moveY[k];
		
	//	cout<<"isSafe:"<<isSafe(nextX,nextY,sol)<<" ";
		
		if(isSafe(nextX,nextY,sol)){
			sol[nextX][nextY] = movei;
			
			if(tourKnight(nextX,nextY,movei+1,sol,moveX,moveY)== true)
				return true;
			else
				sol[nextX][nextY] = -1;
		}		
	}
	
	return false;
}

void printSol(int sol[][N]){
	int i,j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main(){
	int sol[N][N], i, j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			sol[i][j] = -1;	
		}
	}
	
	int moveX[N] = { 2, 1, -1, -2, -2, -1,  1,  2};
	int moveY[N] = { 1, 2,  2,  1, -1, -2, -2, -1};
	
	sol[0][0] =0;
	
	if(tourKnight(0,0,1,sol,moveX,moveY))	
		printSol(sol);
	else 
		cout<<"false";
	
	return 0;
				
}
