#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> birth, death;

        for(auto it : logs){
            birth.push_back(it[0]);
            death.push_back(it[1]);
        }

        sort(birth.begin(), birth.end());
        sort(death.begin(), death.end());

        int i=0,j=0;
        int maxi =0;
        int ans = -1;
        int cnt = 0;

        while(i<birth.size() && j<death.size()){
            if(birth[i]<death[j]){
                cnt++;

                if(cnt>maxi){
                    maxi = cnt;
                    ans = birth[i];
                }
                i++;
            }else{
                cnt--;
                j++;
            }
        }

        return ans;
    }
};
// Time Complexity : O(nlogn)
// Space Complexity : O(n)


class SolutionOptimal {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // 1950 to 2050
        vector<int> overlap(101,0);

        for(auto it: logs){
            overlap[it[0]-1950]++;
            overlap[it[1]-1950]--;
        }

        int index = 0;

        int maxi = overlap[0];

        for(int i=1; i<=100; i++){
            overlap[i] = overlap[i] + overlap[i-1];
            if(overlap[i]>maxi){
                maxi = overlap[i];
                index = i;
            }
        }

        return index+1950;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(1)