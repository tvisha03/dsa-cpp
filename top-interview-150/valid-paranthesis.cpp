class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (pairs.count(c)) {
                if (st.empty() || st.top() != pairs[c]) return false;
                st.pop();
            } else {
                st.push(c);
            }
        }

        return st.empty();
    }
};

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int main() {
    Solution solution;
    string s = "({[]})"; // Example input

    // Check if the parentheses are valid
    bool result = solution.isValid(s);

    // Output the result
    cout << (result ? "Valid parentheses" : "Invalid parentheses") << endl; // Output: Valid parentheses

    return 0;
}