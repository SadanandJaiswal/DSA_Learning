#include <bits/stdc++.h>
using namespace std;

int recursion(int i, int sum, vector<int> &nums){
    if(i==0){
        if(sum==0 && nums[0]==0) return 2;
        if(sum==0 || nums[0]==sum) return 1;
        return 0;
    }

    int exclude = recursion(i-1, sum, nums);
    int include = 0;
    if(sum>=nums[i]){
        include = recursion(i-1, sum - nums[i], nums);
    }
    
    return (include + exclude);
}

int memomization(int i, int sum, vector<vector<int>> &dp, vector<int> &nums){
    if(i==0){
        if(sum==0 && nums[0]==0) return 2;
        if(sum==0 || nums[0]==sum) return 1;
        return 0;
    }

    if(dp[i][sum]!=-1) return dp[i][sum];

    int exclude = memomization(i-1, sum, dp, nums);
    int include = 0;
    if(sum>=nums[i]){
        include = memomization(i-1, sum - nums[i], dp, nums);
    }
    
    return dp[i][sum] = (include + exclude);
}

int tabulation(int sum, vector<int> &nums){
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(sum+1, 0));

    if(nums[0]==0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if(nums[0]!=0 && sum>=nums[0]) dp[0][nums[0]] = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<=sum; j++){
            int exclude = dp[i-1][j];
            int include = 0;
            if(j>=nums[i]) include = dp[i-1][j - nums[i]];

            dp[i][j] = include + exclude;
        }
    }

    return dp[n-1][sum];
}

int spaceOptimization(int sum, vector<int> &nums){
    int n = nums.size();
    vector<int> prev(sum+1, 0);

    if(nums[0]==0) prev[0] = 2;
    else prev[0] = 1;

    if(nums[0]!=0 && sum>=nums[0]) prev[nums[0]] = 1;

    for(int i=1; i<n; i++){
        for(int j=sum; j>=0; j--){
            int exclude = prev[j];
            int include = 0;
            if(j>=nums[i]) include = prev[j - nums[i]];

            prev[j] = include + exclude;
        }
    }

    return prev[sum];
}

int findTargetSumWays(vector<int>& nums, int target) {
    int total = 0;
    int n = nums.size();
    for(int i=0; i<n; i++){
        total+= nums[i];
    }

    if(total-target<0 || (total-target)%2==1) return 0;

    int k = (total - target)/2;

    // return recursion(n-1, k, nums);

    vector<vector<int>> dp(n, vector<int>(k+1, -1));

    // return memomization(n-1, k, dp, nums);
    // return tabulation(k, nums);
    return spaceOptimization(k, nums);
}

int main() {
    // This Question Can be converted into the question -> count the partition with difference k
    // for all the + sign create one subset and for all -ve elm create one subset
    // S1 - S2 = target, Total = S1 + S2
    // S2 = (Total - target)/2

    // Now this question is reduced into the question: count the subset with sum (Total - target)/2

    // for (Total - target < 0 || (Total - target)%2==1) it is not possible to find any subset which satisfy the condition
    return 0;
}