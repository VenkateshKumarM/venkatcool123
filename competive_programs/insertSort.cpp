//Insertion Sort 3 4 1 5 2

#include<iostream>

using namespace std;
int main(){
	int i,j,n,a[15],min;
	
	cout<<"Enter the n val:";
	cin>>n;
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	for(i=1;i<n;i++){
		min = a[i];
		j=i-1;
		
		while(j>=0 && min<a[j]){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = min;
	}
	
	cout<<"Output:";
	for(i=0;i<n;i++)
		cout<<a[i];
}
