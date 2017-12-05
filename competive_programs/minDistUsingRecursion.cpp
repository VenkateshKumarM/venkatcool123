//Edit Distance using Recursion, c

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int min(int a,int b,int c){	
	return min(min(a,b),c);
}

int minDistance(string s1,string s2,int m,int n){
	
	if(m==0)
		return n;
	else if(n==0)
		return m;
	else if(s1[m-1] == s2[n-1])
		return minDistance(s1,s2,m-1,n-1);
	else
		return 1+min(minDistance(s1,s2,m,n-1),
					 minDistance(s1,s2,m-1,n),
					 minDistance(s1,s2,m-1,n-1)
					);
}


int main(){
	
	string str1 = "cat", str2 = "cut";
	
	int m = str1.length();
	
	int n = str2.length();
	
	cout<<minDistance(str1,str2,m,n);
	
	return 0;
}
