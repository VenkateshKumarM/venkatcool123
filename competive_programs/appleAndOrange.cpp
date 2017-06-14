#include<iostream>

using namespace std;
int main(){
	int a,b,c,d,e,f,i,apple[100000],orange[100000];
	int appleCount=0,orangeCount=0;
	cin>>a>>b;
	cin>>c>>d;	
	cin>>e>>f;
	for(i=0;i<e;i++)
		cin>>apple[i];
	for(i=0;i<f;i++)
		cin>>orange[i];
	for(i=0;i<e;i++){
		apple[i]+=c;
		if(apple[i]>=a && apple[i]<=b)
			appleCount++;
	}
	for(i=0;i<e;i++){
		orange[i]+=d;
		if(orange[i]>=a &&orange[i]<=b)
			orangeCount++;
	}
	cout<<appleCount<<"\n";
	cout<<orangeCount;
}
