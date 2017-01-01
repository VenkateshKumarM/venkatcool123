#include<iostream>

using namespace std;
int main(){
	int k;
	char num[30];
	cout<<"Enter the number n digits";
	cin>>num;
	cin>>k;
	int i;
	for(i=0;k>0;i++){
		if(num[i]!='9')
		{
			num[i]='9';
			k--;
		}
		}
	cout<<"The largest Number is:"<<num;
	return 0;
}
