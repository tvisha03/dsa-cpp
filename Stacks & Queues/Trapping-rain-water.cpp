#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {

public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int leftMax=0,rightMax=0;
        int total=0;

        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=leftMax){
                    leftMax=height[left];
                }else{
                    total+=leftMax-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=rightMax){
                    rightMax=height[right];
                }else{
                    total+=rightMax-height[right];
                }
                right--;
            }
        }
        return total;

        
    }
};

int main() {
    Solution solution;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = solution.trap(height);
    cout << "Trapped rainwater: " << result << endl;
    return 0;
}