#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int t) {
        vector<vector<int>> mat(n, vector<int>(n, 1e9));

        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            mat[u][v] = wt;
            mat[v][u] = wt;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) mat[i][j] = 0;
            }
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(mat[i][k]==1e9 || mat[k][j]==1e9){
                        continue;
                    }
                    mat[i][j] = min(mat[i][j],
                    mat[i][k] + mat[k][j]);
                }
            }
        }

        int mini = INT_MAX;
        int city = -1;

        for(int i=0; i<n; i++){
            int ct = 0;
            for(int j=0; j<n; j++){
                if(mat[i][j]<=t) ct++;
            }

            if(ct<=mini){
                mini = ct;
                city = i;
            }
        }

        return city;
    }
};

// Time Complexity: O(V*V*V)
// Space Complexity: O(V*V);

int main()
{
    return 0;
}