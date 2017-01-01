#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>



int calculateSum(int n,int arr[n][n],int c,int d) {
	int i,j,k=0,sum=0;
	for(i=c;i<c+3;i++){
		for(j=d;j<d+3;j++){
		    if(!((i==c+1&&j==d) || (i==c+1&&j==d+2))){
		    	printf("%d ",arr[i][j]);
				sum+=arr[i][j];
			}
			else {
				printf("  ");
			}					
		}
		printf("\n");	
	}
	return sum;
}


int main(){
    int arr[6][6],total=0, i, j,output=0;
    for(i = 0; i < 6; i++){
       for(j = 0; j < 6; j++){          
          scanf("%d",&arr[i][j]);
       }
    }
        
    for(i=0;i<4;i++){
    	for(j=0;j<4;j++){
    		output = calculateSum(6,arr,i,j);    			
    		if((i==0&&j==0) || total<output){
    			total = output;
			} 		
		}
	}    
   
    printf("%d ",total);
    return 0;
}

