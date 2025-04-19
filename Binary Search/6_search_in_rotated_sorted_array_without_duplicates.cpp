#include <bits/stdc++.h>
using namespace std;

/*
    step 1: first check is mid the target elem
    step 2: then check which part either left / right part is sorted
    step 3: if target lies in sorted part then go with sorted part or with the unsorted part
*/

int binary_search_in_sorted_rotated_without_duplicates(vector<int> &arr, int n, int target){
    int low = 0, high = n-1;
        
    while(low<=high){
        int mid = low + (high-low)/2;

        if(arr[mid]==target) return mid;

        // left sorted
        if(arr[low]<=arr[mid]){
            if(arr[low]<=target && target<=arr[mid]){
                high = mid -1;
            }else{
                low = mid +1;
            }
        }else{  // right sorted
            if(arr[mid]<=target && target<=arr[high]){
                low = mid +1;
            }else{
                high = mid -1;
            }
        }
    }

    return -1;
}

// Time Complexity: O(logN) base 2

int main() {
    return 0;
}