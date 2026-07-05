// Sorted Array will have at most K elements away from its target position. i-k to i+k will be the range of the target position of the element at index i. So we can use a min heap of size k+1 to sort the array.

#include <bits/stdc++.h>
using namespace std;

void SortKSorted(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int idx = 0;

    for (int i = 0; i < n; i++) {
        minHeap.push(arr[i]);

        if (minHeap.size() > k ) {
            arr[idx++] = minHeap.top();
            minHeap.pop();
        }
    }

    while (!minHeap.empty()) {
        arr[idx++] = minHeap.top();
        minHeap.pop();
    }
}

int main() {
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    SortKSorted(arr, n, k);

    cout << "Sorted Array:\n";
    for (int x : arr)
        cout << x << " ";
}