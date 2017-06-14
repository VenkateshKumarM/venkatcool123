#include<iostream>

using namespace std;

int conditionCheck(int start1,int start2,int jump1,int jump2){
	if(start1>=0 || start1<=10000 || start2>=0 || start2<=10000 || jump1>=1 || jump1<=10000 || jump2 >=1 || jump2<=10000){
		return 0;
	}
		return 1;
		
}

int main(){
	long i,j,start1,start2,jump1,jump2,meet=0;
	cin>>start1>>jump1>>start2>>jump2;
	i=start1;
	j=start2;
	
	if(conditionCheck(start1,start2,jump1,jump2)){
		cout<<"NO";
	}
	else {
	while(i!=j){
		i+=jump1;
		j+=jump2;
		
		cout<<"i="<<i;
		cout<<"j="<<j;
		cout<<"\n";
		if(i==j)
			meet=1;
	}
	if(meet)
		cout<<"YES";
	else
		cout<<"NO";
	}
}
