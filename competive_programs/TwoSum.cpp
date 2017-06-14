// [2, 7, 11, 15] , target = 9

#include<iostream>
#define MAX 15

using namespace std;

int main(){
	
	int a[MAX],n,i,j,target,x,y;
	
	cout<<"Enter n val:";
	cin>>n;
	
	cout<<"Enter elements:";
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	cout<<"Enter target:";
	cin>>target;	
	
	for(i=0;i<n;i++){		
		j = i+1;
		while(j<n){			
			if(a[i]+a[j] == target && a[i] != a[j]){
			  	x = i;
			  	y = j;
			  	goto LOOP;
			}			
			j++;
		}
		cout<<"i";
	}
	
	LOOP:cout<<x<<" "<<y;
}




