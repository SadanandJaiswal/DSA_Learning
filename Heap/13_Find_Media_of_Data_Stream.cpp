#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach : Using Sorting
class MedianFinderBrute {
private:
    vector<int> arr;
public:
    void addNum(int num) {
        // Brute force : O(nlogn)
        arr.push_back(num);
        sort(arr.begin(), arr.end());
    }
    
    double findMedian() {
        int n = arr.size();

        if(n%2==1){
            return arr[n/2];
        }
        return (arr[n/2]+arr[(n/2)-1])/2.0;
    }
};

// Better Approach : Binary Search + Insertion Sort
class MedianFinderBetter {
private:
    vector<int> arr;
public:
    void addNum(int num) {
        // Better approach : O(n)
        auto it = lower_bound(arr.begin(), arr.end(), num);
        int ind = it - arr.begin();
        arr.insert(it, num);    // O(n) shift all elm 

        // swap(arr[ind],num);
        // for(int i=ind+1; i<arr.size(); i++){
        //     swap(arr[i], num);
        // }
        // arr.push_back(num);
    }
    
    double findMedian() {
        int n = arr.size();

        if(n%2==1){
            return arr[n/2];
        }
        return (arr[n/2]+arr[(n/2)-1])/2.0;
    }
};


// Optimal Approach : Using Two Heaps
class MedianFinderOptimal {
private:
    priority_queue<int> maxHeap; // left side
    priority_queue<int, vector<int>, greater<int>> minHeap; // right side
public:
    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top()>=num){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }

        if(maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size()){
            return (maxHeap.top()+minHeap.top())/2.0;
        }
        return maxHeap.top();
    }
};
// Time Complexity : O(logn) for addNum() and O(1) for findMedian()
// Space Complexity : O(n) where n is the number of elements in the data stream