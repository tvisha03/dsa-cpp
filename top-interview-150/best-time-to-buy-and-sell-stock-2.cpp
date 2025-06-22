#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max=0;
        int start=prices[0];
        int len=prices.size();
        for(int i=1;i<len;i++){
            if(start<prices[i]){
                max+=prices[i]-start;
            }
            start=prices[i];
        }
        return max;
        
        
    }
};
int main() {
    // Example usage:
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int profit = solution.maxProfit(prices);
    
    // Output the maximum profit
    cout << "Maximum Profit: " << profit << endl;
    
    return 0;
}

// LeetCode Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Problem Statement: You are given an array prices where prices[i] is the price of a
// given stock on the ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// You can buy and sell the stock as many times as you like (i.e., multiple transactions). However, you