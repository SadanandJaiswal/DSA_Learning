#include <bits/stdc++.h>
using namespace std;

// using priority queue / for queue just put q instead of pq
vector<int> dijkstraUsingPriorityQueue(int V, vector<vector<int>> adj[], int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // dist,node
    vector<int> dist(V, INT_MAX);

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int newW = it[1];
            int adjNode = it[0];

            if (d + newW < dist[adjNode])
            {
                dist[adjNode] = d + newW;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

// using set : unique and smallest at top
vector <int> dijkstraUsingSet(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>> st;
        vector<int> dist(V, INT_MAX);
        dist[S]=0;
        st.insert({0,S});
        
        while(!st.empty()){
            auto it = *st.begin(); // begin() will return the address of smallest node
            int d = it.first;
            int node = it.second;
            st.erase(it);
            
            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgeW = it[1];
                
                if(d+edgeW < dist[adjNode]){
                    // if dist not INT_MAX means already in set hence erase from set as we get smaller then that
                    if(dist[adjNode] != INT_MAX){
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = d + edgeW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }

// Time Complexity: 

int main()
{
    return 0;
}