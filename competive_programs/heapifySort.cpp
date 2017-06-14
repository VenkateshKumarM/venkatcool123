//heapSort 4 1 2 3 5

#include<iostream>

using namespace std;

void heapify(int a[],int i,int n){
	int left = 2*i+1;
	int right = 2*i+2;
	
	int largest = i;
	
	cout<<"largest:"<<a[largest];
	cout<<"l:"<<a[left];
	cout<<"r:"<<a[right];
	
	if(a[largest]<a[left] && left <n){
		largest = left;
	}
	
	if(a[largest]<a[right] && right <n){
		largest = right;
	}
	
	cout<<"largest:"<<a[largest];
	cout<<"l:"<<a[left];
	cout<<"r:"<<a[right];
	
	cout<<"\n";
	
	if(largest != i){
		int temp;
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		heapify(a,largest,n);
	}
}

void heapSort(int a[],int n){
	int i;
	
	for(i=(n/2)-1;i>=0;i--)
		heapify(a,i,n);
	
	for(i=n-1;i>=0;i--){
		int temp;
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		
		heapify(a,0,i);
	}
}

int main(){
	int a[15],i,n;
	
	cout<<"Enter the n val:";
	cin>>n;
	
	for(i=0;i<n;i++)
		cin>>a[i];
		
	heapSort(a,n);	
	
	for(i=0;i<n;i++)
		cout<<a[i];
}


