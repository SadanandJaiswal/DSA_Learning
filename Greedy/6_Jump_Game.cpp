#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>

class SolutionMemoization {
public:
    bool solve(int ind, vector<int> &dp, vector<int> &nums){
        if(ind==nums.size()-1){
            return true;
        }

        if(dp[ind]!=-1) return dp[ind];

        if(nums[ind]==0) return false;

        bool ans = false;

        int l = min(ind+nums[ind], (int)nums.size()-1);

        for(int i=ind+1; i<=l; i++){
            if(solve(i, dp, nums))
                return true;
        }

        return dp[ind] = ans;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return solve(0, dp, nums);
    }
};
// Time Complexity : O(n*n)
// Space Complexity : O(n) + O(n) Recursion Stack

class SolutionTabulation {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[nums.size()-1]=true;
        for(int i=nums.size()-2; i>=0; i--){
            int l = min(i+nums[i], (int)nums.size()-1);

            for(int j=i+1; j<=l; j++){
                if(dp[j]){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
// Time Complexity : O(n*n)
// Space Complexity : O(n)


class SolutionGreedy {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for(int i=0; i<nums.size(); i++){
            if(farthest==nums.size()-1) break;

            farthest = max(farthest, i+nums[i]);

            if(farthest<i+1) return false;
        }

        return true;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(1)