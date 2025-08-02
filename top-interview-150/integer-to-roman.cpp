#include <string>
#include <vector>
#include <iostream>
#include <utility> // for std::pair
#include <unordered_map>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        string result = "";
        for (auto &[val, symbol] : roman) {
            while (num >= val) {
                result += symbol;
                num -= val;
            }
        }
        return result;
    }
};

int main() {
    // Example usage:
    Solution solution;
    int number = 1994; // Example integer
    string romanNumeral = solution.intToRoman(number);
    
    // Output the Roman numeral
    cout << "Roman Numeral: " << romanNumeral << endl; // Output: MCMXCIV
    
    return 0;
}