#include <bits/stdc++.h>
using namespace std;

int longestBitonicSubsequence(vector<int>& arr, int n)
{
	vector<int> dp1(n, 1);

	for(int i=0; i<n; i++){
		for(int previ=0; previ<i; previ++){
			if(arr[i]>arr[previ] && 1+dp1[previ]>dp1[i]){
				dp1[i] = 1 + dp1[previ];
			}
		}
	}

	vector<int> dp2(n, 1); 
	int maxi = 0;

	for(int i=n-1; i>=0; i--){
		for(int previ=n-1; previ>i; previ--){
			if(arr[i]>arr[previ] && 1+dp2[previ]>dp2[i]){
				dp2[i] = 1 + dp2[previ];
			}
		}

        // if want to return length of subsequence that is strictly bitonic (means, not just increasing or decresing, both increasing and then decreasing)
        // if(dp1[i]>1 && dp2[i]>1){
        //     maxi = max(maxi, dp1[i]+dp2[i]-1);
        // }

		maxi = max(maxi, dp1[i]+dp2[i]-1);
	}

	// int maxi = 0;

	// for(int i=0; i<n; i++){
	// 	maxi = max(maxi, dp1[i]+dp2[i]-1);
	// }

	return maxi;
}
// Time Complexity: O(n*n*2)
// Space Complexity: O(n*2)

int main() {
    // If we look to the bitonic subsequence we can found that looking from both the end it will look as lis, hence we will use two vector and find lis, lds
    return 0;
}