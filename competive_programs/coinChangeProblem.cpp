//Coin Change.

#include<stdio.h>
#include <string.h>

int coinChange(int S[],int m,int n){
	
	int table[n+1],i,j;
	
	memset(table,0,sizeof(table));
	
	table[0] = 1;	
	
	for(i=0;i<m;i++){
		for(j=S[i];j<=n;j++){
			
			//if(n>=j)
				table[j]+=table[j-S[i]];
		}
	}
	
//	printf("%d",table[n]);
	
	return table[n];
}


int main(){
	int S[3]={1,2,5},n=12;	
	
	printf("%d",coinChange(S,3,n));
	
	return 0;	
}
