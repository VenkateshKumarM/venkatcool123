//nth fibonacci Number using Recursion.

//f(5).

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int fibonacci(int n){
	int res = findFibo(n);
	if(res>0){
		return res;
	}
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
	return fibonacci(n-1)+fibonacci(n-2);	
}

///* C program for Tabulated version */
/*int fibonacci(int n){
	int i,a[n];
	
	a[0] = 0, a[1]= 1;
	
	for(i=2;i<=n;i++){
		a[i] = a[i-1] +a[i-2];
	}
	
	return a[n];
}*/

int main(){
	
	int n;
	
	cout<<"Enter the number to find fibonacci";
	cin>>n;
	
	cout<<fibonacci(n-1);
	
	return 0;	
} 
