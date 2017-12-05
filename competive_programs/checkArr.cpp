#include<iostream>

using namespace std;

void changeArr(int a[]){
	
	a[2]=3;
}


int main(){
	int arr[3] = {0,1,2};
	
//	changeArr(arr);
	
	int i;
	
	for(i=0;i<3;i++)
		cout<<arr[i];
		
	return 0;
}
