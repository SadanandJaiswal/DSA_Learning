#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0){
                    dp[i][j] = matrix[i][j]-'0';
                }else if(matrix[i][j]=='1'){
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                }
                ans = max(ans, dp[i][j]);
            }
        }

        return ans*ans;
    }
};
// Time Complexity : O(n*m)
// Space Complexity : O(n*m)



class SolutionSpaceOptimized {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> dp(m, 0);
        int ans = 0;

        for(int i=0; i<n; i++){
            int diagonal = 0;
            for(int j=0; j<m; j++){
                int top = dp[j];

                if(i==0 || j==0){
                    dp[j] = matrix[i][j]-'0';
                }else if(matrix[i][j]=='1'){
                    dp[j] = 1 + min({diagonal, dp[j], dp[j-1]});
                }else{
                    dp[j] = 0;
                }

                diagonal = top;
                ans = max(ans, dp[j]);
            }
        }

        return ans*ans;
    }
};
// Time Complexity : O(n*m)
// Space Complexity : O(m) where m is the number of columns in the matrix