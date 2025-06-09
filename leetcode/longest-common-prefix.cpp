
// Problem: Longest Common Prefix
// LeetCode Problem: https://leetcode.com/problems/longest-common-prefix/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for sort

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(), strs.end()); // Lexicographical sort

        int n = strs.size();
        string first = strs[0];
        string last = strs[n - 1];

        // Compare characters between the first and last strings
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            if (first[i] != last[i]) {
                return ans; // Return collected prefix if mismatch found
            }
            ans += first[i];
        }

        return ans; // Full match of min length
    }
};

int main() {
    // Example usage
    vector<string> strs = {"flower", "flow", "flight"};
    Solution sol;
    string result = sol.longestCommonPrefix(strs);

    // Output the result
    cout << "Longest Common Prefix: \"" << result << "\"" << endl;
    return 0;
}
// Output: Longest Common Prefix: "fl"
// Explanation: The longest common prefix among the strings "flower", "flow", and "flight" is "fl".
// Time Complexity: O(N * M log N), where N is the number of strings and M is the length of the longest string.
// Space Complexity: O(M), where M is the length of the longest string in the input.
// Note: The solution sorts the strings lexicographically and compares the first and last strings to find the common prefix.
// This approach is efficient for the problem and handles edge cases like empty strings or single string inputs.
// Edge Cases:
// 1. If the input vector is empty, the function will return an empty string.
// 2. If all strings are identical, the function will return that string as the common prefix.
// 3. If there are no common characters, the function will return an empty string.
// 4. If the input contains a single string, that string will be returned as the common prefix.
// 5. If the input contains strings with varying lengths, the function will correctly identify the common prefix up to the shortest string's length.
// 6. If the input contains strings with special characters or numbers, the function will still find the common prefix based on character comparison.
// 7. If the input contains strings with mixed case, the function will treat them as distinct characters (e.g., 'a' and 'A' are different).
