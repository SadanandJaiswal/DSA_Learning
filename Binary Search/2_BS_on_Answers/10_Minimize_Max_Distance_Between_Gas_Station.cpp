#include <bits/stdc++.h>
using namespace std;

/*
    Approach 1: Brute Force
        - we will place new gas station one by one, where the section is maximum, thus we can reduce the distance
        - we will consider section length with initial diff
        - newdiff = (arr[i+1]-arr[i])/(placed[i]+1)
        - for each gas station, we will iterate through each elm in array to find the maximum section length
        - for maximum section length increase the placed new gas station 
    
    Approach 2: Better solution (Priority Queue)
        - instead of finding max diff by iterating through all the element
        - we will use priority queue to do the same with log n time

    Approach 3: Bs on answer
        - This approach also reduce the space complexity which waas not possible in priority quee solution
        - answer will lie : 0 to maxdiff
        - as here we will deal with double / long double , here traditional way of binary search will not work
        - instead we will use while(high-low>esp) esp = 1e-6
        - for each mid value we will check are we able to place k station or not, if greater than k means: max distance is not minimisez -> check for higher mid value
            - low = mid
        - if we are able to place less than equal to k means we need to check for lower mid value
            - high = mid
*/

// Approach 1: Brute Force
int minimiseMaxDistance_brute_force(vector<int> &arr, int k){
    int n = arr.size();

    vector<int> placed(n-1, 0);

    for(int gasStation=1; gasStation<=k; gasStation++){
        double maxdiff = -1;
        int maxind = -1;

        for(int i=0; i<n-1; i++){
            int diff = arr[i+1] - arr[i];
            double sectionLenJ = diff/(double)(placed[i]+1);

            if(sectionLenJ>maxdiff){
                maxdiff = sectionLenJ;
                maxind = i;
            }
        }

        placed[maxind]++;
    }

    double ans = -1;
    for(int i=0; i<n-1; i++){
        int diff = arr[i+1] - arr[i];
        double sectionLenJ = diff/(double)(placed[i]+1);
        ans = max(ans, sectionLenJ);
    }

    return ans;
}
// Time Complexity: O(n*k)
// Space Complexity: O(n)

// Approach 2: Priority Queue Solution 
int minimiseMaxDistance(vector<int> &arr, int k){
    int n = arr.size();

    vector<int> placed(n-1, 0);
    priority_queue<pair<double , int>> pq;

    for(int i=0; i<n-1; i++){
        pq.push({(double)(arr[i+1] - arr[i]), i});
    }
    // O(nlogn)

    for(int gasStation=1; gasStation<=k; gasStation++){
        auto top = pq.top();
        pq.pop();

        double sectionLenJ = top.first;
        int maxind = top.second;

        placed[maxind]++;

        double newdiff = (arr[maxind+1] - arr[maxind])/(double)(placed[maxind]+1);

        pq.push({newdiff, maxind});
    }

    return pq.top().first;
}
// Time Complexity: O(n*logn) + O(k*logn)
// Space Complexity: O(n)

// Approach 3: Binary Search on Answers
int helper(vector<int> &v, double mid){
    int cnt =0;
    for(int i=0; i<v.size()-1; i++){
        int diff = v[i+1] - v[i];
        cnt+= (int)(diff/mid);
    }

    return cnt;
}

int minimiseMaxDistance(vector<int> &arr, int k){
    int n = arr.size();

    double low = 0, high =0;

    for(int i=0; i<n-1; i++){
        high = max(high, (double)(arr[i+1]-arr[i]));
    }

    while(high - low > 1e-6){
        double mid = (high  + low)/2.0;

        int gasStationPlaced = helper(arr, mid);

        if(gasStationPlaced>k){
            low = mid;  // need to increase the value of mid to get proper no of gas station
        }else{
            high = mid;
        }
    }

    return high;
}

int main() {
    return 0;
}