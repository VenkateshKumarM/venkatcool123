#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int sumOfElements(int arr[],int n){
    int sum=0,i;
    for(i=0;i<n;i++){
         sum+=arr[i];
    }
    return sum;
}

int main(){
    int n,total,arr_i; 
    scanf("%d",&n);
    int arr[n];
    for(arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
    }
    total = sumOfElements(arr,n);
    printf("Total:%d",total);
    return 0;
}

