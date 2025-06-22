#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// LeetCode Problem: https://leetcode.com/problems/rotate-array/
// Problem Statement: Given an array, rotate the array to the right by k steps, where
// k is non-negative. Note: Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
// Example: Input: nums = [1,2,3,4,5,6,7], k = 3; Output: [5,6,7,1,2,3,4].
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        
    }
};
int main() {
    // Example usage:
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    solution.rotate(nums, k);
    
    // Output the rotated array
    cout << "Rotated array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
// Note: The reverse function is used to reverse the entire array and then reverse the first k
