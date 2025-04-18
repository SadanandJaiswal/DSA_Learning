#include <bits/stdc++.h>
using namespace std;

vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {    
    vector<int> dp(n, 1), hash(n);
    
    for(int i=0; i<n; i++) hash[i] = i;
    
    int lastindex = 0;
    int maxi = 1;
    
    for(int i=0; i<n; i++){
        for(int previ = 0; previ<i; previ++){
            
            if(arr[i]>arr[previ] && 1+dp[previ]>dp[i]){
                
                dp[i] = 1 + dp[previ];
                
                hash[i] = previ;
            }
        }
        
        if(dp[i]>maxi){
            maxi = dp[i];
            lastindex = i;
        }
    }
    
    vector<int> lis;
    lis.push_back(arr[lastindex]);
    int ind = 1;
    while(hash[lastindex]!=lastindex){
        lastindex = hash[lastindex];
        
        lis.push_back(arr[lastindex]);
    }
    
    reverse(lis.begin(), lis.end());
    
    return lis;
}
// Time Complexity: O(n*n) + O(n)
// Space Complexity: O(2*n)

int main() {
    return 0;
}