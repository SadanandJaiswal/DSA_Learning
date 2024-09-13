#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer = 0;

    void dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj, vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges){
        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for(auto it: adj[node]){
            if(it==parent) continue;

            if(vis[it]){    // visited
                low[node] = min(low[node], low[it]);
            }else{  // not visited
                dfs(it, node, vis, adj, tin, low, bridges);

                //  once dfs is completed
                low[node] = min(low[node], low[it]);

                // can node -- it be bridge
                if(tin[node]<low[it]){
                    bridges.push_back({node, it});
                }
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n);
        vector<int> low(n);
        vector<vector<int>> bridges;

        // also require a timer initially to zero
        dfs(0, -1, vis, adj, tin, low, bridges);

        return bridges;
    }
};
// Time Complexity: O(V+2*E)

int main() {
    return 0;
}