#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string time,arr;
    int i,j=0;
    cin >> time;
    for(i=0;i<time.length();i++)
    {
    	if(time[i] == ":")
    		cout<<time[i-1];
	}
    return 0;
}

