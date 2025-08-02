#include <iostream>
#include <string>
#include <cctype>
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
    Solution solution;
    string input = "A man, a plan, a canal: Panama";
    bool result = solution.isPalindrome(input);
    cout << "Is palindrome: " << (result ? "true" : "false") << endl;
    return 0;
}