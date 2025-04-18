#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), cnt(n, 1);
    
    int maxi = 1;
    int lastindex = 0;
    for(int i=0; i<n; i++){
        for(int previ=0; previ<i; previ++){
            if(nums[i]>nums[previ] && 1+dp[previ]>dp[i]){
                dp[i] = 1 + dp[previ];
                cnt[i] = cnt[previ];
            }
            else if(nums[i]>nums[previ] && 1+dp[previ]==dp[i]){
                cnt[i] += cnt[previ];
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        if(dp[i]==maxi){
            ans+= cnt[i];
        }
    }

    return ans;
}
// Time Complexity: O(n*n) + O(n)
// Space Complexity: O(2*n)

int main() {
    return 0;
}