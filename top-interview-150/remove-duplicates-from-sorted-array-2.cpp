#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2;

        if (nums.size() <= 2) return nums.size();
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;       
    }
};
int main() {
    // Example usage:
    Solution solution;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
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
// LeetCode Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Problem Statement: Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and returns the new length.
// Note: Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
// Example: Input: nums = [1,1,1,2,2,3]; Output: 5, nums = [1,1,2,2,3,_] (the elements after the returned length don't matter).