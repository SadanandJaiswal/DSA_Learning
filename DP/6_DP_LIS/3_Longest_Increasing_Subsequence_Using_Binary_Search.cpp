#include <bits/stdc++.h>
using namespace std;

int LengthOfLISUsingBinarySearch(int n, vector<int> &nums){
    vector<int> ans;
    ans.push_back(nums[0]);

    for(int i=1; i<n; i++){
        if(nums[i]>ans.back()){
            ans.push_back(nums[i]);
        }else{
            // Direct CPP function which return index of elm if found in vector/array if not then return the index of first elm in vector that is greater than the target elm
            auto it = lower_bound(ans.begin(), ans.end(), nums[i]);

            // replace the elm with ans[ind]
            *it = nums[i];
        }
    }

    return ans.size();
}
// Time Complexity: O(n*log(n))
// Space Complexity: O(n)

int main() {
    // This will Only Return the Size of the Longest Increasing Subsequence, but can't print the LIS
    return 0;
}