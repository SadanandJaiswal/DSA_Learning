#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

bool recursion(int i, int target, vector<int> &arr){
    if(target==0) return true;
    if(i==0) return target==arr[0];
    
    bool notTake = recursion(i-1, target, arr);
    bool take = false;
    if(target>=arr[i]) take = recursion(i-1, target-arr[i], arr);
    
    return take || notTake;
}
// Time Complexity: O(2^n)
// Space Complexity: O(n)

bool memomization(int i, int target, vector<vector<int>> &dp ,vector<int> &arr){
    if(target==0) return true;
    if(i==0) return target==arr[0];
    
    if(dp[i][target]!=-1) return dp[i][target];
    
    bool notTake = memomization(i-1, target, dp, arr);
    bool take = false;
    if(target>=arr[i]) take = memomization(i-1, target-arr[i], dp, arr);
    
    return dp[i][target] = take || notTake;
}
// Time Complexity: O(n*target)
// Space Complexity: O(n*target) + O(n)

bool tabulation(int target, vector<int> &arr){
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target+1, 0));
    
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }

    if (arr[0] <= target) {
        dp[0][arr[0]] = true; 
    }
    
    for(int i=1; i<n; i++){
        for(int j=1; j<=target; j++){
            bool notTake = dp[i-1][j];
            bool take = false;
            if(j>=arr[i]){
                take = dp[i-1][j - arr[i]];
            }
            
            dp[i][j] = notTake || take;
        }
    }
    
    return dp[n-1][target];
}
// Time Complexity: O(n*target)
// Space Complexity: O(n*target)

bool spaceOptimization(int target, vector<int> &arr){
    vector<bool> prev(target+1, false), curr(target+1);
    // don't forget to take size target+1
    int n = arr.size();
    
    prev[0] = true; // base condition
    
    if(arr[0]<=target){
        prev[arr[0]] = true;
    }
    
    for(int i=1; i<n; i++){
        curr[0] = true;
        for(int j=1; j<=target; j++){
            bool notTake = prev[j];
            bool take = false;
            if(j>=arr[i]) take = prev[j-arr[i]];
            curr[j] = notTake || take;
        }
        prev = curr;
    }
    
    return prev[target];
}
// Time Complexity: O(n*target)
// Space Complexity: O(target)

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for(int i=0; i<n; i++) sum+=nums[i];
    if(sum%2==1) return false;
    int target = sum/2;

    // return recursion(n-1, target, nums);

    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    // return memomization(n-1, target, dp, nums);

    // return tabulation(target, nums);

    return spaceOptimization(target, nums);
}

int main() {
    return 0;
}