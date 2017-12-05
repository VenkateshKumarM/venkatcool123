//MinCost Path using Recursion

#include<stdio.h>
#include<limits.h>

#define R 3
#define C 3

int min(int i,int j,int k){
	if(i<j)
		return (i<k)?i:k;
	else
		return (j<k)?j:k; 
}

int minCostPath(int i,int j,int a[R][C]){
	
	if(i<0 || j<0)
		return INT_MAX;
	else if(i==0 && j==0){
		return a[i][j];	
    }
	else 
		return a[i][j]+min(minCostPath(i-1,j-1,a),minCostPath(i-1,j,a),minCostPath(i,j-1,a));	

}

int main(){	

	int arr[R][C] = {{1,2,3},{4,8,2},{1,5,3}};
	
	const int i=3,j=3;
	
	printf("minCostPath:%d",minCostPath(i-1,j-1,arr));
	
	return 0;	
}
