#include<stdio.h>
#include <math.h> 

int jumpSearch(int n,int arr[n],int find){
	int square = sqrt(n),i,res;
	for(i=0;i<n;i+=square){
		if(arr[i]>find)
			return linearSearch(n,arr,find,i-square);	
	}	
}

int linearSearch(int n,int arr[],int find,int start){
	int i;
	for(i=start;i<n;i++){
		if(arr[i]==find)
			return arr[i];
	}
}

int main(){
	int arr[] = {2,5,8,12,16,23,28,38,56,72,91};
	int n=11,find=56,f;
	f = jumpSearch(n,arr,find);
	cout<<"Index:"<<f;
}
