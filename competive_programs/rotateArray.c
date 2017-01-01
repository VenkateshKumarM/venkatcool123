#include<stdio.h>
#include<conio.h>

int rotateArray(int r,int n,int a[n]){
	int i,c=0,valid=1;
	while(valid){
		if(r<n){		
			printf("%d ",a[r]);
			c == n-1 ? valid=0 : c++ ;
			r++;
		}
		else if(r==n){
			r=0;
		}		
		else
			r= r%n;
	}
	return;
}

int main(){
	int n,r,i,a[15];
	scanf("%d %d",&n,&r);
	for(i=0;i<n;i++)		
		scanf("%d",&a[i]);
	rotateArray(r,n,a);
	return 0;
}
