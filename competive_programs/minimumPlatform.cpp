#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int minimumPlatform(int arr[],int dep[],int n){
	
	int no_plat=1, result=1, i=1, j=0;
	
	sort(arr,arr+n);
	sort(dep,dep+n);
	
	while(i<n && j<n){	
	
	if(arr[i]<dep[j]){
		i++;
		no_plat++;		
		if(no_plat > result){
			result = no_plat;
		}
	}
	else {
		j++;
		no_plat--;
	}
	}
	
	return result;
}


int main(){
	
	int arr[6] = {900,  940, 950,  1100, 1500, 1800};
	int dep[6] = {910, 1200, 1120, 1130, 1900, 2000};
	
	int n = sizeof(arr)/sizeof(arr[0]);
		
	cout<<minimumPlatform(arr,dep,n);
	
	return 0;
}       
