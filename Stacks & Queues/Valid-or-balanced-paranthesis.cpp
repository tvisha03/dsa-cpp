#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

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

int main() {
    Solution solution;
    string test1 = "([]){}";
    string test2 = "([)]";
    
    // Test cases
    bool result1 = solution.isValid(test1); // Should return true
    bool result2 = solution.isValid(test2); // Should return false

    return 0;
}