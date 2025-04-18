#include <bits/stdc++.h>
using namespace std;

int recursion(int i, int previ, vector<int> &nums){
    if(i==nums.size()) return 0;

    int notTake = recursion(i+1, previ, nums);
    int take = 0;
    if(previ==-1 || nums[i] > nums[previ]){
        take = 1 + recursion(i+1, i, nums);
    }

    return max(take, notTake);
}
// Time Complexity: O(2^n)
// Space Complexity: O(n)

int memoization(int i, int previ, vector<vector<int>> &dp, vector<int> &nums){
    if(i==nums.size()) return 0;

    if(dp[i][previ+1]!=-1) return dp[i][previ+1];

    int notTake = memoization(i+1, previ, dp, nums);
    int take = 0;
    if(previ==-1 || nums[i] > nums[previ]){
        take = 1 + memoization(i+1, i, dp, nums);
    }

    return dp[i][previ+1] = max(take, notTake);
}
// Time Complexity: O(n*n)
// Space Complexity: O(n*n) + O(n)

int tabulation(int n, vector<int> &nums){
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int i=n-1; i>=0; i--){
        // previ cannot be greater than equal to ind
        for(int previ=i-1; previ>=-1; previ--){
            int notTake = dp[i+1][previ+1];
            int take = 0;
            if(previ==-1 || nums[i]>nums[previ]){
                take = 1 + dp[i+1][i+1];    // inseated of i , previ is i+1
            }
            dp[i][previ+1] = max(take, notTake);
        }
    }

    return dp[0][0];
}
// Time Complexity: O(n*n)
// Space Complexity: O(n*n)

int spaceOptimization(int n, vector<int> &nums){
    vector<int> prev(n+1, 0), curr(n+1, 0);

    for(int i=n-1; i>=0; i--){
        // previ cannot be greater than equal to ind
        for(int previ=i-1; previ>=-1; previ--){
            int notTake = prev[previ+1];
            int take = 0;
            if(previ==-1 || nums[i]>nums[previ]){
                take = 1 + prev[i+1];    // inseated of i , previ is i+1
            }
            curr[previ+1] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[0];
}
// Time Complexity: O(n*n)
// Space Complexity: O(2*n)

int optimalTabulation(int n, vector<int>& nums){
    vector<int> dp(n, 1);

    int maxi = 1;

    for(int i=0; i<n; i++){
        for(int previ=0; previ<i; previ++){
            if(nums[i]>nums[previ]){
                dp[i] = max(dp[i], 1 + dp[previ]);
            }
        }
        maxi = max(maxi, dp[i]);
    }

    return maxi;
}
// Time Complexity: O(n*n)
// Space Complexity: O(n)

int lengthOfLIS(vector<int>& nums) {
    // return recursion(0, -1, nums);

    int n = nums.size();

    // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    // As previ is -1 we will do coordinate change, previ+1
    // return memoization(0, -1, dp, nums);

    // return tabulation(n, nums);

    return spaceOptimization(n, nums);
}

int main() {
    return 0;
}