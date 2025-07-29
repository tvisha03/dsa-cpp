#include <vector>
#include <stack>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> nGE(n);
        stack<int> st;

        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            if(i<n){
                nGE[i]=st.empty()?-1:st.top();
                
            }
            st.push(nums[i%n]);
            
        }
        return nGE;
    }
        
    
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 1};
    vector<int> result = solution.nextGreaterElements(nums);
    
    // Output the next greater elements
    cout << "Next Greater Elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}