/*
	P   A   H   N
	A P L S I I G
	Y   I   R
*/

#include<stdio.h>


void stringToZigZag(char* str){
	
	int i=0,len=0;
	
	for(i=0;str[i]!='\0';i++)
		len++;
	
	i=0;	
	while(i<=len){
		printf("%c ",str[i]);
		i+=4;
	}	
	
	i=1;
	printf("\n");
	while(i<=len){
		printf("%c",str[i]);
		i+=2;
	}
	
	i=2;
	printf("\n");
	while(i<=len){
		printf("%c ",str[i]);
		i+=4;	
	}
}

int main(){
	char str[] = "PAYPALISHIRINGABCDEFGH";
	
	stringToZigZag(str);
	
	return 0;
}
