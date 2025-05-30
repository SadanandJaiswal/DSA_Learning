#include <bits/stdc++.h>
using namespace std;

/*
    Question: Order should be shipped in the same order as given, need to find the minium capacity to shipp all the items in less or eqal to d days
    Approach:
        - minimum capacity is the max_element, as capacity below that won't be able to ship the element of greater capacity
        - maximum capacity is the sum of all weights as by this, we can shipp all the items in single day
        - answer range will be [max_element, sumofAllElements]
        
        - check valid days
        - start by day one, and add the loads that can be shipped to that day
        - if load exceded shift the load to next day's laod and increment the days by 1

        - BS on answers
        - if daysrequired is less than or equal to the d days then it may be the answer, move to more minimum values
        - else move to higher value as this can't be the answer
*/

int solve(vector<int> &v, int mid){
    int days = 1, load = 0, n = v.size();
    for(int i=0; i<n; i++){
        if(load + v[i] > mid){
            days++;
            load = v[i];    // set the load to current weight and ship all the previous items on previous day 
        }else{
            load += v[i];   // increasee the load
        }
    }

    return days;
}

int shipWithinDays(vector<int>& weights, int days){
    int low = weights[0], high = 0;
    int n = weights.size();

    for(int i=0; i<n; i++){
        low = max(low, weights[i]);
        high += weights[i];
    }

    while(low<=high){
        int mid = low + (high - low)/2;

        int daysreq = solve(weights, mid);

        if(daysreq<=days){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return low;
}

int main() {
    return 0;
}