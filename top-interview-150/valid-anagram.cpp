class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int count[26] = {0};

        for (char c : s) count[c - 'a']++;
        for (char c : t) count[c - 'a']--;

        for (int i = 0; i < 26; ++i)
            if (count[i] != 0)
                return false;

        return true;
    }
};

#include <iostream>
#include <string>
using namespace std;
int main() {
    Solution solution;
    string s = "anagram";
    string t = "nagaram";

    // Check if the strings are anagrams
    bool result = solution.isAnagram(s, t);

    // Output the result
    cout << (result ? "Anagrams" : "Not anagrams") << endl; // Output: Anagrams

    return 0;
}