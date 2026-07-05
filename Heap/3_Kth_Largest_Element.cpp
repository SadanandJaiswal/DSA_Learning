#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int n = arr.size();
    int k = 2;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0; i<n; i++){
        minHeap.push(arr[i]);

        if(minHeap.size()>k){
            minHeap.pop();
        }
    }

    cout << "The " << k << "th largest element is: " << minHeap.top() << endl;
    return 0;
}


int main2(){
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int n = arr.size();
    int k = 2;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0; i<n; i++){
        if(minHeap.size()<k){
            minHeap.push(arr[i]);
        } else if(arr[i]>minHeap.top()){
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    cout << "The " << k << "th largest element is: " << minHeap.top() << endl;
    return 0;
}


// maxheap approach
int main3(){
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int n = arr.size();
    int k = 2;

    priority_queue<int> maxHeap;
    for(int i=0; i<n; i++){
        maxHeap.push(arr[i]);
    }

    for(int i=0; i<k-1; i++){
        maxHeap.pop();
    }

    cout << "The " << k << "th largest element is: " << maxHeap.top() << endl;
    return 0;
}