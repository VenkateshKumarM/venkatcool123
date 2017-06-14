//QuickSort 2 3 1 6 4 5

#include<iostream>

using namespace std;

int partition(int a[],int l,int h){
	
	int i = (l-1);
	int pivot = a[h];
	int temp,j;
	
	cout<<"\n";
	
	cout<<"l:"<<l;
	cout<<"h:"<<h;
	
	
	cout<<"pivot:"<<a[h];
	cout<<"\n";
	
	for(j=l;j<h;j++){
		if(a[j]<=pivot){
			i++;			
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;			
		}
	} 
	
	temp = a[i+1];
	a[i+1] = a[h];
	a[h] = temp;
	
	cout<<"h:"<<a[h];
	cout<<"\n";
	
	return (i+1);
}

int quickSort(int a[],int l,int h){
	if(l<h){
		int pi =  partition(a,l,h);
		quickSort(a,l,pi-1);
		quickSort(a,pi+1,h);
	}
}

int main(){
	int a[15],i,n;
	
	cout<<"Enter the n val:";
	cin>>n;
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	quickSort(a,0,n-1);	
	
	for(i=0;i<n;i++)
		cout<<a[i];
}
