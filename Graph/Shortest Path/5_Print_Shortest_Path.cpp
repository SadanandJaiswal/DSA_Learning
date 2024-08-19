#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<pair<int, int>> adj[n+1]; // 1 based indexing
    
    // create graph
    for(auto it: edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    
    // define priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, INT_MAX);
    vector<int> parent(n+1);
    
    // mark parent with themselves
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    dist[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty()) {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        // Optimization to avoid unnecessary processing
        if (d > dist[node]) continue;
        
        for(auto it: adj[node]) {
            int adjNode = it.first;
            int edgeW = it.second;
            
            if(d + edgeW < dist[adjNode]) {
                dist[adjNode] = d + edgeW;
                parent[adjNode] = node;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    
    // if destination is not reached then return -1
    if(dist[n] == INT_MAX) {
        return {-1};
    }
    
    // Construct the path
    vector<int> path;
    int node = n;
    while(node != parent[node]) {
        path.push_back(node);
        node = parent[node];
    }
    
    // Add the source node
    path.push_back(1);
    
    // Reverse to get the path from source to destination
    reverse(path.begin(), path.end());
    
    return path;
}
// Time Complexity: O(ElogV + V)

int main()
{
    return 0;
}