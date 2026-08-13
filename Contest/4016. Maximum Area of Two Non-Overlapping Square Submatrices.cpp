#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool haveValidSquares(int k, vector<vector<int>> &prefsum){
        int n = prefsum.size(), m=prefsum[0].size();

        int minRow = n, minCol = m, maxRow = -1, maxCol = -1;

        for(int i=0; i+k<n; i++){
            for(int j=0; j+k<m; j++){
                int sum = prefsum[i+k][j+k] 
                    - prefsum[i][j+k]
                    - prefsum[i+k][j]
                    + prefsum[i][j];

                if(sum!=k*k) continue;

                minRow = min(minRow, i);
                minCol = min(minCol, j);

                maxRow = max(maxRow, i);
                maxCol = max(maxCol, j);
            }

            if(maxRow-minRow>=k || maxCol-minCol>=k){
                return true;
            }
        }

        return false;
    }

public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m=mat[0].size();
        vector<vector<int>> prefsum(n+1, vector<int>(m+1, 0));

        // calculate prefix sum : O(n*m)
        for(int i=0; i<n ;i++){
            for(int j=0; j<m; j++){
                prefsum[i+1][j+1] = mat[i][j] 
                    + prefsum[i][j+1]
                    + prefsum[i+1][j]
                    - prefsum[i][j];
            }
        }

        // binary search on answer : O(log(min(n,m)))
        int low = 1, high = min(n,m), ans =0;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(haveValidSquares(mid, prefsum)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return ans*ans;
    }
};
// Time Complexity : O(n*m*log(min(n,m)))
// Space Complexity : O(n*m) for prefix sum