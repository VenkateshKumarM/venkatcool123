//Heap Sort 3 5 1 4 6 2

		 3
	5	       1
4		6	2

#include<iostream>

using namespace std;

void heapSort(int a[],int n){
	
	int m = n/2;
	int i,l,r;

	for(i=0;i<m;i++){
		l =2*i+1;
		r =2*i+2;
		
		if(a[l]>a[r] && a[l]>a[i]){
			int temp;
			temp = a[i];
			a[i] = a[l];
			a[l] = temp;
		}
		else if(a[r]>a[l] && a[r]>a[i]){
			int temp;
			temp = a[i];
			a[i] = a[l];
			a[l] = temp;
		}
		
		if()
	}		
}


int main(){
	int a[15],i,j;
	
	cout<<"Enter the n val:";
	cin>>n;
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	heapSort(a,n);	
}
