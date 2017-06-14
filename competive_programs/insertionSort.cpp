#include<iostream>

using namespace std;

int main(){
	int a[20],n,i,j;
	cout<<"Enter the n value:";
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n-1;i++){
		for(j=i+1;j>0;j--){
			if(a[j]<a[j-1]){
				int temp;
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;	
			}			
		}
	}
	
	for(i=0;i<n;i++){
		cout<<a[i];
	}	
	
}
