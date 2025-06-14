#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1, k=m+n-1;
        while(j >= 0){
            if(i >= 0 && nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};

int main() {
    int arr1[] = {1, 2, 3, 0, 0, 0};
    int arr2[] = {2, 5, 6};
    vector<int> nums1(arr1, arr1 + 6);
    vector<int> nums2(arr2, arr2 + 3);

    Solution sol;
    sol.merge(nums1, 3, nums2, 3);

    cout << "Merged nums1: ";
    for (size_t i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}
