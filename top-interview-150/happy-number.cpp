#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n = n / 10;
            }
            n = sum;
        }

        return n == 1;
    }
};


int main() {
    Solution solution;
    int n = 19; // Example input

    // Check if the number is happy
    bool result = solution.isHappy(n);

    // Output the result
    cout << (result ? "Happy number" : "Not a happy number") << endl; // Output: Happy number

    return 0;
}