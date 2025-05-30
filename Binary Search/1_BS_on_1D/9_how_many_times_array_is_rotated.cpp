#include <bits/stdc++.h>
using namespace std;

/*
    To find this we will find the index of smallest index and that will be our answer
*/

int how_many_times_array_is_rotated(vector<int> &nums){
    int low = 0, high = nums.size()-1, ans = INT32_MAX, index = -1;

    while(low<=high){
        // if duplicates
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low = low + 1;
            high = high - 1;
            continue;
        }

        if(nums[low]<=nums[mid]){
            if(nums[low]<ans){
                ans = nums[low];
                index = low;
            }
            low = mid + 1;
        }else{
            if(nums[mid]<ans){
                ans = nums[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }

    return index;
}

int main() {
    return 0;
}