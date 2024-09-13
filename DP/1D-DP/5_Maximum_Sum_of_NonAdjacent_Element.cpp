#include <bits/stdc++.h>
using namespace std;

int recursion(int ind, vector<int> &nums){
    if(ind==0) return nums[0];
    if(ind<0) return 0;

    int pick = nums[ind] + recursion(ind-2, nums);
    int notpick = 0 + recursion(ind-1, nums);

    return max(pick, notpick);
}
// Time Complexity: O(2^n)
// Space Complexity: O(N) for recursive stack space

int memo(int ind, vector<int> &dp, vector<int> &nums){
    if(ind==0) return nums[0];
    if(ind<0) return 0;

    if(dp[ind]!=-1) return dp[ind];

    int pick = nums[ind] + memo(ind-2, dp, nums);
    int notpick = 0 + memo(ind-1, dp, nums);

    return dp[ind] = max(pick, notpick);
}
// Time Complexity: O(N)
// Space Complexity: O(N) + O(N) for recursive stack space

int tabulation(int n, vector<int> &dp, vector<int> &nums){
    dp[0] = nums[0];

    for(int i=1; i<n; i++){
        int take = nums[i];
        if(i>1) take+= dp[i-2];

        int nottake = 0 + dp[i-1];
        dp[i] = max(take, nottake);
    }

    return dp[n-1];
}
// Time Complexity: O(N)
// Space Complexity: O(N) 

int spaceOptimization(int n, vector<int> &nums){
    int prev = nums[0];
    int prev2 = 0;

    for(int i=1; i<n; i++){
        int take = nums[i];
        if(i-2>=0){
            take+= prev2;
        }
        int nottake = 0 + prev;

        int curr = max(take , nottake);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}
// Time Complexity: O(N);
// Space Complexity: O(1)

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    // return recursion(n-1, nums);
    // return memo(n-1, dp, nums);
    // return tabulation(n, dp, nums);
    return spaceOptimization(n, nums);
}

int main() {
    return 0;
}