#include <bits/stdc++.h> 
using namespace std;

int recursion(int i, int W, vector<int>& weight, vector<int>& value){
	if(i==0){
		if(weight[0]<=W) return value[0];
		return 0;
	}

	int notTake = recursion(i-1, W, weight, value);
	int take = 0;
	if(weight[i]<=W) take = value[i] + recursion(i-1, W-weight[i], weight, value);

	return max(notTake, take);
}
// Time Complexity: O(2^n)
// Space Complexity: O(n) -> Auxiliary stack space

int memomization(int i, int W, vector<int>& weight, vector<int>& value, vector<vector<int>>& dp){
	if(i==0){
		if(weight[0]<=W) return value[0];
		return 0;
	}

	if(dp[i][W]!=-1) return dp[i][W];

	int notTake = memomization(i-1, W, weight, value, dp);
	int take = 0;
	if (weight[i] <= W) take = value[i] + memomization(i-1, W-weight[i], weight, value, dp);
	
	return dp[i][W] = max(notTake, take);
}
// Time Complexity: O(n*W)
// Space Complexity:  O(n*W) + O(n) -> Auxiliary stack space

int tabulation(int W, vector<int>& weight, vector<int>& value){
	int n = weight.size();
	vector<vector<int>> dp(n, vector<int>(W + 1, 0));

	for(int i=weight[0]; i<=W; i++){
		dp[0][i] = value[0];
	}

	for(int i=1; i<n; i++){
		for(int j=0; j<=W; j++){
			int notTake = dp[i-1][j];
			int take = 0;
			if(weight[i]<=j) take = dp[i-1][j-weight[i]] + value[i];

			dp[i][j] = max(take, notTake);
		}
	}

	return dp[n-1][W];
}
// Time Complexity: O(n*W)
// Space Complexity:  O(n*W)

int spaceOptimization(int W, vector<int>& weight, vector<int>& value){
	int n = weight.size();
	vector<int> prev(W+1, 0), curr(W+1, 0);

	for(int i=weight[0]; i<=W; i++){
		prev[i] = value[0];
	}

	for(int i=1; i<n; i++){
		for(int j=0; j<=W; j++){
			int notTake = prev[j];
			int take = 0;
			if(weight[i]<=j) take = prev[j-weight[i]] + value[i];

			curr[j] = max(take, notTake);
		}
		prev = curr;
	}

	return prev[W];
}
// Time Complexity: O(n*W)
// Space Complexity: O(2n) 

int spaceOptimization2(int W, vector<int>& weight, vector<int>& value){
	int n = weight.size();
	vector<int> prev(W+1, 0);

	// Fill From Right to Left instead of left to right, this will reduce the space by W+1

	for(int i=weight[0]; i<=W; i++){
		prev[i] = value[0];
	}

	for(int i=1; i<n; i++){
		for(int j=W; j>=0; j--){
			int notTake = prev[j];
			int take = 0;
			if(weight[i]<=j) take = prev[j-weight[i]] + value[i];

			prev[j] = max(take, notTake);
		}
		// prev = curr;
	}

	return prev[W];
}
// Time Complexity: O(n*W)
// Space Complexity: O(2n) 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	// return recursion(n-1, maxWeight, weight, value);

	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
	// return memomization(n-1, maxWeight, weight, value, dp);

	// return tabulation(maxWeight, weight, value);

	// return spaceOptimization(maxWeight, weight, value);
	return spaceOptimization2(maxWeight, weight, value);
}