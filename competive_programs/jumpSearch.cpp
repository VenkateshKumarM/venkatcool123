#include<iostream>
#include <math.h> 

using namespace std;

int linearSearch(int n,int arr[],int find,int start){
	int i;
	for(i=start;i<n;i++){
		if(arr[i]==find)
			return i;
	}
	return -1;
}

int jumpSearch(int n,int arr[],int find){
	int square = sqrt(n),i=0,c=0;
	if(find>arr[n])
		return -1;		
	while(i<n){		
		if(arr[i]>=find){
			return linearSearch(n,arr,find,i-square);
		}
		i+=square;	
		if(c==0 && i>n){
			c++;
			i=n-1;
		}	
	}	
}

int main(){
	int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
	int n=11,find=55,f;
	f = jumpSearch(n,arr,find);
	cout<<"Index:"<<f;
}
