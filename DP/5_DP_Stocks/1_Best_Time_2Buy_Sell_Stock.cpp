#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int mini = prices[0];
    int ans = 0;

    for(int i=1; i<prices.size(); i++){
        ans = max(ans, prices[i] - mini);
        mini = min(mini, prices[i]);
    }

    return ans;
}
// Time Complexity: O(n)
// Space Complexity: O(1)

int main() {
    // Single Buy and Sell
    return 0;
}