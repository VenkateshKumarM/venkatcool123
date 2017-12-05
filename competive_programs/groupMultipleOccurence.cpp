//Group multiple occurrence of array elements ordered by first occurrence

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printMultipleOccurence(int arr[],int size){
	cout<<"\n";
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
}

void groupMultipleOccurrence(int a[],int size){
	
	map<int,int> m;
	
	int i;
	
	map<int,int>::iterator it;
	
	for(i=0;i<size;i++){
		it = m.find(a[i]);		
		if(it->first == a[i]){
			cout<<a[i]<<"\n";
			int temp;
			temp = a[it->second+1];
			a[it->second+1] = a[i] ;
			a[i] = temp;
			
			it = m.find(a[i]);
		 	
			if(it->first == a[i])
				it->second = i;
			
			it = m.find(a[it->second+1]);
			
			if(it->first == a[it->second+1])
				it->second = it->second+1;	
		}
		else {
			m.insert(pair<int,int>(a[i],i));
		}
	}
	
	for(it=m.begin();it!=m.end();it++){
		cout<<it->first<<" "<<it->second;
		cout<<"\n";
	}
	
	printMultipleOccurence(a,size);
}



int main(){
	int arr[] = {4, 6, 9, 2, 3, 4, 9, 6, 10, 4};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	groupMultipleOccurrence(arr,size);
		
	return 0;
}
