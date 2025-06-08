#include <iostream> // for cout
#include <vector>   // for vector
using namespace std;
// Lexicographic Order Iterative Approach
// This code generates numbers in lexicographic order from 1 to n.
// The function `lexicalOrder` uses an iterative approach to build the numbers in lexicographic order.
// It starts with the number 1 and explores deeper by multiplying by 10, and backtracks when necessary.
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int curr = 1;

        for (int i = 0; i < n; ++i) {
            result.push_back(curr);  // Add current number

            if (curr * 10 <= n) {
                curr *= 10;          // Go deeper (like 1 → 10)
            } else {
                if (curr >= n || curr % 10 == 9) {
                    while (curr % 10 == 9 || curr >= n) {
                        curr /= 10;  // Backtrack (like 19 → 1)
                    }
                }
                curr += 1;           // Go to next sibling
            }
        }

        return result;
    }
};

// Example usage

int main() {
    Solution sol;
    int n = 25; // Example input
    vector<int> result = sol.lexicalOrder(n);

    // Print the result
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;   
}