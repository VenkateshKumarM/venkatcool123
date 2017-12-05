//minCostPath 

#include<stdio.h>


//using namespace std;

const int m=3,n=3;

int min(int a,int b,int c){
	if(a<b)
		return a<c?a:c;
	else
		return b<c?b:c;
}

int minCostPath(int m,int n,int path[][n])
{
	int i,j, temp[3][3];
	
	temp[0][0] = path[0][0];
	
	j=0;	
	for(i=1;i<m;i++){
		temp[i][j] = temp[i-1][j] + path[i][j];
	}
	
	i=0;
	for(j=1;j<n;j++){
		temp[i][j] = temp[i][j-1] + path[i][j];
	}
	
	
	for(i=1;i<m;i++){
		for(j=1;j<n;j++){
				temp[i][j] = min(temp[i-1][j-1],temp[i][j-1],temp[i-1][j]) + path[i][j];
		}
	}
	
	return temp[m-1][n-1];
}


int main(){

	
	int path[][3] = {{1,2,3},{4,8,2},{1,5,3}};
	

	printf("MinCostPath:%d",minCostPath(m,n,path));
	
	return 0;
}
