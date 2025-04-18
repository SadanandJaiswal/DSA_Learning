#include <bits/stdc++.h>
using namespace std;

int LengthLongestDivisibleSubset(int n, vector<int> &num){
    // Step 1:
    sort(nums.begin(), nums.end());

    // Step 2:
    vector<int> dp(n, 1), hash(n);

    int maxi = 1;
    int lastindex = 0;

    for(int i=0; i<n; i++){
        hash[i] = i;
        for(int previ=0; previ<i; previ++){
            if(nums[i]%nums[previ]==0 && 1+dp[previ]>dp[i]){
                dp[i] = 1 + dp[previ];
                hash[i] = previ;
            }
        }

        if(dp[i]>maxi){
            maxi = dp[i];
            lastindex = i;
        }
    }

    vector<int> ans;
    ans.push_back(nums[lastindex]);

    while(hash[lastindex]!=lastindex){
        lastindex = hash[lastindex];
        ans.push_back(nums[lastindex]);
    }

    return ans;
    // There are multiple answer, we can return any one
}
// Time Complexity: O(n*n) + O(n)
// Space Complexity: O(2*n)

int main() {
    // Subset : any elm from array in any order

    // Approach

    // There are multiple answer and we can return any one, hence order of the answer is not fixed hence we will sort the array
    // Step 1: Sort the array (as we are not asked to return a fixed subset, we can change the order, so we will sort the array to make it simpler)
 
    // Step 2: Apply LIS, to find the subset (this question is coverted into LIS, just rather than checking a[i]>a[prev] check for a[i]%a[prev] as all the elm will be divisible by the last elm)

    return 0;
}