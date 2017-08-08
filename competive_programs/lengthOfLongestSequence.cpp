// Longest Increasing Subsequence

// 10,22,9,33,21,50,41,60.

#include<stdio.h>
#include<stdlib.h>

int lengthOfIncreasingSubsequence(int arr[],int n){
	
	int i,j,max;	
	int* lis = (int *)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++)
		lis[i]=1;
	
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){			
			if((arr[i]>arr[j])&&(lis[i]<lis[j]+1))
					lis[i] = lis[j]+1;		
		}
	}
	
	for(i=0;i<n;i++){
		if(max<lis[i])
			max=lis[i];
	}
	
	free(lis);
	return max;
}


int main(){
	
	int i,n,max,arr[15];
	
	printf("Enter the size:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	max = lengthOfIncreasingSubsequence(arr,n);
	
	printf("\nLengthOfLongestSubString:%d",max);
}
