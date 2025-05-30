#include <bits/stdc++.h>
using namespace std;

/*
    It is guarante that array will contain only one element that do not have duplicate rest all element will have one duplicate
    - Our answer will be the element which do not have same left or right element
    - to reduce the conditional statements we will check seperately for first and last index as they are boundry element
    - if n==1 || i==0 and i==n-1 these index will be checked seperately
    - pattern: 
        element before our answer will have one elm on even index and duplicate elm on odd index (even, odd)
        element after our answer will have one elm on odd index and duplicate elm on even index (odd, even)
    
*/

int single_non_duplicated(vector<int> &nums, int n){
    // if single element in arrya
    if(n==1) return nums[0];

    // ii first element is the answer
    if(nums[0]!=nums[1]) return nums[0];
    
    // if last element is the answer
    if(nums[n-1]!=nums[n-2]) return nums[n-1];

    int low = 1, high = n-2;

    while(low<=high){
        int mid = low + (high-low)/2;

        // if mid element is the answer
        if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1]) return nums[mid];

        // mid is on left of the answer -> trim array low to mid
        // left half: (even, odd)
        // condition to be on left -> if mid is odd : mid-1 elm should be equal to mid elem
        // condition to be on left -> if mid is even : mid+1 elm should be equal to mid elem
        if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])){
            low = mid + 1;
        }else{  // else mid eleement is on right side, means to trim the right array
            high = mid - 1;
        }
    }

    return -1;  // this line will not get executed as it is guaranted that it have answer
}

int main() {
    return 0;
}