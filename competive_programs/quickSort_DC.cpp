//Quick Sort Algorithm

#include<iostream>
#include<bits/stdc++.h>

#define N 8

using namespace std;

void swap(int* l, int* h){
	int temp;
	
	temp = *l;
	*l = *h;
	*h = temp;
	
}

void printSol(int a[]){
	int i;
	
	for(i=0;i<N;i++)
		cout<<a[i]<<" ";
	
	cout<<"\n";
}

int partition(int a[],int l,int h){
	
	int pivot = a[h];
	int high = h;
	
//	cout<<"pivot:"<<pivot;
//	cout<<"high"<<high;
	h = h-1;
	
	cout<<"Before:\n";
	
	printSol(a);
		
	while(l<=h){
		
		while(a[l]<pivot && l<=h)
			l++;
		
		while(a[h]>pivot && l<=h)
			h--;
			
	//	cout<<l<<" "<<h<<" ";	
		
		if(a[l]>a[h] && l<h){			
			swap(&a[l],&a[h]);
			
		}		
	}
	
	swap(&a[l],&a[high]);
	
	
	cout<<"After:\n";
	printSol(a);
	
	return l;
}



void qSort(int arr[],int low,int high){
	
	if(low<high){
		int pi = partition(arr,low,high);
		
		qSort(arr,low,pi-1);
		
		qSort(arr,pi+1,high);
	}
}


int main(){
	
	int arr[] = {10, 7, 8, 9, 1, 5,2,3};
	
	qSort(arr,0,7);
	
	printSol(arr);
	
	return 0;
}
