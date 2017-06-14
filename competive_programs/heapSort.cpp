#include<iostream>

using namespace std;

void printArray(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<arr[i];
	}
}

void swap(int *n,int *largest){
	int temp;
	temp = *n;
	*n = *largest;
	*largest = temp;
}

void heapSort(int a[],int n,int i){

	cout<<"\n";
	cout<<"i"<<i;
	int largest=i;
	int left = 2*i+1;
	int right = 2*i+2;
	
	
	if(left<n && a[left]>a[i]){
		largest = left;
	}
	
	if(right<n && a[right]>a[largest]){
		largest = right;
	}
	
	cout<<"largest:"<<largest;
	cout<<"\n";
	if(largest!=i){
		swap(a[i],a[largest]);
		heapSort(a,n,largest);
	}
}


void heapify(int arr[],int n){
	int i;
	cout<<"N:"<<n;
	for(i=n/2-1;i>=0;i--)
		heapSort(arr,n,i);
	cout<<"\n";
	cout<<"N:"<<n;
	for(i=n-1;i>=0;i--){
		swap(arr[0],arr[i]);
		heapSort(arr,i,0);		
	}
	printArray(arr,n);
}

int main(){
	int arr[20],n,i;
	cout<<"Enter the n val:";
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	heapify(arr,n);
}
