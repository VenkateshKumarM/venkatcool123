#include<iostream>

using namespace std;
int gcd(int x[],int num){
	int i;
	
	for(i=0;i<num;i++){
		if(x[i]%i== 0){
			
		}
		else{
			d++;
		}
	}
	return 1;
}

int main(){
	int x[5],num,commonDivisor,i=0;
	cout<<"Enter hw many num:";
	cin>>num;
	for(i=0;i<num;i++)
		cin>>x[i];
	commonDivisor = gcd(x,num);
	cout<<"\ncommonDivisor"<<commonDivisor;
}

