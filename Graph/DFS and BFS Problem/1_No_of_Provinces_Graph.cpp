#include<bits/stdc++.h>
using namespace std;

vector<int> dfs;
// BFS Traversal of Graph
void dfsOfGraph(int node, vector<int> adj[], int vis[]){
    vis[node] = 1;
    dfs.push_back(node);

    for(auto it: adj[node]){
        if(!vis[it]){
            vis[it] = 1;
            dfsOfGraph(it, adj, vis);
        }
    }

    return;
}
int numberofProvinces(vector<vector<int>> adj, int V){
    // convert matrix to list
    vector<int> adjLs[V];
    for(int i =0; i<V; i++){
        for(int j=0; j<V; j++)
        {
            if(adj[i][j]==1 && i!=j){
                adjLs[i].push_back(j);
                adjLs[j].push_back(i); // for undirected graph
            }
        }
    }

    int count =0;
    int vis[V+1] = {0};

    for(int i=1; i<=V; i++){
        if(!vis[i])
        {
            dfsOfGraph(i, adjLs, vis);    // we can use bfs as well
            count++;
        }
    }

    return count;
}
// Time Complexity: O(N)    // N+V+E : N for n nodes and V+E for dfs
// Space Complexity: O(N)   // N for dfs

int main(){
    int n,m;
    cin>>n>>m;

    // 2) adjacency list
    // use array of size n with empty list
    vector<int> alist[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        // u--->v
        alist[u].push_back(v);
        // alist[v].push_back(1);
    }
    // space complexity: O(E)   // only adjacent will be inserted

}