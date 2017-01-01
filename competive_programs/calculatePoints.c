#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int compare(int a, int b){
    if(a>b){
        return 1;
    } else if(b>a){
        return 0;
    } else {
        return -1;
    }
}

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
    if(compare(a0,b0)!=-1){
        compare(a0,b0)==1?alicePoints++:bobPoints++;
    }
    if(compare(a1,b1)!=-1){
        compare(a1,b1)==1?alicePoints++:bobPoints++;
    }
    if(compare(a2,b2)!=-1){
        compare(a2,b2)==1?alicePoints++:bobPoints++;
    }
    printf("%d %d",alicePoints,bobPoints);
    return 0;
}
