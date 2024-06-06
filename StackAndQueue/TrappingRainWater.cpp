// Trapping Rain Water 

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int bruteForce(vector<int> v){
            int n = v.size();
            int ans =0;
            for(int i=0; i<n; i++){
                int mini = 0;
                int maxi = 0;
                for(int j=0; j<n; j++){
                    if(j<i){
                        mini = max(mini,v[j]);
                    }else if(j > i) {
                        maxi = max(maxi,v[j]);
                    }
                }
                if(min(mini,maxi) - v[i] >=0){
                    ans += min(mini,maxi) - v[i];
                }
            }
            return ans;
        }

        int betterApproach(vector<int> v)
        {
            int n = v.size();
            if(n<3) return 0;

            vector<int> prefixMax(n);
            prefixMax[0] = v[0];
            vector<int> suffixMax(n);
            suffixMax[n - 1] = v[n - 1];

            int ans = 0;

            for(int i=1; i<n; i++){
                prefixMax.push_back(max(prefixMax[i-1], v[i]));
            }

            for(int j=n-2; j>=0; j--){
                suffixMax.push_back(max(suffixMax[j+1], v[j]));
            }

            for(int i=0; i<n; i++){
                int val = min(prefixMax[i], suffixMax[i]) - v[i];
                if(val>0){
                    ans+=val;
                }
            }

            return ans;
        }

        int moreBetterApproachUsingStack(vector<int> v){
            int n = v.size();
            if(n<3) return 0;

            stack<int> s;
            int res = 0;
        }

        int optimal2PointerApproach(vector<int> v){
            int n = v.size();
            if(n<3) return 0;
            int ans = 0;
            int l = 0, r = n-1;
            int leftmax =0, rightmax  =0 ;
            while(l < r){
                if(v[l] < v[r]){
                    if(v[l] >= leftmax){
                        leftmax = v[l];
                    }
                    else{
                        ans += leftmax - v[l];
                    }
                    l++;
                }
                else{
                    if(v[r] >= rightmax){
                        rightmax = v[r];
                    }
                    else{
                        ans += rightmax - v[r];
                    }
                    r--;
                }
            }

            return ans;
        }
};