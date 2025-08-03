#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,char> map_s_to_t;
        unordered_map<char,char> map_t_to_s;
        for(int i=0;i<s.length();i++){
            char c1=s[i];
            char c2=t[i];
            if(map_s_to_t.count(c1)&&map_s_to_t[c1]!=c2) return false;
            if (map_t_to_s.count(c2) && map_t_to_s[c2] != c1) return false;

            map_s_to_t[c1] = c2;
            map_t_to_s[c2] = c1;
        }

        return true;
        
        
    }
};

int main() {
    Solution solution;
    string s = "egg";
    string t = "add";
    
    // Check if strings are isomorphic
    bool result = solution.isIsomorphic(s, t);
    
    // Output the result
    cout << (result ? "Isomorphic" : "Not isomorphic") << endl; // Output: Isomorphic
    
    return 0;
}