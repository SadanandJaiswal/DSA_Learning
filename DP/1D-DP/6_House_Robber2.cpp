#include <bits/stdc++.h>
using namespace std;

int recursive(int ind, vector<int> nums){
    if(ind == 0){
        return nums[0];
    }
    if(ind < 0) return 0;

    int pick = nums[ind] + recursive(ind-2, nums);
    int notpick = recursive(ind-1, nums);

    return max(pick, notpick);
}
// Time Complexity: O(2^n);
// Space Complexity: O(N)   // recursive stack space

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

int tabulation(vector<int> &dp, vector<int> &nums){
    dp[0] = nums[0];
    int n = nums.size();

    for(int i=1; i<n; i++){
        int pick = nums[i];
        if(i>1) pick+= dp[i-2];
        int notpick = dp[i-1];

        dp[i] = max(pick, notpick);
    }

    return dp[n-1];
}
// Time Complexity: O(N)
// Space Complexity: O(N) 

int spaceOptimization(vector<int> &nums){
    int prev = nums[0];
    int prev2 = 0;
    int n = nums.size();

    for(int i=1; i<n; i++){
        int pick = nums[i] + prev2;
        int notpick = prev;
        int curr = max(pick, notpick);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}
// Time Complexity: O(N)
// Space Complexity: O(1)

int rob(vector<int>& nums) {
    vector<int> temp1, temp2;
    int n = nums.size();
    vector<int> dp1(n-1, -1);
    vector<int> dp2(n-1, -1);

    if(n==1){
        return nums[0];
    }

    for(int i=0; i<n; i++){
        if(i!=0){
            temp1.push_back(nums[i]);
        }
        if(i!=n-1){
            temp2.push_back(nums[i]);
        }
    }

    // // recursive solution
    // int ans1 = recursive(n-2, temp1);
    // int ans2 = recursive(n-2, temp2);
    // return max(ans1, ans2);
    
    // // Memomization solution
    // int ans1 = memo(n-2, dp1, temp1);
    // int ans2 = memo(n-2, dp2, temp2);
    // return max(ans1, ans2);
    
    // // Tabulation solution
    // int ans1 = tabulation(dp1, temp1);
    // int ans2 = tabulation(dp2, temp2);
    // return max(ans1, ans2);
    
    // Space Optimization Solution
    int ans1 = spaceOptimization(temp1);
    int ans2 = spaceOptimization(temp2);
    return max(ans1, ans2);
}

int main() {
    return 0;
}