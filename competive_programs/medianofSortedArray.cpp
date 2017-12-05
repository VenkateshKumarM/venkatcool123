//Median of two sorted arrays of same size

#include<iostream>
#include<bits/stdc++.h>

#define N 5

using namespace std;

int main(){
	int arr1[] = {1, 12, 15, 26, 38}, arr2[]= {2, 13, 17, 30, 45};
	
	int arr3[N+N];
	
	int i=0,j=0,k=0;
	
	while(i<N&&j<N){
		
		//cout<<i;	
		if(arr1[i]<=arr2[j]){
			arr3[k++] = arr1[i];
			i++;
		}
		else if(arr1[i]>arr2[j]){
			arr3[k++] = arr2[j];
			j++;
		}	
	
	}
	
	while(i<N){
		arr3[k++] = arr1[i];
		i++;
	}
	
	while(j<N){
		arr3[k++] = arr2[j];
		j++;
	}
	
	int n =2*N-1;
	
	if((n%2) != 0){
		cout<<(arr3[n/2]+arr3[(n/2)+1])/2;
	} else {
		cout<<arr3[n/2];
	}
	
}
