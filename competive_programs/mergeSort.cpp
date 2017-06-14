#include<iostream>

using namespace std;

int merge(int a[],int left,int middle,int right){
	int n1,n2,i,j,k;
	n1=middle-left+1;
	n2=right-middle;
	
	int L[n1],R[n2];
	
	for(i=0;i<n1;i++){
		L[i] = a[left+i];
	}
	for(j=0;j<n2;j++){
		R[j] = a[middle+1+j];
	}
	
	i =0;
	j =0;
	k =left;
	
	while(i<n1&&j<n2){
		if(L[i]<R[j]){
			a[k] =L[i];
			i++;
		}
		else{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	
	while(i<n1){
		a[k++] = L[i++];
	}
	
	while(j<n2){
		a[k++] = R[j++];
	}
	
}

int mergeSort(int a[],int left,int right){
	if(left<right){
	int middle = left+(right-left)/2;
	mergeSort(a,left,middle);
	mergeSort(a,middle+1,right);	
	merge(a,left,middle,right);
	}
}

int main(){
	int a[20],n,i,res;
	cout<<"Enter the n value:";
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
 	mergeSort(a,0,n-1);
 	cout<<"\n";
	for(i=0;i<n;i++)
		cout<<a[i];
}
