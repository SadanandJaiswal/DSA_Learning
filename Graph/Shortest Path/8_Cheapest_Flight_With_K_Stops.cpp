#include<bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<pair<int,int>> adj[n];

    for (auto it : flights) {
        adj[it[0]].push_back({it[1], it[2]});
    }

    vector<int> dist(n, INT_MAX);
    queue<pair<int, pair<int,int>>> q;
    // k, node, dist

    dist[src]=0;
    q.push({0,{src,0}});

    while(!q.empty()){
        auto it= q.front();
        q.pop();

        int stop = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if(stop>k){
            continue;
        }

        for(auto it: adj[node]){
            int adjNode = it.first;
            int edW = it.second;

            if(cost + edW < dist[adjNode] && stop<=k){
                dist[adjNode] = cost + edW;
                q.push({stop+1, {adjNode, cost + edW}});
            }
        }

    }
    if(dist[dst]==INT_MAX){
        return -1;
    }
    return dist[dst];
}
// Time Complexiy: O(E) : E is total number of edges

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