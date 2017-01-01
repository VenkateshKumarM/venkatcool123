#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int diagonalSum(int n,int a[n][n]){
    int sumL=0,sumR=0,k=n-1,i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){            
            	sumL+=a[i][j];
			}            
			if(k==j) {			
			  sumR+=a[i][k];
				k--;
			}   
        }        
    }
    printf("\nsumL=%d",sumL);
    printf("\nsumR=%d",sumR);
    return sumL+sumR;
}

int main(){
    int n,a_i,a_j,total; 
    scanf("%d",&n);
    int a[n][n];
    for(a_i = 0; a_i < n; a_i++){
       for(a_j = 0; a_j < n; a_j++){          
          scanf("%d",&a[a_i][a_j]);
       }
    }
    total = diagonalSum(n,a);
    printf("Total=%d",total);
    return 0;
}

