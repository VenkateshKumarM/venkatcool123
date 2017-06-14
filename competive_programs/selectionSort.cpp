#include<iostream>

using namespace std;
int main(){
	int n,i,j,a[15],min;
	cout<<"Enter the n value:";
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(a[min]>a[j])
				min=j;
		}
		int temp;
		temp = a[i];
		a[i] = a[min];
		a[min]= temp;
	}
	for(i=0;i<n;i++)
		cout<<a[i];
}
