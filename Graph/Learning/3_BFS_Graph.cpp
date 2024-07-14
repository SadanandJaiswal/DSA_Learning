#include<bits/stdc++.h>
using namespace std;

// BFS Traversal of Graph
vector<int> bfsOfGraph(int v, vector<int> adj[]){
    int vis[v] ={0};
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    vector<int> bfs;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it: adj[node]){    // this will run for each node and for there degree times
            if(!vis[it]){
                vis[it] =1;
                q.push(it);
            }
        }
    }

    return bfs;
}
vector<int> bfsMatrix(int v, vector<vector<int>> isConnected){
    int vis[v] ={0};
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    vector<int> bfs;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(int i=0; i<v; i++){
            if(isConnected[node][i] && !vis[i]){
                vis[i] =1;
                q.push(i);
            }
        }
    }

    return bfs;
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