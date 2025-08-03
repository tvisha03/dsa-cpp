#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        istringstream iss(s);
        string word;
        while(iss>>word){
            words.push_back(word);
        }
        if(pattern.size()!=words.size()) return false;
        unordered_map<char,string> p_to_w;
        unordered_map<string,char> w_to_p;

        for(int i=0;i<pattern.size();i++){
            char c=pattern[i];
            string w=words[i];
            if(p_to_w.count(c) && p_to_w[c]!=w) return false;
            if(w_to_p.count(w) && w_to_p[w]!=c) return false;

            p_to_w[c]=w;
            w_to_p[w]=c;

        }
        return true;
        
    }
};

int main() {
    Solution solution;
    string pattern = "abba";
    string s = "dog cat cat dog";
    
    // Check if the string follows the given pattern
    bool result = solution.wordPattern(pattern, s);
    
    // Output the result
    cout << (result ? "Follows pattern" : "Does not follow pattern") << endl; // Output: Follows pattern
    
    return 0;
}