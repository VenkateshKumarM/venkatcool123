#include <iostream>

using namespace std;

int main() {
	int n,i,j,a[25],b[25];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		cin>>b[i];
	}
	
	for(i=0;i<n-1;i++){
		for(j=0;j<n;j++){
			if(b[j]>b[j+1]){
				int temp;
				temp = b[j];
				b[j] = b[j+1];
				b[j+1] = temp;
			}
		}
	}
	
	for(i=0;i<n;i++){
		cout<<b[i];
	}
}
