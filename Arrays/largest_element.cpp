//Brute Force Approach

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sortArr(vector<int> &arr){
    sort(arr.begin(), arr.end());
    return arr[arr.size() - 1];
}

//Using Recursion
int findLargest(vector<int> &arr, int n){
    if (n == 1)
        return arr[0];
    return max(arr[n - 1], findLargest(arr, n - 1));
}
//Using Iteration
int findLargestIterative(vector<int> &arr, int n){
    int largest = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > largest)
            largest = arr[i];
    }
    return largest;
}
int main(){
    vector<int> arr = {4, 2, 9, 2, 7, 5, 1};
    cout << "Array elements are: ";
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Largest element is: " << sortArr(arr) << endl;
    return 0;
}

