#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int> sizeVec, parent;
    DisjointSet(int n){
        sizeVec.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int upu = findParent(u);
        int upv = findParent(v);

        if(upu == upv) return;

        if(sizeVec[upu] < sizeVec[upv]){
            parent[upu] = upv;
            sizeVec[upv] += sizeVec[upu];
        }else{
            parent[upv] = upu;
            sizeVec[upu] += sizeVec[upv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        int dr[4] = {0, -1, 1, 0};
        int dc[4] = {-1, 0, 0, 1};

        for(int i=0; i<n; i++){   
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    int cellno = i*n+j;

                    for(int k=0; k<4; k++){
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        int adjcell = nr*n+nc;

                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                            if(ds.findParent(adjcell)!=ds.findParent(cellno)){
                                ds.unionBySize(cellno, adjcell);
                            }
                        }
                    }
                }
            }
        }

        int ans = 0;

        for(int i=0; i<n*n; i++){
            ans = max(ans, ds.sizeVec[i]);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                if(grid[i][j]==0){
                    int count = 1;
                    unordered_set<int> st;
                    for(int k=0; k<4; k++){
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        int adjcell = nr*n+nc;

                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                            int ulp = ds.findParent(adjcell);

                            if(st.find(ulp)==st.end()){
                                count+= ds.sizeVec[ulp];
                                st.insert(ulp);
                            }
                        }
                    }

                    // for(auto it: st){
                    //     int ulp = it;
                    //     count+= ds.sizeVec[ulp];
                    // }
                    ans = max(ans, count);
                }
            }
        }

        return ans;
    }
};

// Time Complexity => O(n*n);
// Space Complexity => O(n*n);

int main() {
    return 0;
}