#include<iostream>

using namespace std;

int noOfWhiteHats(int arr[],int n){
	int i,noOfBlackHats=0,whiteHats=0,noOfWhiteHats=1;
	for(i=0;i<n;i++){
		if(arr[i]>n)
			return -1;
		else if(whiteHats<arr[i])
		{
			whiteHats=arr[i];
			noOfWhiteHats++;
		}
		if(arr[i]==0)
		    noOfBlackHats++;
	}
	if(noOfBlackHats==n-1)
		return noOfBlackHats;
	else if(noOfWhiteHats == n)
		return noOfWhiteHats;
	else
		return whiteHats;
}

int main(){
	int arr[20],n,i,whiteHats;
	cout<<"Enter total elements:";
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	whiteHats= noOfWhiteHats(arr,n);
	cout<<"No of White hats:"<<whiteHats;
	return 1;
}
