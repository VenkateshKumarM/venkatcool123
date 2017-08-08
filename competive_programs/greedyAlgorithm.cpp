//Greedy Algorithms

// start[]  =  {1, 3, 0, 5, 8, 5};
// finish[] =  {2, 4, 6, 7, 9, 9};

#include<iostream>

using namespace std;

int main(){
	
	int start[6] = {1, 3, 0, 5, 8, 5};
	int finish[6] = {2, 4, 6, 7, 9, 9};
	int i=0,j;
	
	cout<<i;
	cout<<start<<"\n";
	
	for(j=1;(j<=5&&i<4);j++){
		if(start[j]>=finish[i]){
			cout<<j;
			i++;
		}
	}		
	
	return 0;
	
}
