#include<bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
    // code here
    vector<pair<int,int>> adj[n];
    
    for(auto it: roads){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
    // node, dist

    vector<long long> dist(n, LLONG_MAX);
    vector<long long> ways(n, 0);

    dist[0] = 0;
    ways[0] = 1;
    pq.push({0,0});

    int mod = (int)(1e9+7);

    while(!pq.empty()){
        int node = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        
        for(auto it: adj[node]){
            int adjNode = it.first;
            long long edW = it.second;

            if(edW + d < dist[adjNode]){
                dist[adjNode] = edW + d;
                pq.push({edW+d, adjNode});
                ways[adjNode] = ways[node];
            }else if(edW + d == dist[adjNode]){
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }

    return ways[n-1]%mod;
}
// Time Complexity: O(ElogE);
// Space Complexity: O(V + E)

int main()
{
    return 0;
}