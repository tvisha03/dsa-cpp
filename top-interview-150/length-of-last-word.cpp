#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word, lastWord;

        while (ss >> word) {
            lastWord = word;
        }

        return lastWord.length();
    }
};

int main() {
    Solution solution;
    string s = "Hello World";
    int length = solution.lengthOfLastWord(s);
    
    cout << "Length of the last word: " << length << endl; // Output: 5
    
    return 0;
}
