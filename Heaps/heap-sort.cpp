#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

// 0-indexed helpers
inline int leftChild(int i)  { return 2*i + 1; }
inline int rightChild(int i) { return 2*i + 2; }

// ----- Max-heapify: arr[i] "sift down" within size n -----
void maxHeapify(vector<int>& arr, int n, int i) {
    while (true) {
        int largest = i;
        int l = leftChild(i), r = rightChild(i);
        if (l < n && arr[l] > arr[largest]) largest = l;
        if (r < n && arr[r] > arr[largest]) largest = r;
        if (largest == i) break;
        swap(arr[i], arr[largest]);
        i = largest; // continue sifting down
    }
}

// ----- Build max-heap in O(n) -----
void buildMaxHeap(vector<int>& arr) {
    int n = (int)arr.size();
    for (int i = n/2 - 1; i >= 0; --i) {
        maxHeapify(arr, n, i);
    }
}

// ----- Heap sort ascending using max-heap -----
void heapSortAscending(vector<int>& arr) {
    int n = (int)arr.size();
    buildMaxHeap(arr);
    for (int end = n - 1; end > 0; --end) {
        swap(arr[0], arr[end]);          // put current max at the end
        maxHeapify(arr, end, 0);         // restore heap in arr[0..end-1]
    }
}

// (Optional) Min-heap for descending
void minHeapify(vector<int>& arr, int n, int i) {
    while (true) {
        int smallest = i;
        int l = leftChild(i), r = rightChild(i);
        if (l < n && arr[l] < arr[smallest]) smallest = l;
        if (r < n && arr[r] < arr[smallest]) smallest = r;
        if (smallest == i) break;
        swap(arr[i], arr[smallest]);
        i = smallest;
    }
}

void buildMinHeap(vector<int>& arr) {
    int n = (int)arr.size();
    for (int i = n/2 - 1; i >= 0; --i) {
        minHeapify(arr, n, i);
    }
}

void heapSortDescending(vector<int>& arr) {
    int n = (int)arr.size();
    buildMinHeap(arr);
    for (int end = n - 1; end > 0; --end) {
        swap(arr[0], arr[end]);          // put current min at the end
        minHeapify(arr, end, 0);         // restore min-heap in arr[0..end-1]
    }
}

// ---- Demo ----
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter n: ";
    if (!(cin >> n) || n < 0) return 0;

    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> asc = a, desc = a;

    heapSortAscending(asc);   // ascending
    heapSortDescending(desc); // descending

    cout << "Ascending: ";
    for (int x : asc) cout << x << ' ';
    cout << '\n';

    cout << "Descending: ";
    for (int x : desc) cout << x << ' ';
    cout << '\n';

    return 0;
}
