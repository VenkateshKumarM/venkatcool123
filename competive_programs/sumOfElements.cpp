#include<iostream>

using namespace std;

int sumOfElements(int a[],int n,int k1,int k2){
	int i,j,temp,sum=0;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;	
			}
		}
	}
	for(i=k1;i<k2-1;i++){
		sum+=a[i];
	}
	return sum;
}

int main(){
	int n,i,a[15],k1,k2,total;
	cout<<"Enter the total numbers:";
	cin>>n;
	cout<<"Enter k1:";
	cin>>k1;
	cout<<"Enter k2:";
	cin>>k2;
	for(i=0;i<n;i++)
		cin>>a[i];
	total=sumOfElements(a,n,k1,k2);
	cout<<"Total:"<<total;
	return 1;
}
