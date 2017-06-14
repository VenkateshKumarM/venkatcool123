#include<iostream>

using namespace std;

void printQuery(int n,int b[],int qn,int q[]){
	int c=0;
	while(c<qn){
		cout<<b[q[c]];
		cout<<"\n";
		c++;
	}
}

int rotateArray(int n,int a[],int r,int qn,int q[]){
	int i=0,c=0,b[n];
	if(r==0){
		printQuery(n,a,qn,q);
	}	
	else {	
		while(c<n){	
		    b[c]=a[r++];
			c++;
			if(r==n)
				r=0;
		}
		/*for(i=0;i<n;i++)
			cout<<b[i];*/
		printQuery(n,b,qn,q);		
	}
}

int main(){
	int n,r,i,qn,a[15],q[15];
	cin>>n>>r>>qn;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<qn;i++){
		cin>>q[i];
	}
	if(r>=n)
		r=r%n;
	else
		r=n-r;
	rotateArray(n,a,r,qn,q);
	return 0;
}
