#include<bits/stdc++.h>
using namespace std;

// Condition is current child should have more candies than neighbor if rating is higher than neighbor. So we can use greedy approach to solve this problem. We can traverse the ratings array from left to right and then from right to left and assign candies accordingly.
// Condition : atleast 1 && if rating[i] > rating[i-1] then candies[i] = candies[i-1]+1 && if rating[i] > rating[i+1] then candies[i] = max(candies[i], candies[i+1]+1)
class SolutionBruteForce {
public:
    int candy(vector<int>& ratings) {
        vector<int> ans(ratings.size(), 1);

        for(int i=1; i<ratings.size(); i++){
            if(ratings[i]>ratings[i-1]){
                ans[i] = ans[i-1]+1;
            }
        }

        for(int i=ratings.size()-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                ans[i] = max(ans[i], ans[i+1]+1);
            }
        }

        return accumulate(ans.begin(), ans.end(), 0);
    }
};
// Time Complexity : O(n) + O(n) + O(n) = O(n)
// Space Complexity : O(n) for ans vector



class SolutionOptimal {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n==0) return 0;

        int sum = 1;
        int i = 1;

        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }

            int peak = 1;

            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }


            int down = 1;

            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                down++;
                i++;
            }

            if(down>peak){
                sum+=down-peak;
            }
        }

        return sum;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(1)


