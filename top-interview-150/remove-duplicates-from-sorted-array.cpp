#include <vector>
#include <iostream>
using namespace std;
// LeetCode Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Problem Statement: Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.
// Note: Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
// Example: Input: nums = [1,1,2]; Output: 2, nums = [1,2,_] (the elements after the returned length don't matter).
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=1;j<nums.size();j++){
           if(nums[i]!=nums[j]){
            i++;
            nums[i]=nums[j];
           }
        }
        return i+1;
    }
};
int main() {
    // Example usage:
    Solution solution;
    vector<int> nums = {1, 1, 2};
    int newLength = solution.removeDuplicates(nums);
    
    // Output the new length and modified array
    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}