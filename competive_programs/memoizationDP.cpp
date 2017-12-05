//find fibonacci Num using Memoization

#include<iostream>
#include<bits/stdc++.h>

#define MAX 25

using namespace std;

void _intialize(int arr[],int max){
	int i;	
	for(i=0;i<max;i++){
		arr[i] = -1;
	}
}

int findFibo(int arr[],int n){
	
	if(arr[n] == -1){
		if(n<=1){
			arr[n] = n;	
		//	return n;
		}
		else {
			arr[n] = findFibo(arr, n-1) + findFibo(arr, n-2);
		}
	}
	
//	if(arr[i] != NIL)
		return arr[n];
}


int main(){
	int arr[MAX],n;
	
	cout<<"Enter the no to find";
	cin>>n;
	
	_intialize(arr,MAX);
	
	cout<<findFibo(arr,n-1);
	
	return 0;
}
