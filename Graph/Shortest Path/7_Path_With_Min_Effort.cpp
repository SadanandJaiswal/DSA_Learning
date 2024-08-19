#include<bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>& h) { // h : heights
    // get the priority queue
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    int n = h.size();
    int m = h[0].size();

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = 0;
    pq.push({0, {0,0}});

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int dif = it.first;
        int row = it.second.first;
        int col = it.second.second;
        if(row == n-1 && col == m-1) return dif;

        for(int i=0; i<4; i++){
             int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                
            }
        }
    }
}

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