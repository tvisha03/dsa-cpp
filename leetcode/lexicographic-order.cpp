#include <vector>
using namespace std;
// Lexicographic Order
// This code generates numbers in lexicographic order from 1 to n.
// The function `lexicalOrder` starts with numbers 1 to 9 and recursively appends digits 0-9 to generate all valid numbers up to n.
// The result is stored in a vector and returned at the end.
// Time Complexity: O(n)
// Space Complexity: O(n)
// LeetCode Problem: https://leetcode.com/problems/lexicographical-numbers/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(int currNum, int n, vector<int>& result) {
        if (currNum > n) return;
        result.push_back(currNum);
        for (int append = 0; append <= 9; append++) {
            int newNum = (currNum * 10) + append;
            if (newNum > n) break;
            solve(newNum, n, result);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int startNum = 1; startNum <= 9; startNum++) {
            if (startNum > n) break;
            solve(startNum, n, result);
        }
        return result;
    }
};

// ✅ Add a main() function
int main() {
    Solution sol;
    int n = 25;
    vector<int> result = sol.lexicalOrder(n);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
