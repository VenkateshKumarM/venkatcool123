// Selection Sort: 2 3 1 5 4

#include<iostream>

using namespace std;

int main(){
	int i,j,n,a[15],index;
	cout<<"Enter n value:";
	cin>>n;
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	for(i=0;i<n-1;i++) {
		index=i;
		for(j=i+1;j<n;j++) {			
		if(a[index]>a[j])
			index = j;			
		}
		int temp;
		temp = a[index];
		a[index] = a[i];
		a[i] = temp;
	}
	
	cout<<"Sorted Order:";
	for(i=0;i<n;i++)
		cout<<a[i];
}
