#include<bits/stdc++.h>
using namespace std;

class LargestRectanleHistogram{
    public:
        int bruteForce(vector<int> v){
            int ans =0;
            for(int i=0; i<v.size(); i++){
                int h = v[i];
                if(h>0){
                int count=1;
                    for(int j=i-1; j>=0; j--){
                        if(v[j]>=h && v[j]>0){
                            count++;
                        }else{
                            break;
                        }
                    }
                    for(int j=i+1; j<v.size(); j++){
                        if(v[j]>=h && v[j]>0){
                            count++;
                        }else{
                            break;
                        }
                    }
                ans = max(ans,h*count);
                }
            }
            return ans;
        }
}