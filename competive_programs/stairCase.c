#include<stdio.h>
#include<conio.h>

int main(){
	int n,i,j,k;
	scanf("%d",&n);
	k=n-1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j>=k){
				printf("#");
			} else{
				printf(" ");
			}			
		}
		printf("\n");
		k--;
	}
}
