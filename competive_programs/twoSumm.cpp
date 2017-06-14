#include<iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;

class Solution {
public:
 vector<int> twoSum(vector<int>& nums, int target) {
        	
    int i,j;
    
    vector<int> output;
	
	for(i=0;i<nums.size();i++){		
		j = i+1;
		while(j<nums.size()){			
			if(nums[i]+nums[j] == target && nums[i] != nums[j]){			  	
			  	output.push_back(i);
			  	output.push_back(j);			  	
			  return output;
			}			
			j++;
		}
	}	
    }
};

int main(){
	Solution sol;
	
	vector<int> nums(4);
	
	vector<int> output(2);
	
	int i;
	
	nums[0] = 2;
	nums[1] = 7;
	nums[2] = 11;
	nums[3] = 15;
	
	output = sol.twoSum(nums,17);
	
	for(i=0;i<2;i++)
		cout<<output[i];
}
