#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=0;
        for(int price:prices){
            minPrice=min(minPrice,price);
            maxProfit=max(maxProfit, price-minPrice);
        }
        return maxProfit;
        
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

// LeetCode Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Problem Statement: You are given an array prices where prices[i] is the price of a
// given stock on the ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit,
