//Grading Students.

#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

int main(){	
	vector <int> g1;
	vector <int> ::iterator it;
	
	int n,i,val,rem;
	
	cin>>n;
	
	for(i=0;i<n;i++){
		cin>>val;
		g1.push_back(val);
	}
	
	for(it=g1.begin();it!=g1.end();it++){
		if(*it>37){		
			rem = *it%5;		
			if(rem>2){
				rem = 5 - rem;
				*it = *it + rem;
			}
		}
	}
	
	for(it=g1.begin();it!=g1.end();it++){
		cout<<*it<<"\n";
	}
}
