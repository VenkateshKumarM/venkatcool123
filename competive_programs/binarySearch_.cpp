//Binary Search..

#include<iostream>
#include<conio.h>

#define N 6

using namespace std;

int numToFind(int a[N],int left,int right,int num){
	
	int middle = (left+right)/2;
	
	if(num == a[middle]){
		return a[middle];
	}
	else if(num < a[middle] && left>=0 && right>=0 && left<N && right<N){
		right = middle -1;
		numToFind(a,left,right,num);		
	}
	else if(num > a[middle] && left>=0 && right>=0 && left<N && right<N) {
		left = middle+1;
		numToFind(a,left,right,num);	
	}
	else {
		return -1;
	}		
}


int main(){
	int arr[N] = {0,1,2,3,4,5};
	
	int num;
	
	cin>>num;
	
	cout<<numToFind(arr,0,N-1,num);
	
	return 0;
	
}
