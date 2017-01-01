#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


int main(){
    int n,i,j,k;
    scanf("%d",&n);
    k=n-1;
    for(i=0;i<n;i++){
    	for(j=k;;j++){
    		if(j<n)
    			printf("#");
    		else
    			printf(" ");
		}    		
     k--;
     printf("\n");
	}
    return 0;
}

