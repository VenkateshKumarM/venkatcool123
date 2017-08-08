

#include<iostream>
#include<conio.h>

using namespace std;
void arrayRotate(int a[],int n,int d){

	d = d%n;
	int j = 0, i=0;
	int b[n];
	
	for(i=d;j<n;j++){
	    b[j] = a[i];
		i++;
		if(i == n)
			i=0;
	}
	
	cout<<"Array Rotation\n";
	
	for(i=0;i<n;i++)
		cout<<b[i];
}


int main(){
	int n,i,a[10],d;
	
	cout <<"Enter n val:";
	cin>>n;
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	cout<<"No of Rotation";
	cin>>d;
	arrayRotate(a,n,d);	
	return 0;
}
