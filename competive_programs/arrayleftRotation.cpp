//Array left Rotation

#include<iostream>
#include <vector>
#include <iterator>

#define MAX 15

using namespace std;

int main()
{
	int n,i,r,len=0,val;
	
	cin>>n>>r;
	
	vector <int> g1;
	vector <int> :: iterator it;
	
	for(i=0;i<n;i++){
		cin>>val;
		g1.push_back(val);
	}
	
	
	for(it = g1.begin()+r;len<n;it++){
		if(it==g1.end())
			it = g1.begin();
		cout<<*it<<" ";
		len++;
	}
	
}
