#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

int main(){
	int n,i,num1,num2;
	string a,b;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>b;
	}
	num1 = stoi(a);
	num2 = stoi(b);
	cout<<num1<<num2;
}
