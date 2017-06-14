#include<iostream>

using namespace std;


int main(){
	int i;
    long int a[5];
   	long int min,max,total=0,minVal=0,maxVal=0;
    for(i=0;i<5;i++){
    	cin>>a[i];    	
	}
	min =a[0],max=a[0];
	for(i=0;i<5;i++){
    	total+=a[i];
		if(min>a[i])
			min=a[i];
		if(max<a[i])
			max=a[i]; 	
	}	
	minVal = total-max;
	maxVal = total-min;
	cout<<minVal<<" "<<maxVal;
    return 0;
}

How to receive response Future[Result], send to another function as Future[Result], 
 error in Controllers like actual:Future[Result] expected Action Result
