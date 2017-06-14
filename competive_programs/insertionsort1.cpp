//Insertion Sort

#include<iostream>

using namespace std;

int main(){
	int a[15],i,j,n,key;
	cout<<"Enter the n val:";
	cin>>n;
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	for(i=2;i<n;i++){
		key=a[i];
		j=i-1;
		while(j>=0 && key<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	
	for(i=0;i<n;i++)
		cout<<a[i];
}
