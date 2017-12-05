//StripWiseInMatrix
#include<iostream>
#include<bits/stdc++.h>

#define N 5

using namespace std;

int main(){	
	int row,col;
	
	cout<<"Enter row:";
	cin>>row;
	
	cout<<"Enter Col:";
	cin>>col;
	
	int arr[N][N];
	
	int i,j;
	
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			cin>>arr[i][j];
		}
	}
	
	i=0;
	int k=0,m=row-1,l=0,n=col-1;
	
	while(k<m && l<n){
		
		for(i=l;i<=n;i++){
			cout<<arr[k][i]<<" ";
		}
		k++;
		
		for(i=k;i<=m;i++){
			cout<<arr[i][n]<<" ";
		}
		n--;
		
		for(i=n;i>=l;i--){
			cout<<arr[m][i]<<" ";
		}
		m--;
		
		for(i=m;i>=k;i--){
			cout<<arr[i][l]<<" ";
		}
		l++;
	}

	
	return 0;
}
