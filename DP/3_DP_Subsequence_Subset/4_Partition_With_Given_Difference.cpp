#include <bits/stdc++.h>
using namespace std;

int recursion(int i, int sum, vector<int>&arr){
    if(i==0){
        if(sum==0 && arr[0] == 0) return 2;
        if(sum==0 || sum==arr[0]) return 1;
        return 0;
    }  
    
    int exclude = recursion(i-1, sum, arr);
    int include = 0;
    if(sum>=arr[i]){
        include = recursion(i-1, sum - arr[i], arr);
    }
    
    int modulo = 1e9+7;
    
    return (include + exclude)%modulo;
}
// Time Complexity: O(2^n)
// Space Complexity: O(n) -> Auxiliary stack space

int memomization(int i, int sum, vector<vector<int>> &dp, vector<int>&arr){
    if(i==0){
        if(sum==0 && arr[0] == 0) return 2;
        if(sum==0 || sum==arr[0]) return 1;
        return 0;
    }  
    
    if(dp[i][sum]!=-1) return dp[i][sum];
    
    int exclude = memomization(i-1, sum, dp, arr);
    int include = 0;
    if(sum>=arr[i]){
        include = memomization(i-1, sum - arr[i], dp, arr);
    }
    
    int modulo = 1e9+7;
    
    return dp[i][sum] = (include + exclude)%modulo;
}
// Time Complexity: O(n*sum)
// Space Complexity:  O(n*sum) + O(n) -> Auxiliary stack space

int tabulation(int sum, vector<int>&arr){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum+1, 0));
    
    if(arr[0]==0) dp[0][0]=2;
    else dp[0][0] = 1;
    
    if(arr[0]!=0 && sum>=arr[0]) dp[0][arr[0]] = 1;
    
    for(int i=1; i<n; i++){
        for(int j=0; j<=sum; j++){
            int exclude = dp[i-1][j];
            int include = 0;
            if(j>=arr[i]){
                include = dp[i-1][j-arr[i]];
            }
            
            int modulo = 1e9+7;
            dp[i][j] = (include + exclude)%modulo;
        }
    }
    
    return dp[n-1][sum];
}
// Time Complexity: O(n*sum)
// Space Complexity:  O(n*sum) 

int spaceOptimization(int sum, vector<int>&arr){
    int n = arr.size();
    vector<int> prev(sum+1, 0), curr(sum+1,0);
    
    if(arr[0]==0) prev[0] = 2;
    else prev[0] = 1;
    
    if(arr[0]!=0 && sum>=arr[0]) prev[arr[0]] = 1;
    
    
    for(int i=1; i<n; i++){
        for(int j=0; j<=sum; j++){
            int exclude = prev[j];
            int include = 0;
            if(j>=arr[i]){
                include = prev[j-arr[i]];
            }
            
            int modulo = 1e9+7;
            
            curr[j] = (include + exclude)%modulo;
        }
        prev = curr;
    }
    
    return prev[sum];
}
// Time Complexity: O(n*sum)
// Space Complexity:  O(sum)

int countPartitions(int n, int d, vector<int>& arr) {
    // Code here
    int total = 0;
    for(int i=0; i<n; i++){
        total += arr[i];
    }
    
    if(total - d <0 || (total-d)%2==1) return 0;
    
    int k = (total - d)/2;
    
    // return recursion(n-1, k, arr);
    
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    
    // return memomization(n-1, k, dp, arr);
    
    // return tabulation(k, arr);
    
    return spaceOptimization(k, arr);
}

int main() {
    return 0;
}