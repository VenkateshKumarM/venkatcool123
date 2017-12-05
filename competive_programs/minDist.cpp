//Edit Distance, str1 = "sunday", str2 = "saturday"

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int min(int a,int b,int c){	
	return min(min(a,b),c);
}

int minDistance(string str1,string str2,int m,int n){
	
	int L[m+1][n+1];
	
	int i,j;
	
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			
			if(i == 0)
				L[i][j] = j;
			
			else if(j == 0)
				L[i][j] = i;
			
			else if(str1[i-1] == str2[j-1])
				L[i][j] = L[i-1][j-1];
			
			else
				L[i][j] = min(L[i-1][j],L[i][j-1],L[i-1][j-1])+1; 
		}
	}
	
	return L[m][n];
}

int main(){
	string str1 = "keeg", str2 = "gesek";
	
	int m = str1.length();
	
	int n = str2.length();
	
	cout<<minDistance(str1,str2,m,n);
	
	return 0;
}
