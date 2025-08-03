#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(string& word:strs){
            int freq[26]={0};
            for(char c:word) freq[c-'a']++;
            string key="";
            for(int i=0;i<26;i++){
                key+=to_string(freq[i])+"#";
            }
            map[key].push_back(word);
        }
        vector<vector<string>> result;
        for(auto& pair:map){
            result.push_back(pair.second);
        }
        return result;
        
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"}; // Example input
    
    // Group anagrams
    vector<vector<string>> result = solution.groupAnagrams(strs);
    
    // Output the result
    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl; // Output: [ eat tea ate ] [ tan nat ] [ bat ]
    }
    
    return 0;
}