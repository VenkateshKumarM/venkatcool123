//Merge Sort 1 4 2 3 6 5

0 3 1

0 2  1 3

#include<iostream>

using namespace std;

void merge(int a[],int l,int r,int m){
	
	int n1,n2;
	n1 = m-l+1;
	n2 = r-m;
	
	int L[n1],R[n2];
	
	for(i=0;i<n1;i++)
		L[i] = a[l+i];
	
	for(i=0;i<n2;i++)
		R[i] = a[l+m+i];
		
	i=0;
	j=0;
	k=l;	
	while(i<n1 && j<n2){
		if(L[i]<R[j]){
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}
	
	while(i<n1){
		a[k++] = L[i];
		i++;
	}
		
	while(j<n2){	
		a[k++] = R[j];
		j++;
	}
}

void mergeSort(int a[],int l,int r){
	if(l<r){
		int middle = (l+r)/2;
		mergeSort(a,l,middle);
		mergeSort(a,middle+1,r);
		merge(a,l,r,middle);	
	}	
}

int main(){
	int a[15],i,j,n;
	
	cout<<"Enter the n val:";
	cin>>n;
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	mergeSort(a,0,n);
}
