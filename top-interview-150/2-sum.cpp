#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashMap;
        for(int i=0;i<nums.size();i++){
            int complement=target-nums[i];
            if(hashMap.find(complement)!=hashMap.end()){
                return {hashMap[complement],i};
            }
            hashMap[nums[i]]=i;
        }
        return {};
        
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15}; // Example input
    int target = 9; // Example target
    vector<int> result = solution.twoSum(nums, target);
    
    // Output the result
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl; // Output: Indices: 0, 1
    } else {
        cout << "No two sum solution found." << endl;
    }
    
    return 0;
}