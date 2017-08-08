#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


int main(){
    int n,arr_i; 
    float positiveNum=0,negativeNum=0,zeroNum=0,res1,res2,res3; 
    scanf("%d",&n);
    int arr[n];
    
    
    char a[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int size = sizeof(a)/sizeof(a[0]);
    
    printf("Size = %d\n",size);
    
    for(arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
    }
    for(arr_i=0;arr_i<n;arr_i++){
    	if(arr[arr_i]==0){
    		zeroNum++;
		}    	
    	else if(arr[arr_i]>0)
    		positiveNum++;
    	else
    	    negativeNum++;
	}
	res1=positiveNum/n;
	res2=negativeNum/n;
	res3=zeroNum/n;   
	printf("%f\n",res1);
    printf("%f\n",res2);
    printf("%f\n",res3);
    return 0;
}

