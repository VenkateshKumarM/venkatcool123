//Find Itinerary from a given list of tickets

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void findSequence(map<string,string> &ticket1){
	
	map<string,string>::iterator itr;
	
	map<string,string> ticket2;
	
	string str;
	
	int n=1;
	
	for(itr = ticket1.begin(); itr!=ticket1.end(); itr++){
		//cout<<itr->first<<" "<<itr->second;
		ticket2.insert(pair <string,string>(itr->second,itr->first));
	}
			
	for(itr = ticket1.begin(); itr!=ticket1.end(); itr++){	
		 if(ticket2.find(itr->first) == ticket2.end()){	
		 	itr = ticket1.find(itr->first);	 	
		 	cout<<itr->first<<" "<<itr->second;	
		 	str = itr->second;
			 break;	 	
		 }				
	}		

	
	while(n<=ticket1.size()){	
		itr = ticket1.begin();
		cout<<"\n";
		 if(ticket1.find(str) != ticket1.end()){
		 	itr = ticket1.find(str);		 	
		 	cout<<itr->first<<" "<<itr->second;	
			str = itr->second;		 	
		 }				
		n++;
	}
	
}


int main(){

	map<string,string> ticket;
	
	ticket.insert(pair <string,string>("Bombay","Chennai"));
	ticket.insert(pair <string,string>("Banglore","Delhi"));
	ticket.insert(pair <string,string>("Goa","Bombay"));
	ticket.insert(pair <string,string>("Delhi","Goa"));

	findSequence(ticket);	
	
	return 0;
}
