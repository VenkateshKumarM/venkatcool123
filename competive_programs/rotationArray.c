#include<stdio.h>

int rotateArray(int r,int n,int a[n]){
	int i,c=0;
	if(r>=n)
		r=r%n;
    while(c<n){
    	printf("%d ",a[r++]);
    	if(r==n)
    		r=0;
    	c++;
	} 
	return 1;
}

int main(){
	int n,r,i,a[15];
	scanf("%d %d",&n,&r);
	for(i=0;i<n;i++)		
		scanf("%d",&a[i]);
	rotateArray(r,n,a);
	return 0;
}
