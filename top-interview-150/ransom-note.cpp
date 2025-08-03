#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26]={0};
        for(char c:magazine){
            freq[c-'a']++;
        }
        for(char c:ransomNote){
            if(freq[c-'a']==0){
                return false;
            }
            freq[c-'a']--;
        }
        return true;
        
    }
};

int main() {
    Solution solution;
    string ransomNote = "a";
    string magazine = "b";
    
    // Check if ransom note can be constructed from magazine
    bool result = solution.canConstruct(ransomNote, magazine);
    
    // Output the result
    cout << (result ? "Can construct" : "Cannot construct") << endl; // Output: Cannot construct
    
    return 0;
}