//To calculate pow(x,n)

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int power(int x,int n){
	if(n==0)
		return 1;
	else{	
		//cout<<x<<" "<<n;
		n--;
		return x*power(x,n);				
	}
}

int main(){
	
	int x,n;
	
	cout<<"Enter the x and n value:";
	cin>>x>>n;
	
	cout<<power(x,n);
	
	return 0;
}
