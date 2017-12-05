//RatMaze Problem.

#include<stdio.h>

#define N 4

bool isSafe(int x,int y,int maze[N][N]){
//	printf("x:%d",x);
//	printf("y:%d",y);
//	printf("maze:%d",maze[x][y]);
	return ( (x>=0) && (x<N) && (y>=0) && (y<N) && maze[x][y]==1);
}

int ratMaze(int x,int y,int maze[N][N], int sol[N][N]){
	if(x == N-1 && y==N-1){
		sol[x][y] = 1;
		return true;
	}
	//printf("x:%d",x);
	//printf("y:%d",y);
	if(isSafe(x,y,maze)){
		sol[x][y] = 1;
		if(ratMaze(x+1,y,maze,sol))
			return true;
		else if(ratMaze(x,y+1,maze,sol))
			return true;
		else
			sol[x][y] = -1;
	}
	return false;	
}


int main(){
	int maze[N][N] = {{1, 0, 0, 0},{1, 1, 0, 1},{0, 1, 0, 0},{1, 1, 1, 1}};
	
	int sol[N][N], i,j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			sol[i][j] = 0;	
	}
	
	if(ratMaze(0,0,maze,sol)){
		for(i=0;i<N;i++){
			for(j=0;j<N;j++)
				printf("%d ",sol[i][j]);
			printf("\n");	
		}		
	}
	else {
		printf("Route not exist");
	}
	
	return 0;
}
