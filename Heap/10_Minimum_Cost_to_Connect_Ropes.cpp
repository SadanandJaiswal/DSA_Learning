#include<bits/stdc++.h>
using namespace std;

// When Array is not sorted
class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());  // O(n) time complexity to build the heap
        
        long long sum = 0;
        
        while(pq.size()>1){ // O(n log n) time complexity for the while loop
            int smallest = pq.top();
            pq.pop();   // O(log n) time complexity for pop operation
            
            int secondSmallest = pq.top();
            pq.pop();   // O(log n) time complexity for pop operation
            
            int val = smallest + secondSmallest;
            sum+= val;
            
            pq.push(val);
        }
        
        return sum;
    }
};
// Time Complexity: O(n log n), where n is the number of elements in the input array. The priority queue operations (push and pop) take O(log n) time, and we perform these operations for each element in the array.
// Space Complexity: O(n), where n is the number of elements in the input array. The priority queue stores all the elements of the array, leading to a space complexity of O(n).



// When Array is sorted
class Solution {
  private:
    int getMin(queue<int> &normal, queue<int> &joined){
        if(normal.empty()){
            int val = joined.front();
            joined.pop();
            return val;
        }
        
        if(joined.empty()){
            int val = normal.front();
            normal.pop();
            return val;
        }
        
        if(normal.front()<=joined.front()){
            int val = normal.front();
            normal.pop();
            return val;
        }
        
        int val = joined.front();
        joined.pop();
        return val;
    }
  public:
    int minCost(vector<int>& arr) {
        // code here
        queue<int> normal, joined;
    
        for(int it: arr){
            normal.push(it);
        }    
        
        int sum = 0;
        
        while((normal.size()+joined.size())>1){
            int smallest = getMin(normal, joined);
            int secondSmallest = getMin(normal, joined);
            int val = smallest + secondSmallest;
            
            sum+=val;
            joined.push(val);
        }

        return sum;
    }
};
// Time Complexity: O(n), where n is the number of elements in the input array. The getMin function takes O(1) time, and we perform this operation for each element in the array.
// Space Complexity: O(n), where n is the number of elements in the input array. The two queues store all the elements of the array, leading to a space complexity of O(n).