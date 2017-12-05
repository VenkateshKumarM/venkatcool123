//Array + 1

#include<iostream>

using namespace std;

#define N 4

void printSol(int out[],int n){
	int i;
	for(i=0;i<n;i++)
		cout<<out[i]<<" ";
		
}


void arrayAddOne(int a[]){
	
	int carry =1,out[N-1],i;
	
//	cout<<"a..";
	
	for(i=N-1;i>=0;i--){
		if(carry == 1){	
			int temp = a[i]+1;
			out[i] = temp%10;
			carry = temp == 10 ?1:0; 
		}
		else {
			out[i] = a[i];
		}
	}
	
	
	
	if(carry == 1){
		int output[N];
		output[0] = 1;
		
		for(i=1;i<=N;i++)
			output[i]=out[i-1];
		
		printSol(output,N+1);
	}
	else {
		printSol(out,N);
	}
	
}


int main(){
	
	int i, a[N];
	
	cout<<"Enter the 4 numbers:";
	
	for(i=0;i<N;i++){
		cin>>a[i]; 
	}
	
	arrayAddOne(a);
	
	return 0;
}
