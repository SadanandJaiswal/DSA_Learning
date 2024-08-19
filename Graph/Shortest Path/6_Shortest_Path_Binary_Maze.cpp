#include<bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // we will take queue instead of priority queue as the weight = 1 for each and by this we already getting the dist in increasing order means earliest one will be the shortest distance

        int n = grid.size();

        // distance matrix
        vector<vector<int>> dist (n, vector<int> (n, INT_MAX));

         if((grid[0][0] ==1 || grid[n-1][n-1] ==1)) {
            return -1;
        }

        queue<pair<int, pair<int,int>>> q; // dist, i,j
        dist[0][0] = 1;
        q.push({1, {0,0}});

        vector<int> row = {-1,-1,-1, 0, 0, 1, 1, 1};
        vector<int> col = {-1,0,1, -1, 1, -1, 0, 1};

        while(!q.empty()){
            auto it = q.front();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;
            q.pop();

            if(r ==( n-1) && c ==( n-1)){
                return dist[r][c];
            }

            for(int i=0; i<8; i++){
                int nrow = r + row[i];
                int ncol = c + col[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0){
                    if(dist[nrow][ncol] > d +1){
                        dist[nrow][ncol] = d + 1;
                        q.push({d+1, {nrow, ncol}});
                    }
                }
            }
        }

        return -1;
    }

int main()
{
    return 0;
}