#include<bits/stdc++.h>
using namespace std;


class SolutionMemoization {
public:
    int solve(int ind, vector<int>& dp, vector<int>& nums){
        if(ind==nums.size()-1) return 0;

        if(nums[ind]==0) return INT_MAX;

        if(dp[ind]!=-1) return dp[ind];

        int ans = INT_MAX;
        int end = min(ind+nums[ind], (int)nums.size()-1);

        for(int i = ind+1; i<=end; i++){
            int jumps = solve(i,dp,nums);
            if(jumps!=INT_MAX){
                ans = min(ans, 1+jumps);
            }
        }

        return dp[ind] = ans;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0,dp,nums);
    }
};
// Time Complexity : O(n*n)
// Space Complexity : O(n) + O(n) Recursion Stack


class SolutionTabulation {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);

        dp[nums.size()-1] = 0;

        for(int i=nums.size()-2; i>=0; i--){
            int end = min(i+nums[i], (int)nums.size()-1);

            for(int j=i+1; j<=end; j++){
                if(dp[j]!=INT_MAX){
                    dp[i] = min(dp[i], 1+dp[j]);
                }
            }
        }
        return dp[0];
    }
};
// Time Complexity : O(n*n)
// Space Complexity : O(n)