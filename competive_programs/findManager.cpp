//Find number of Employees Under every Employee
/*
{ "A", "C" },
{ "B", "C" },
{ "C", "F" },
{ "D", "E" },
{ "E", "F" },
{ "F", "F" } */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void findManager(map<string, string> &m){
	
	multimap<string, string> mm;
	
	map<string, string>::iterator itr;
	
	int n=0;
	
	for(itr = m.begin();itr!= m.end();itr++){
		mm.insert(pair<string, string> (itr->second,itr->first));
	}
	
	multimap<string, string>::iterator itr1;
	
	for(itr = m.begin();itr!= m.end();itr++){
		itr1 = mm.find(itr->first);
		n=0;
		while(itr1 != mm.end()){
			if(itr->first == itr1->first)
				n++;
			itr1++;
		}				
		cout<<itr->first<<","<<n<<"\n";
	}

}

int main(){
	
	map<string, string> m;
	
	m["A"] = "C";
	m["B"] = "C";
	m["C"] = "F";
	m["D"] = "E";
	m["E"] = "F";
	m["F"] = "F";
	
	findManager(m);
	
	return 0;		
}
