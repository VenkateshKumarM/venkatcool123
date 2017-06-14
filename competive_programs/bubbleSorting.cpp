//Bubble Sort 2 4 1 5 3

#include<iostream>

using namespace std;

int main(){
	int i,j,n,a[20];
	
	cout<<"Enter the n value:";
	cin>>n;
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	
	cout<<"Output:";
	
	for(i=0;i<n;i++)
		cout<<a[i];
}
