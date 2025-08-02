#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i){
            if (i>0 && nums[i] == nums[i - 1]) continue;
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                if((nums[i] + nums[j] + nums[k]) == 0){
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (j<k && nums[j] == nums[j+1]) j++;
                    while (j<k && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                }
                else if((nums[i] + nums[j] + nums[k])<0) j++;
                else k--;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4}; // Example input
    vector<vector<int>> result = solution.threeSum(nums);
    
    // Output the result
    for (const auto& triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    
    return 0;
}