#include<bits/stdc++.h>
using namespace std;

bool dfs(int start, int currColor, vector<vector<int>> &graph, vector<int> &color) {
    color[start] = currColor;

    for(auto it: graph[start]){
        if(color[it]==-1)
        {
            if(!dfs(it, !currColor, graph, color)) return false;
        }
        else if(color[it]==color[start]) return false;
    }
    
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);

    for (int i = 0; i < n; ++i) {   // for connected components
        if (color[i] == -1) {
            if (!dfs(i, 0, graph, color)) {
                return false;
            }
        }
    }
    return true;
}
// Time Complexity: O(V+2*E)
// Space Complexity: O(V+E)

int main()
{
    
    return 0;
}