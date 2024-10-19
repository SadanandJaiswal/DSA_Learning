#include <bits/stdc++.h>
using namespace std;

int recursion(int i, int sum, vector<int>& arr){
	if(sum==0) return 1;
	if(i==0) return sum==arr[i];

    // if(i==0){
    //     if(sum==0 && arr[0] == 0) return 2;
    //     if(sum==0 || sum==arr[0]) return 1;
    //     return 0;
    // }
	
	int exclude = recursion(i-1, sum, arr);
	int include = 0;
	if(sum>=arr[i]){
		include = recursion(i-1, sum - arr[i], arr);
	}
	
	return include + exclude;
}
// Time Complexity: O(2^n)
// Space Complexity: O(n) -> Auxiliary stack space

int memomizatioon(int i, int sum, vector<vector<int>> &dp, vector<int>& arr){
	if(sum==0) return 1;
	if(i==0) return sum==arr[i];

    // if(i==0){
    //     if(sum==0 && arr[0] == 0) return 2;
    //     if(sum==0 || sum==arr[0]) return 1;
    //     return 0;
    // }
	
	if(dp[i][sum]!=-1) return dp[i][sum];
	
	int exclude = memomizatioon(i-1, sum, dp, arr);
	int include = 0;
	if(sum>=arr[i]){
		include = memomizatioon(i-1, sum - arr[i], dp, arr);
	}
	
	return dp[i][sum] = include + exclude;
}
// Time Complexity: O(n*sum)
// Space Complexity:  O(n*sum) + O(n) -> Auxiliary stack space

int tabulation(int sum, vector<int>& arr){
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(sum+1, 0));

	for(int i=0; i<n; i++){
		dp[i][0] = 1;
	}

	if(sum>=arr[0]) dp[0][arr[0]] = 1;

	for(int i=1; i<n; i++){
		for(int j=0; j<=sum; j++){
			int exclude = dp[i-1][sum];
			int include = 0;
			if(sum>=arr[i]){
				include = dp[i-1][sum-arr[i]];
			}
			
			dp[i][sum] = include + exclude;
		}
	}

	return dp[n-1][sum];
}
// Time Complexity: O(n*sum)
// Space Complexity:  O(n*sum)

int spaceOptimization(int sum, vector<int>& arr){
	vector<int> prev(sum+1, 0), curr(sum+1);
	prev[0] = 1;
	curr[0] = 1;
	prev[arr[0]] = 1;

	int n = arr.size();

	for(int i=1; i<n; i++){
		for(int j=1; j<=sum; j++){
			int exclude = prev[sum];
			int include = 0;
			if(sum>=arr[i]){
				include = prev[sum-arr[i]];
			}

			curr[sum] = include + exclude;
		}
		prev = curr;
	}
	
	return prev[sum];
}
// Time Complexity: O(n*sum)
// Space Complexity:  O(sum)

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	// return recursion(n-1, k, arr);

	vector<vector<int>> dp(n, vector<int>(k+1, -1));
	// return memomizatioon(n-1, k, dp, arr);

	// return tabulation(k, arr);

	return spaceOptimization(k, arr);
}


int main() {
    return 0;
}