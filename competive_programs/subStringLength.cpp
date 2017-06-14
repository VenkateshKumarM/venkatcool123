#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];n
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }

int main(){
	
	int max = lengthOfLongestSubstring("abcaefab");
	cout<<max;
}
