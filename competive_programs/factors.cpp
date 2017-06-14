#include<iostream>

using namespace std;

int main(){
	int n,m,i;
	cin>>n;
	//cin>>m;
	int a[n],b[m],c[n],d[m],k=0,l=0,j,max1=0,max2=0;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<m;i++)
		cin>>b[i];
	
	for(i=0;i<n;i++){
		if(max1<a[i])
			max1=a[i];
	}
	
	for(i=2;i<=max1;i++){
			k=0;
		for(j=0;j<n;j++){
			if(a[j]%i ==0){
				k++;
			}
			if(k== n)
			c[l++] = i;
		}
	}
	
	for(i=0;i<n;i++){
		if(max2<a[i])
			max2=a[i];
	}
	
	for(i=2;i<=max2;i++){
			k=0;
		for(j=0;j<m;j++){
			if(b[j]%i ==0){
				k++;
			}
			if(k== m)
			d[++] = i;
		}
	}
	
	cout<<"l:"<<l<<"\n";
	for(i=0;i<l;i++)
		cout<<c[i];		
}
