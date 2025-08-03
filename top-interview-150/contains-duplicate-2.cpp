

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;

        for(int i=0;i<nums.size();i++){
            if(window.count(nums[i])){
                return true;
            }
            window.insert(nums[i]);

            if(window.size()>k){
                window.erase(nums[i-k]);
            }
        }
        return false;
    }
};

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <sstream>
#include <cctype>
using namespace std;

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 1}; // Example input
    int k = 3; // Example k value

    // Check for nearby duplicates
    bool result = solution.containsNearbyDuplicate(nums, k);

    // Output the result
    cout << (result ? "Contains nearby duplicate" : "No nearby duplicate") << endl; // Output: Contains nearby duplicate

    return 0;
}