//Longest Increasing Subsequence.

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int longestIncreasingSubsequence(int arr[],int size){

	int i,j,a[size],max=1,output=1;
	
	for(i=0;i<size;i++)
		a[i] = 1;
	
	for(i=1;i<size;i++){
		output = 1;
		max = 1;
		for(j=i-1;j>=0;j--){
		
			if(arr[i] >arr[j]){
				max = a[i]+a[j];
				if(output<max)
					output = max;
			}
		}
		a[i] = output;
	}		
	
	max = a[0];
	for(i=1;i<size;i++){
		if(max<a[i])
			max=a[i];
	}

	return max;
}


int main(){
	int arr[] = {50, 3, 10, 7, 40, 80};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	cout<<longestIncreasingSubsequence(arr,size);
	
	return 0;
}
