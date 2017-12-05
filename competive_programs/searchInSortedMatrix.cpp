//SearchInSortedMartrix

#include<iostream>

#define N 4

using namespace std;

bool searchInSortedMatrix(int a[N][N],int e){
	
	int i=0,j=N-1;
	
	while(i>=0&&i<N&&j>=0&&j<N){
		
		if(a[i][j] == e){
			cout<<i<<" "<<j;
			return true;
		}
		else if(a[i][j]>e){
			j=j-1;
		}
		else {
			i=i+1;
		}
	}
	
	return false;
}

int main(){
	int a[4][4] = {{10, 20, 30, 40},
                   {15, 25, 35, 45},
                   {27, 29, 37, 48},
                   {32, 33, 39, 50}};
	int e;
	cout<<"ElementToFind:";
	cin>>e;
	if(!searchInSortedMatrix(a,e))
		cout<<"Not Found";
	
	return 0; 
}
