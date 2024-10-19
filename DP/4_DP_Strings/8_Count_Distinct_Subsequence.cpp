#include <bits/stdc++.h>
using namespace std;

int recursion(int i, int j, string &s, string &t){
    if(j<0) return 1;
    if(i<0) return 0;

    if(s[i]==t[j]){
        return recursion(i-1, j-1, s, t) + recursion(i-1, j, s, t);
    }

    return recursion(i-1, j, s, t);
}
// Time Complexity: exponential -> O(2^n * 2^m)
// Space Complexity: O(n+m) -> recursive stack space

int memomization(int i, int j, vector<vector<int>> &dp, string &s, string &t){
    if(j==0) return 1;
    if(i==0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i-1]==t[j-1]){
        return dp[i][j] =  memomization(i-1, j-1, dp, s, t) + memomization(i-1, j, dp, s, t);
    }

    return dp[i][j] = memomization(i-1, j, dp, s, t);
}
// Time Complexity: O(n*m)
// Space Complexity: O(n*m) + O(n+m)

int tabulation(int n, int m, string &s, string &t){
    vector<vector<double>> dp(n+1, vector<double>(m+1, 0));
    // Take double when int giving tle, and in returning return by typecasting

    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return (int)dp[n][m];
}
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

int spaceOptimization(int n, int m, string &s, string &t){
    vector<long long> prev(m+1, 1), curr(m+1, 0);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1]==t[j-1]){
                curr[j] = (prev[j-1] + prev[j]);
            }else{
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }

    return (int)prev[m];
}
// Time Complexity: O(n*m)
// Space Complexity: O(m)

int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();

    // return recursion(n-1, m-1, s, t);

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    // return memomization(n, m, dp, s, t);

    // return tabulation(n, m, s, t); 

    return spaceOptimization(n, m, s, t); 
}

int main() {
    return 0;
}