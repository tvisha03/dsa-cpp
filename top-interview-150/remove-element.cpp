#include <vector>
#include <iostream>
using namespace std;

// LeetCode Problem: https://leetcode.com/problems/remove-element/
// Problem Statement: Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
// Note: Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
// Example: Input: nums = [3,2,2,3], val = 3; Output: 2, nums = [2,2,_] (the elements after the returned length don't matter).
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=val){
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
        
    }
};
int main() {
    // Example usage:
    Solution solution;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int newLength = solution.removeElement(nums, val);
    
    // Output the new length and modified array
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
