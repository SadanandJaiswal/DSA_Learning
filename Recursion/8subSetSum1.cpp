#include<bits/stdc++.h>
using namespace std;

// ********************* Approach 1 (brute force) generate all the subset and take sum of each *****************

void solve(int i, int n, int sum, vector<int> &result, vector<int> &nums)
{
	if(i>=n)
	{
		result.push_back(sum);
		return;
	}

	solve(i+1, n, sum+nums[i], result, nums);
    // we don't need extra vector to store as we don't want to print the subset we just need the sum

	solve(i+1, n, sum, result, nums);
}

vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	vector<int> result;
	solve(0,num.size(),0, result,num);	
	sort(result.begin(), result.end());
	return result;
}

int main(){

    return 0;
}