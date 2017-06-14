#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
	int i;
    char tim[12];
    scanf("%c",tim);
    for(i=0;i<11;i++)
    {
    	if(tim[i] == ":"){
    		printf("%c",tim[i-1]);
		} 	
		printf("%c",tim[i]);
	}
    return 0;
}

