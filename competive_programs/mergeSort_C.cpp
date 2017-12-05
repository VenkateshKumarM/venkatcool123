//Merge Sort..

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void merge(int a[],int l,int m,int r){
	int n1,n2;
	
	n1 = m-l+1;
	n2 = r-m;
	
	int L[n1],R[n2];
	
	int i=0,j=0,k;
	
	for(i=0;i<n1;i++)
		L[i] = a[l+i];
	
	for(j=0;j<n2;j++)
		R[j] = a[m+1+j];
	
	i=0,j=0,k=l;
	
	while(i<n1&&j<n2){
		if(L[i]<=R[j]){		
			a[k] = L[i];
			i++;
		}
		else if(L[i]>R[j]){
			a[k] = R[j];
			j++;
		}
		k++;
	}
	
	while(i<n1){
		a[k++] = L[i++];
	}
	
	while(j<n2){
		a[k++] = R[j++];
	}
}



void mergeSort(int arr[],int l,int r){
	if(l<r){
		int m = (l+r)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

void printSol(int arr[],int size){
	int i;
	
	for(i=0;i<size;i++)
		cout<<arr[i]<<" ";
}

int main(){
	int arr[] = {12, 11, 13, 5, 6, 7};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	//cout<<"Size:"<<size;
	
	mergeSort(arr,0,size-1);
	
	printSol(arr,size);
	
	return 0;	
}
