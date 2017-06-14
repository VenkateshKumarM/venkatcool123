//merge Sort 3 1 4 6 2 5

#include<iostream>

using namespace std;

void merge(int a[],int l,int r,int m){
	
	cout<<"\n";
	cout<<"l:"<<l;
	cout<<"r:"<<r;
	cout<<"m:"<<m;
	
	cout<<"\n";
	
	int n1 = m-l+1;
	int n2 = r-m;
	
	cout<<"n1:"<<n1;
	cout<<"n2:"<<n2;
	
	cout<<"\n";
	
	int L[n1],R[n2];
	int i,j,k;
	
	for(i=0;i<n1;i++){
		L[i] = a[l+i];
		cout<<"L[i]:"<<L[i];
	}
	
	for(j=0;j<n2;j++){
		R[j] = a[m+1+j];
		cout<<"R[j]:"<<R[j];
	}
	
	cout<<"\n";
	i=0;
	j=0;
	k=l;
	
	while(i<n1&&j<n2){
		if(L[i]<R[j]){
			a[k]=L[i];
			i++;
		}
		else {
			a[k]=R[j];
			j++;
		}
		cout<<"a[k]:"<<a[k];
		k++;
	}
	
	while(i<n1){
		a[k] = L[i];
		i++;
		k++;
	}
	
	while(j<n2){
		a[k] = R[j];
		j++;
		k++;
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
	int a[15],i,n;
	
	cout<<"Enter the n val:";
	cin>>n;
	
	for(i=0;i<n;i++)
		cin>>a[i];
		
	mergeSort(a,0,n-1);
	
	cout<<"\n";
	for(i=0;i<n;i++)
		cout<<a[i];
}


