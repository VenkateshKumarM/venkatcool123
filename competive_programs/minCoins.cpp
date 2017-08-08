//Minimum number of Coins

#include<iostream>
#include<conio.h>

using namespace std;

int minCoins(int a[],int size,int currency){
	
	int result =0, i=size-1;	
	
	while((i>=0 && currency>0)){				
		if(currency >= a[i]){
		//	cout<<"\nBCurrency:"<<currency;
			currency -= a[i];
			result++;
		//	cout<<"\nACurrency:"<<currency;
		//	cout<<"\nResult:"<<result;						
		}	
		if(currency < a[i] ){
			i--;
		}
	}
	
	return result;
}

int main(){
	int arr[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	int currency;
	
	cout<<"Enter the currency val:";
	cin>>currency;
		
	cout<<minCoins(arr,size,currency);
	
	return 0;
}
