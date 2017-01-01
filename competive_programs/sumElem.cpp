#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sumOfElements(vector<int> arr[]){
    int sum=0,i;
    vector<int> sum=0
    for(i=0;i<sizeof(arr)/sizeof(vector<int>);i++)
        sum+=arr[i];
    return sum;
}

int main(){
    int n,total;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    total = sumOfElements(arr);
    cout<<total;
    return 0;
}

