#include <bits/stdc++.h>
using namespace std;

/*
    Question: Array is given with a threshold, need to find the smallest divisor such that sum of ceil value of all elment in array is less than equal to threshold
    Edge Case: minimum threshold valuue should be equal to size of array : t==n
    Approach: 
        - If we devide the elements with max element in array or any higer number than sum of ceil will be equal to size of array, and minimum divisor possible for this case is 1
        - Answer range will be 1 to max_element
        - if mid is our answer, such that its ceil valuue for all is less than equal to threshold, then we will checek for more smaller mid value, i.e: high = mid - 1
        - else we need to get higher value: low = mid + 1

*/

bool isValidAnswer(vector<int> &v, int t, int mid){
    int ans = 0;
    for(int i=0; i<v.size(); i++){
        ans += (v[i] + mid - 1)/mid;
    }

    return ans<=t;  // is mid a valid answer, that is is sum of ceil valuue is less than equal to threshold
}

int smallest_divisor_given_threshold(vector<int> &nums, int threshold){
    int low = 1, high = *max_element(nums.begin(), nums.end());

    while(low<=high){
        int mid = low + (high - low)/2;

        if(isValidAnswer(nums, threshold, mid)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return low;
}
// Time Complexity: O(n*log(max_element))

int main() {
    return 0;
}