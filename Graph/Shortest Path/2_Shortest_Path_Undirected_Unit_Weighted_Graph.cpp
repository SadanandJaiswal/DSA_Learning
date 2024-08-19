#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPathBFS(vector<vector<int>> edges, int n, int m, int src){
    // create adj list
    vector<int> adj[n];
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n, INT_MAX);
    dist[src]=0;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int it: adj[node]){
            if(dist[it]> dist[node]+1){
                dist[it] = dist[node]+1;
                q.push(it);
            }
        }
    }

    for(int i=0; i<n; i++){
        if(dist[i]==INT_MAX){
            dist[i] = -1;
        }
    }

    return dist;
}
// Time Complexity: O(N+M);
// Space Complexity: O(N+M);

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
}