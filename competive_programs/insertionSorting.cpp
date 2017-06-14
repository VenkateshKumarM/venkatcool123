//Insertion Sort 3 5 1 4 2
#include<iostream>

using namespace std;
int main(){
	int i,j,n,a[15],index,min,flag;	
	cout<<"Enter the n value:";
	cin>>n;	
	for(i=0;i<n;i++)
		cin>>a[i];
			
	while(i<n-1){		
		flag = false;
		min = a[i];
		for(j=i+1;j>0;j--){			
			if(a[j]< min) {
				index = j;
				min = a[index];
				a[j] = a[j-1];
				flag = true;
			}
		}
		if(flag)
			a[index] = min;
		i++;
	}
	
	for(i=0;i<n;i++)
		cout<<a[i];
}
