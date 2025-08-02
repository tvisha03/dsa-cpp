#include <string>
#include <stack>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int char2num(char a){
        switch(a){
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;
            default:return 0;
        }
    }
    int romanToInt(string s) {
        int result=0;
        for(int i=0;i<s.length();i++){
            int curr=char2num(s[i]);
            int next=(i+1<s.length())?char2num(s[i+1]):0;
            if(curr<next){
                result-=curr;
            }else{
                result+=curr;
            }

        }
        return result;
        
    }
};

int main() {
    // Example usage:
    Solution solution;
    string roman = "MCMXCIV"; // Example Roman numeral
    int integerValue = solution.romanToInt(roman);
    
    // Output the integer value
    cout << "Integer Value: " << integerValue << endl; // Output: 1994
    
    return 0;
}