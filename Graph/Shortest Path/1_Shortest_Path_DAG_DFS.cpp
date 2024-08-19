#include<bits/stdc++.h>
using namespace std;

void toposort(int node, vector<pair<int,int>> adj[], vector<int> &vis, stack<int> &st){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it.first]){
                toposort(it.first, adj, vis, st);
            }
        }
        
        st.push(node);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(int i=0; i<M; i++){ // O(M)
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            // adj[v].push_back(u);
        }
        
        vector<int> vis(N, 0);
        stack<int> st;
        
        
        for(int i=0; i<N; i++){ // O(N+M)
            if(!vis[i]){
                toposort(i, adj, vis, st);
            }
        }
        
        vector<int> dist(N, 1e9);
        dist[0]=0;
        
        while (!st.empty()) {   // O(N+M)
            int node = st.top();
            st.pop();

                for (auto it : adj[node]) { // total O(M)
                    int d = it.second;
                    if (dist[node] + d < dist[it.first]) {
                        dist[it.first] = dist[node] + d;
                    }
                }
            // if (dist[node] != INT_MAX) {
            // }
        }
        
        for(int i=0; i<N; i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        
        return dist;
    }
    // Time Complexity: O(N+M)  // N is no of nodes, M is nu of edges
    // Space Complexity: O(N+M)  // N is no of nodes, M is nu of edges

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