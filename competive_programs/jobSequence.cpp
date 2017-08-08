//Job Sequencing Problem

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Job {
	char id;
	int dead;
	int profit;
};

bool comparison(Job a, Job b){
	return a.profit > b.profit;
}

void jobSequence(struct Job arr[],int n){
	
	sort(arr,arr+n,comparison);
	
	int i, j;
	
/*	for(i=0;i<n;i++){
		cout<<arr[i].id<<" ";
		cout<<arr[i].dead<<" ";
		cout<<arr[i].profit<<" ";
	}*/
	
	bool set[n];
	
	char result[n];
	
	for(i=0;i<n;i++)
		set[i]= false;
	
	for(i=0;i<n;i++){
		for(j = min(n, arr[i].dead)-1;j>=0;j--){
			if(set[j] == false){
				set[j] = true;
				result[j] = arr[i].id;
				break;
			}
		}
	}
	
	for(i=0;i<n;i++){
		if(set[i])
			cout<<result[i]<<" ";
	}
	
}

int main(){
	Job arr[] = { {'a',2,100}, {'b',1,19}, {'c',2,27}, {'d',1,25}, {'e',3,15}};
	
	jobSequence(arr,5);
	
	return 0;
}
