#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int candidate =0;
        for(int num:nums){
            if(count ==0){
                candidate=num;
            }
            if(num==candidate){
                count++;
            }else{
                count--;
            }
        }
        return candidate;
        
    }
};

int main() {
    // Example usage:
    Solution solution;
    vector<int> nums = {3, 2, 3};
    int majority = solution.majorityElement(nums);
    
    // Output the majority element
    cout << "Majority Element: " << majority << endl;
    
    return 0;
}
// LeetCode Problem: https://leetcode.com/problems/majority-element/
// Problem Statement: Given an array of size n, find the majority element. The majority element
// is the element that appears more than n/2 times. You may assume that the majority element always exists in the array.
// Example: Input: nums = [3,2,3]; Output: 3 (