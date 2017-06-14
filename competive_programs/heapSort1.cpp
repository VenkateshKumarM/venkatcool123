#include<iostream>

using namespace std;

void heapify(int a[],int n){
	
}

void heapSort(int a[],int n){
	for(i=0;i<(n/2)-1;i++)
		heapify(a,n);
	
	
}

int main(){
	int a[15],i;
	
	cout<<"Enter n val:";
	cin>>n;
	
	for(i=0;i<n;i++)
		cin>>a[i];
		
	heapSort(a,n);
}
