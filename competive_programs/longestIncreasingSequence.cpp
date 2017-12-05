//Longest Increasing Subsequence | Dynamic Programming

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int findIncreasingSequence(int a[],int n){
	
	int i,j,temp[n],max,inc;
	
	for(i=0;i<n;i++){
		temp[i] = 1;
	}
	
	for(j=1;j<n;j++){	
		max = 1;
		for(i=j-1;i>=0;i--){
			inc = 1;			
			if(a[j]>a[i]){
				inc += temp[i];				
				if(max<inc)
					max=inc;
			}
		}
		temp[j] = max;
 	}
 	
 	max =1;
 	
 	cout<<"\nTemp Array:";
 	for(i=0;i<n;i++){
 		cout<<temp[i];
 		if(max<temp[i])
 			max = temp[i];
	 }
	 
	cout<<"\n";
	 
	return max; 	
}


int main(){
	
	int arr[] =  {10, 22, 9, 33, 21, 50, 41, 60, 80};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	

	cout<<findIncreasingSequence(arr,size);
	
	return 0;
}
