#include <vector>
#include <stack>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> ngeMpp;
        stack<int> st;
        
        for(int i=nums2.size()-1;i>=0;i--){
            int curr=nums2[i];
            while(!st.empty()&& st.top()<=curr){
                st.pop();
            }
            ngeMpp[curr]=st.empty()?-1:st.top();
            
            st.push(curr);

        }
        vector<int> result;
        for (int num : nums1) {
            result.push_back(ngeMpp[num]);
        }

        return result;
        
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}