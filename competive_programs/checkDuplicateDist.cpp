#include<iostream>

using namespace std;

bool checkDuplicate(int a[],int m,int k){
	
	int i,dist;
	
	if(k==0)
		return true;
	
	if(k>=m)
		return false;	
	
	for(i=0;i<m;i++){
		dist = i+k;
		if(dist>=m){
			dist -= m-i;	
		}	
		if(a[i] == a[dist]){
			return true;
		}
	}
	
	return false;
}


int main(){
	int k = 3, arr[] = {1, 2, 3, 4, 4};
	
	int m = sizeof(arr)/sizeof(arr[0]);
	
	cout<<checkDuplicate(arr,m,k);
	
	return 0;
}
