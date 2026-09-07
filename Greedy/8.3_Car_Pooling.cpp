#include <bits/stdc++.h>
using namespace std;


class SolutionBetter {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> pickup, drop;

        for(auto it : trips){
            int passenger = it[0];
            int from = it[1];
            int to = it[2];

            pickup.push_back({from,passenger});
            drop.push_back({to,passenger});
        }

        sort(pickup.begin(), pickup.end());
        sort(drop.begin(), drop.end());

        int i=0,j=0;
        int cnt = 0;

        while(i<pickup.size()){
            while(j<drop.size() && drop[j].first<=pickup[i].first){
                cnt-=drop[j].second;
                j++;
            }

            cnt+=pickup[i].second;

            if(cnt>capacity){
                return false;
            }
            
            i++;
        }

        return true;
    }
};
// Time Complexity : O(nlogn)
// Space Complexity : O(n) + O(n) for pickup and drop


class SolutionOptimal {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> overlap(1001,0);

        for(auto it: trips){
            overlap[it[1]]+=it[0];
            overlap[it[2]]-=it[0];
        }

        int cnt = 0;

        for(int i=0; i<=1000; i++){
            cnt+=overlap[i];
            if(cnt>capacity){
                return false;
            }
        }

        return true;
    }
};
// Time Complexity : O(n) + O(1000)
// Space Complexity : O(1001)