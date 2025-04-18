#include <bits/stdc++.h>
using namespace std;

bool check(string &s1, string &s2){
    if(s1.size()!=s2.size()+1) return false;

    int first = 0;
    int second = 0;

    while(first<s1.size()){
        if(second<s2.size() && s1[first]==s2[second]){
            first++;
            second++;
        }else{
            first++;
        }
    }

    if(first==s1.size() && second==s2.size()) return true;
    return false;
}

static bool comp(string &s1, string &s2){
    return s1.size() < s2.size();
}

int longestStrChain(vector<string>& words) {
    int n = words.size();

    // we will sort the words array, as our approach works as subsequence
    // sort accorrding to length (comp)
    sort(words.begin(), words.end(), comp);

    vector<int> dp(n, 1);

    int maxi = 1;
    int lastindex = 0;
    for(int i=0; i<n; i++){
        for(int previ=0; previ<i; previ++){
            if(check(words[i], words[previ]) && 1+dp[previ]>dp[i]){
                dp[i] = 1 + dp[previ];
            }
        }
        if(dp[i]>maxi){
            maxi = dp[i];
        }
    }

    return maxi;
}
// Time Complexity: O(n*n*32) + O(n*log(n))
// Space Complexity: O(n)

int main() {
    // We will sort the words array according to the length of the elm, as we are applying LIS approach, we will miss some elm if we will not sort the array
    return 0;
}