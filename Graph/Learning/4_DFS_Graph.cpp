#include<bits/stdc++.h>
using namespace std;

vector<int> dfs;
// BFS Traversal of Graph
void dfsOfGraph(int node, vector<int> adj[], int vis[]){
    vis[node] = 1;
    dfs.push_back(node);

    for(auto it: adj[node]){
        if(!vis[it]){
            dfsOfGraph(it, adj, vis);
        }
    }

    return;
}
void dfsMatrix(int node, vector<vector<int>> isConnected, int vis[]){
    vis[node] =1;
    dfs.push_back(node);
    int V = isConnected.size();

    for(int i=0; i<V; i++){
        if(!vis[i] && isConnected[node][i]){
            dfsMatrix(i,isConnected, vis);
        }
    }
}
// Time Complexity: O(V+2*E) = O(V+E)   // V: total node, E: total edges
// Space Complexity: O(3*N) = O(N)

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