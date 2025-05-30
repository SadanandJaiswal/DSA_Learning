#include <bits/stdc++.h>
using namespace std;

/*
    Upper Bound: smallest index where: arr[i]>target
*/

int upper_bound_iterative(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0, high = n-1;

    while(low<high){
        int mid = low + (high-low)/2;

        if(arr[mid]>target){
            high = mid;
        }else{
            low = mid+1;
        }
    }

    return low;
}

int upper_bound_recursive(vector<int> &arr, int low, int high, int target){
    if(low>=high) return low;

    int mid = low + (high-low)/2;

    if(arr[mid]>target){
        return upper_bound_recursive(arr, low, mid, target);
    }else{
        return upper_bound_recursive(arr, mid+1, high, target);
    }
}

// Time Complexity: O(logN);

int main() {
    vector<int> vec = {1, 2, 4, 4, 5, 6};
    int target = 4;

    int arr[] = {1, 2, 4, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    auto it = upper_bound(vec.begin(), vec.end(), target);
    int index = it - vec.begin();
    return 0;
}