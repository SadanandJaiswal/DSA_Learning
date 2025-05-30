#include <bits/stdc++.h>
using namespace std;

/*
    Array can have multiple peak, return any one
    Approach: 
        - Assume -infinity on both the end of the array
        - first check weather first or last element is the peak
        - if peak is on right, shift the low to mid + 1
            - condition: mid + 1 element is greater than mid element
        - if paek is on left, shift the high to mid -1
            - condition: mid -1 element is greater than mid element

        Note: if mid is on bottom of v, that is not a peak and not on increasing or decreasing slope
            : in such case it will stuck in infinite loop, solution: use else case, because both the side will have peak, so it does'nt matter go any side
            : either: low = mid + 1 or high = mid -1 bith is correct
*/

int peakElement(vector<int> &nums){
    int n = nums.size();

    if(n==1) return 0;

    if(nums[0]>nums[1]) return 0;

    if(nums[n-1]>nums[n-2]) return n-1;

    int low = 1, high = n-2;

    while(low<=high){
        int mid = low + (high-low)/2;

        // mid element is the peak
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;

        // mid is on the increasing plane, that is peak is on the right
        if(nums[mid+1]>nums[mid]){
            low = mid + 1;
        }
        // mid is on the decreasing plane, that is peak is on the left
        else{
            high = mid -1;
        }
    }

    return -1;
}
// Time Complexity: O(logN)

int main() {
    return 0;
}