#include<bits/stdc++.h>
using namespace std;

// Disjoin Set By Rank
class DisjointSet{
    vector<int> size, parent;
    public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    // find ultimate parent
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+= size[ulp_v]; 
        }
    }
};


int spanningTree(int V, vector<vector<int>> adj[])
{
    // wt, {u,v}
    vector<pair<int, pair<int,int>>> edges;
    
    // O(V+E)
    for(int i=0; i<V; i++){
        for(auto it: adj[i]){
            int adjNode = it[0];
            int wt = it[1];
            int node = i;
            
            edges.push_back({wt, {node, adjNode}});
        }
    }
    
    DisjointSet ds(V);
    
    // O(E log E)
    // step 1: sort edges
    sort(edges.begin(), edges.end());
    int mstWt = 0;

    // find the edges involved in the mst
    vector<pair<int,int>> mst;
    
    // O(E * 4*alpha*2)
    for(auto it: edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        
        // if belong to different component
        if(ds.findParent(u) != ds.findParent(v)){
            mstWt+= wt;
            ds.unionBySize(u,v);
            mst.push_back({u,v});
        }
    }
    
    cout<<"Edges involved in MST /n";
    for(auto it: mst){
        cout<<it.first<<" "<<it.second<<endl;
    }

    return mstWt;
}


int main()
{
    return 0;
}