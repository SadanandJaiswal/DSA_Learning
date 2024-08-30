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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        DisjointSet ds(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1){
                    ds.unionBySize(i,j);
                }
            }
        }

        int ct =0;
        for(int i=0; i<n; i++){
            if(ds.findParent(i)==i){
                ct++;
            }
        }

        return ct;
    }
};

int main()
{
    return 0;
}