#include<iostream>

using namespace std;

int binarySearch(int arr[],int find,int low,int high){
	int middle=(low+high)/2;
	cout<<"Middle:"<<middle;
	cout<<"Element:"<<arr[middle];
	if(find == arr[middle])
		return middle;
	else if(find < arr[middle] && low<high)
		binarySearch(arr,find,low,middle-1);	
	else if(find > arr[middle] && low<high)
		binarySearch(arr,find,middle+1,high);
	else
		cout<<"NotFound";
}

int main(){
	int arr[] = {2,5,8,12,16,23,28,38,56,72,91};
	int n=11, find=34;
	int f = binarySearch(arr,find,0,n-1);
	cout<<"Index:"<<f+1;
	return 0;
}
