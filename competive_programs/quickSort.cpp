#include<iostream>

using namespace std;

void swap(int* i,int* j){
	int temp;
	temp =*i;
	*i =*j;
	*j = temp;
}

int partition(int a[],int start,int end){
	int pIndex=start;
	int pivot=a[end];
	int i;
	for(i=start;i<end;i++){
		if(a[i]<pivot){
			cout<<"before:";
			cout<<a[pIndex]<<a[i];
			swap(a[pIndex],a[i]);
			cout<<"after:";
			cout<<a[pIndex]<<a[i];
			pIndex++;			
		}
	}
	swap(a[pIndex],a[end]);
	return pIndex;
}

void quickSort(int a[],int i,int n){
	if(i<n){
		int pIndex = partition(a,i,n);
		cout<<"pindex:"<<pIndex;
		quickSort(a,i,pIndex-1);
		quickSort(a,pIndex+1,n);
	}
}

void printArray(int a[],int n){
	int i;
	cout<<"\n";
	for(i=0;i<n;i++)
		cout<<a[i];
}

int main(){
	int a[20],n,i;
	cout<<"Enter n value:";
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	quickSort(a,0,n-1);
	printArray(a,n);
}
