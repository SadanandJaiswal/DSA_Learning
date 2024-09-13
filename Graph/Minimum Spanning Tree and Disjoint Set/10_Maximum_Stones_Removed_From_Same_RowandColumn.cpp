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
    int removeStones(vector<vector<int>>& stones) {
        int n =0, m =0;

        for(auto it: stones){
            n = max(n, it[0]);
            m = max(m, it[1]);
        }

        // row and col will be acts as nodes in DSU
        DisjointSet ds(n+m+1);

        for(auto it: stones){
            int r = it[0];
            int c = it[1] + n + 1;

            ds.unionBySize(r,c);
        }

        int ans = 0;

        for(int i=0; i<(n+m+1); i++){
            if(ds.parent[i]==i && ds.sizeVec[i]>1){
                ans++;
            }
        }

        return stones.size()-ans;
    }
};
// Time Complexity: O(k * alpha(N))
// alpha(N) -> inverse ackermann functiion (constant)
// k is total number of stones

int main() {
    return 0;
}