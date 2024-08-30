#include<bits/stdc++.h>
using namespace std;

// Disjoin Set By Rank
class DisjointSet{
    vector<int> size, parent;
    public:
    DisjointSet(int n){
        size.resize(n+1,0);
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

int main()
{
    DisjointSet ds(7);

    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    // check if 3 and 7 belong to same component or not
    if(ds.findParent(3) == ds.findParent(7)){
        cout<<"Same"<<endl;
    }else{
        cout<<"Not Same"<<endl;
    }

    ds.unionBySize(3,7);
    
}