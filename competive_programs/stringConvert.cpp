//Edit Distance,   str1 = "geek", str2 = "gesek"

#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void strConvert(string str1,string str2,int m,int n){
	
	int i,j;
	
	char ch[n];
	
	for(i=0;i<m;i++){
	  flag = 1;
		for(j=0;j<n;j++){
			if(str1[i] == str2[j]){
				flag = 0;
				if(i==j)
					break;
				else{
					//insertIT(str1,i,str2[j]);
					str1.insert(i,1,str2[j]);										
				}
			}
		}
		if(flag){
			cout<<str1;
		}
	}
	
	cout<<str1;
} 


int main(){
	string str1= "geek", str2 = "gesek";
	
	int m,n;
	
	m = str1.length();
	n = str2.length();
	
	strConvert(str1,str2,m,n);	
	
	return 0;
}  
