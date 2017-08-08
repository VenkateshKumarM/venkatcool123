//Minimum Number of Platforms Required for a Railway/Bus Station

/*Input:  arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
        dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}*/
        
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int minimumPlatform(int arr[],int dep[],int n){
	
	int platforms=0, result=0, i=1, j=0;	
	
	sort(arr,arr+n);
	sort(dep,dep+n);
	
/*	 for (int i = 0; i < n; ++i)
        cout << arr[i] << " "; */
	
	while(i<n){
		if(arr[i]<dep[j]){
			platforms++;
			if(result<platforms)
				result = platforms;								
		}
		else {
			platforms--;
			if(platforms<0)
				platforms = 0;
		}
		i++;
		j++;
	}
	
	//cout<<result;
	return result+1;
}

int main(){
	
	int arr[6] = {900,  940, 950,  1100, 1500, 1800};
	int dep[6] = {910, 1200, 1120, 1130, 1900, 2000};
	
	int n = sizeof(arr)/sizeof(arr[0]);
		
	cout<<minimumPlatform(arr,dep,n);
	
	return 0;
}        
