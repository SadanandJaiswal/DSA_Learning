#include<bits/stdc++.h>
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
            sizeVec[upu] += upv;
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        
        DisjointSet ds(n*m);
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int cnt = 0;
        
        int dr[4] = {-1,0,0,1};
        int dc[4] = {0,-1,1,0};
        
        vector<int> ans;
        
        for(auto it: operators){
            int r = it[0];
            int c = it[1];
            
            if(vis[r][c]){
                ans.push_back(cnt);
                continue;
            }
            
            vis[r][c] = 1;
            cnt++;
            
            for(int i=0; i<4; i++){
                int nrow = r + dr[i];
                int ncol = c + dc[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]){
                    int adjCell = nrow*m+ncol;
                    int cell =  r*m+c;
                    
                    if(ds.findParent(cell)!=ds.findParent(adjCell)){
                        cnt--;
                        ds.unionBySize(cell, adjCell);
                    }
                }
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};

// Time Complexity: O()

int main()
{
    return 0;
}