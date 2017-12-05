//MinCost Path using Recursion

#include<stdio.h>

const int i=3,j=3;

int minCostPath(int i,int j,int a[][]){
	printf("%d %d",i,j);
	
	
	return 1;
}

int main(){	
	
	int arr[i][j] = {{1,2,3},{4,8,2},{1,5,3}};
	
	printf("minCostPath:%d",minCostPath(i,j,arr));
	
	return 0;	
}
