#include<bits/stdc++.h>
using namespace std;

/*
Binary Search is an efficient algorithm used to find the position of a target element in a sorted array. It works by repeatedly dividing the search interval in half.
*/

int binary_search_iterative(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;

    while(low<=high){
        // int mid = (low+high)/2;
        int mid = low + (high-low)/2;

        if(arr[mid]==target) return mid;
        else if(arr[mid]>target){
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }

    return -1;
}

int binary_search_recursive(vector<int> &arr, int low, int high, int target){
    if(low>high) return -1;

    // int mid = (low+high)/2;
    int mid = low + (high-low)/2;

    if(arr[mid]==target) return mid;
    else if(arr[mid]>target){
        return binary_search_recursive(arr, low, mid-1, target);
    }else{
        return binary_search_recursive(arr, mid+1, high, target);
    }
}

// Time Complexity: O(logN)
// Space Complexity: O(logN) for recursive stack

int main(){
    return 0;
}
