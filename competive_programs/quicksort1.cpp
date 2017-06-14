//Quick Sort 

//3 1 5 4 2 

#include<iostream>
#include<stdlib.h>

using namespace std;


void swap(int *i,int *j){
	int temp;
	temp = *i;
	*i= *j;
	*j=temp;
}

int partition(int a[],int l,int h){
	
	int pivot = a[h];
	int i = l-1,j;
		
	for(j=l;j<h;j++){
		if(a[j]<pivot){
			i++;
			swap(&a[i],&a[j]);			
		}
	}
	swap(&a[i+1],&a[h]);
		
	return (i+1);
}


void quickSort(int a[],int l,int h){
	if(l<h){
		int pi = partition(a,l,h);
		quickSort(a,l,pi-1);
		quickSort(a,pi+1,h);
	}
}

int main(){
	int i,n,a[15];
	
	cout<<"Enter the array size:";
	cin>>n;
	
	for(i=0;i<n;i++)
		cin>>a[i];

	quickSort(a,0,n-1);
	
	for(i=0;i<n;i++)
		cout<<a[i];
}
