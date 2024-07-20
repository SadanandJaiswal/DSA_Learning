#include<bits/stdc++.h>
using namespace std;

bool bfs(int start, vector<vector<int>> &graph, vector<int> &color) {
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty()) {    
        int t = q.front();
        int c = color[t];
        q.pop();

        for(auto x:graph[t]){   // all the adjacent of the node
            if(color[x]==-1){
                color[x]=!c;
                q.push(x);
            }
            else if(color[x]==c){   // if the adjacent is alredy colored and with the same color
                return false;
            }
        }
    }
    return true;
}
 bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);

    for (int i = 0; i < n; ++i) {   // for connected components
        if (color[i] == -1) {
            if (!bfs(i, graph, color)) {
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