// Dynamic Pgm.

// "AGGTAB", "GXTXAYB"

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void printCommonSequence(char X[],char Y[],int m,int n){
	
	int L[m+1][n+1],i,j;
	
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			
			if(i==0 || j==0)
				L[i][j] = 0;
			
			else if(X[i-1] == Y[j-1]){
				L[i][j] = L[i-1][j-1]+1; 
			}
			
			else
				L[i][j] = max(L[i-1][j],L[i][j-1]);
		}
	}
	
	cout<<"Length:"<<L[m][n];
	
	cout<<"\n";
	
	int index = L[m][n];
	
	char seq[index+1];
	
	seq[index] = '\0';
	
	i=m,j=n;
	
	while(i>0 && j>0){		
		if(X[i-1] == Y[j-1]){
		//	cout<<"output:"<<X[i-1];
			seq[index-1] = X[i-1];
			i--;
			j--;
			index--;
		}else if(L[i][j] == L[i-1][j]){
			i--;
		}else {
			j--;
		}		
	}	
	
//	for(i=0;i<index+1;i++)
	cout<<seq;
}


/*int max(int i,int j){
	return i>j?i:j;
}*/

int main(){
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";
	
	int m = strlen(X);
	
	int n = strlen(Y);
	
	printCommonSequence(X,Y,m,n);
	
	return 0;
}
