//Soduku

#include<iostream>

#define N 9

using namespace std;

bool isFilled(int grid[N][N],int &row,int &col){
	
	for(row=0;row<N;row++){
		for(col=0;col<N;col++){
			if(grid[row][col] == 0)
				return true;
		}
	}
	
	return false;
}

bool rowCheck(int grid[N][N],int row,int num){
	int i;
	
	//cout<<num<<" ";
	
	for(i=0;i<N;i++){
		if(grid[row][i] == num)
			return true;
	}
	
	
	return false;
}

bool colCheck(int grid[N][N],int col,int num){
	int i;
	
	for(i=0;i<N;i++){
		if(grid[i][col] == num)
			return true;
	}
	
	//cout<<"f";
	return false;
}


bool boxCheck(int grid[N][N],int r,int c,int num){
	
	int row,col;
	
	for(row=0;row<3;row++){
		for(col=0;col<3;col++){
			if(grid[row+r][col+c] == num)
				return true;
		}
	}
	
//	cout<<"f";
	return false;
}



bool isSafe(int grid[N][N], int row, int col, int i){
	
	return !rowCheck(grid,row,i)&&!colCheck(grid,col,i)&&!boxCheck(grid,row-row%3,col-col%3,i);
}


bool solveSudoku(int grid[N][N]){
	
	int row,col,i;
	
	if(!isFilled(grid,row,col)){
		return true;
	}
	
//	cout<<grid[row][col]<<" ";
	
	for(i=1;i<=9;i++){		
		//cout<<i;
		if(isSafe(grid,row,col,i)){			
			grid[row][col] = i;
			
			if(solveSudoku(grid))
				return true;
			
			grid[row][col] = 0;
		}			
	}
	
	return false;
}

void printGrid(int grid[N][N]){
	
	int row,col;
	
	for(row=0;row<N;row++){
		for(col=0;col<N;col++){
			cout<<grid[row][col]<<" ";
		}
		cout<<"\n";
	}
}


int main(){
	 int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (solveSudoku(grid))
          printGrid(grid);
    else
         printf("No solution exists");
 
    return 0;
}
