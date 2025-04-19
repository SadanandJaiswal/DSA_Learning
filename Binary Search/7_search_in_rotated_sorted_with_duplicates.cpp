#include <bits/stdc++.h>
using namespace std;

/*
    Earlier Approach will fails when low, mid, high element will be same
    e.g: arr[] = {3, 2, 1, 3, 3, 3, 3}
    here will not be sure in which direction we need to go as here our condition :
        arr[low]<=arr[mid] && arr[mid]<=arr[high] both will get satisfied
    hence we will trim the array when this condition is reached
*/

bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid]==target){
            return true;
        }

        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low = low + 1;
            high = high - 1;
            continue;
        }

        // left sorted
        if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<=nums[mid]){
                high = mid -1;
            }else{
                low = mid +1;
            }
        }else{  // right sorted
            if(nums[mid]<=target && target<=nums[high]){
                low = mid +1;
            }else{
                high = mid -1;
            }
        }
    }

    return false;
}

// Time Complexity: O(logN)

int main() {
    return 0;
}