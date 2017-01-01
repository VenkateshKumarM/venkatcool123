#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int alicePoints=0,bobPoints=0;
    int a0; 
    int a1; 
    int a2; 
    scanf("%d %d %d",&a0,&a1,&a2);
    int b0; 
    int b1; 
    int b2; 
    scanf("%d %d %d",&b0,&b1,&b2);
    if(a0>b0){
        alicePoints++;
    } else if(b0>a0){
        bobPoints++;
    }
    printf("%d %d",alicePoints,bobPoints);
    return 0;
}

