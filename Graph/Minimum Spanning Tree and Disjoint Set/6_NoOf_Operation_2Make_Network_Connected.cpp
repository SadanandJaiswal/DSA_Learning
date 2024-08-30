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
            sizeVec[upu] += sizeVec[upv];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int e = connections.size();
        if(e<n-1){
            return -1;
        }

        DisjointSet ds(n);

        for(int i=0; i<e; i++){
            auto it = connections[i];
            int u = it[0];
            int v = it[1];

            ds.unionBySize(u,v);
        }

        int ans =0;
        for(int i=0; i<n; i++){
            if(ds.findParent(i)==i){
                ans++;
            }
        }

        return  ans-1;
    }
};

int main()
{
    return 0;
}