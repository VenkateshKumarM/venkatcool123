//Given an array of pairs, find all symmetric pairs in it

#include<iostream>
#include<bits/stdc++.h>

const int M = 5;
const int N = 2;

using namespace std;

void printSymmetric(int a[][N],int M, int N){
	
	//cout<<a[M-1][N-1];
	
	map<int,int> m;
	int i;
	
	map<int,int> ::iterator it;
	
	for(i=0;i<M;i++){
		it = m.find(a[i][0]);
		if(it->first == a[i][0] && it->second == a[i][1]){
			cout<<"\nSymmetricPair:"<<a[i][1]<<","<<a[i][0];
		}
		else {
			m.insert(pair<int,int>(a[i][1],a[i][0]));
		}
	}
}

int main(){
	
	int arr[M][N] = {{11, 20}, {30, 40}, {5, 10}, {40, 30}, {10, 5}};

	printSymmetric(arr,M,N);
	
	return 0;
}
