#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1]>b[1];
        });

        int n = boxTypes.size();

        int ans = 0;

        for(int i=0; i<n && truckSize>0; i++){
            int quantity = min(boxTypes[i][0], truckSize);

            ans+=quantity*boxTypes[i][1];
            truckSize-=quantity;
        }

        return ans;
    }
};