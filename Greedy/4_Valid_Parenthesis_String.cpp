#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int i, int balance, vector<vector<int>> &dp, string s){
        if(i==s.size())
            return balance==0;
        
        if(balance<0) return false;

        if(dp[i][balance]!=-1)
            return dp[i][balance];

        bool ans;

        if(s[i]=='('){
            ans = solve(i+1, balance+1, dp, s);
        }else if(s[i]==')'){
            ans = solve(i+1, balance-1, dp, s);
        }else{
            ans =   solve(i+1, balance+1, dp, s) ||   // '('
                    solve(i+1, balance-1, dp, s) ||   // ')'
                    solve(i+1, balance, dp, s);
        }

        return dp[i][balance] = ans;
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); 
        return solve(0,0,dp,s);
    }
};
// Time Complexity : O(n*n)
// Space Complexity : O(n*n)


class SolutionOptimal {
public:
    bool checkValidString(string s) {
        int minBal = 0, maxBal = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                minBal++;
                maxBal++;
            }else if(s[i]==')'){
                minBal--;
                maxBal--;
            }else{
                minBal--;
                maxBal++;
            }

            if(maxBal<0) return false;

            minBal = max(0, minBal);
        }

        return minBal==0;
    }
};