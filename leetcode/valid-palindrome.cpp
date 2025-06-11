
// LeetCode problem number: 125
// Problem: Valid Palindrome
#include <iostream>
#include <string>
#include <cctype> // for isalnum and tolower
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left=0,right=s.length()-1;

        while(left<right){
            while(left<right && !isalnum(s[left])) left++;
            while(left<right && !isalnum(s[right])) right--;

            if(tolower(s[left])!=tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
        
    }
};
int main() {
    Solution sol;
    string test1 = "A man, a plan, a canal: Panama";
    string test2 = "race a car";
    cout << sol.isPalindrome(test1) << endl; // Output: 1 (true)
    cout << sol.isPalindrome(test2) << endl; // Output: 0 (false)
    return 0;
}
// Output:
// 1
// 0    