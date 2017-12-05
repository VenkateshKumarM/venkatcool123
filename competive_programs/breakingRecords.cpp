//Breaking the records


#include <bits/stdc++.h>

using namespace std;

vector < int > getRecord(vector < int > s){
    // Complete this function
    
    int i=0,j=0,small,large;
    
    vector<int> res;
    
    small = s.front();    
    large = s.front();
    
    for(vector<int>::iterator it = s.begin()+1 ; it != s.end(); ++it) { 	
    //	cout<<*it;
    	if(large < *it){
    		i++;
    		large = *it;
		}
		else if(small > *it) {
			j++;
			small = *it;
		}          
    }
    
   // cout<<i<<j;
    
    res.push_back(i);
    res.push_back(j);
    
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    vector < int > result = getRecord(s);
    string separator = "", delimiter = " ";
    
    cout<<"\n";
    for(vector<int>::iterator it = result.begin() ; it != result.end(); ++it) {
        cout<<separator<<*it;
        separator = delimiter;
    }
    cout<<endl;
    return 0;
}

