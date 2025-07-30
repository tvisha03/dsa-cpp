#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

// ------------------------ Helpers ------------------------
inline int leftChild(int i)  { return 2 * i + 1; }
inline int rightChild(int i) { return 2 * i + 2; }

// ------------------------ Max-Heap ------------------------
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = leftChild(i);
    int r = rightChild(i);

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest); // sift down recursively
    }
}

void buildMaxHeap(int arr[], int n) {
    // Start from the last internal node and heapify down
    for (int i = n / 2 - 1; i >= 0; --i) {
        maxHeapify(arr, n, i);
    }
}

// ------------------------ Min-Heap ------------------------
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int l = leftChild(i);
    int r = rightChild(i);

    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest); // sift down recursively
    }
}

void buildMinHeap(int arr[], int n) {
    // Start from the last internal node and heapify down
    for (int i = n / 2 - 1; i >= 0; --i) {
        minHeapify(arr, n, i);
    }
}

// ------------------------ Utility ------------------------
void printArray(const int arr[], int n, const string& label) {
    cout << label << ": ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i + 1 == n ? '\n' : ' ');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter number of elements: ";
    if (!(cin >> n) || n < 0) {
        cerr << "Invalid n\n";
        return 1;
    }

    vector<int> input(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) cin >> input[i];

    // Copy input to raw arrays for separate heaps
    vector<int> maxArr = input;
    vector<int> minArr = input;

    // Build heaps (in-place on arrays)
    buildMaxHeap(maxArr.data(), n);
    buildMinHeap(minArr.data(), n);

    // Output
    printArray(input.data(), n, "Original");
    printArray(maxArr.data(), n, "Max-Heap array");
    printArray(minArr.data(), n, "Min-Heap array");

    // Heads-up: Printed arrays are the level-order (breadth-first) representation
    // of the heap, not a sorted order. The root is at index 0.

    return 0;
}
