#include <bits/stdc++.h>
using namespace std;

/*
    Question: You are given the array of books which have certain pages, you need to find the minimum of maximum pages we can allocate to students, atleast one book allocate to all student, no book should be unallocated

    Approach 1:
        - we can see answer for this is lie in range : maxi, sum
        - we will iterate and check for which iteration conditions are satisfied
        - when we find the answer break the loop and return the answer

    Approach 1: Bs on answers
        - as we know the range of answer : maxi, sum
        - we will uuse binary search and check for every mid is mid a answer
        - if mid able to allocated more or equal to k student it could be the answer: eleminate the right search space
        - else eliminate the left search space
*/

// Approach 1: Brute Force
int allocate_book_brute_force(vector<int> &v, int k){
    int n = v.size();
    if(n<k) return -1;

    int low = *max_element(v.begin(), v.end());
    int high = accumulate(v.begin(), v.end(), 0);

    for(int mid=low; mid<=high; mid++){
        int cnt = 1, alloc = 0;
        for(int i=0; i<v.size(); i++){
            if(alloc + v[i] >mid){
                cnt++;
                alloc = v[i];
            }else{
                alloc+= v[i];
            }
        }

        if(cnt<=k){
            return mid;;
        }
    }

    return -1;
}
// Time Complexity: O(sum-max-1)*(n)

// Approach 2: Bs on answers
int studentAlloc(vector<int> &v, int k, int mid){
    int cnt = 1, alloc = 0;
    for(int i=0; i<v.size(); i++){
        if(alloc + v[i] >mid){
            cnt++;
            alloc = v[i];
        }else{
            alloc+= v[i];
        }
    }

    return cnt;
}

int allocate_book_optimal(vector<int> &v, int k){
    int n = v.size();
    if(n<k) return -1;

    int low = *max_element(v.begin(), v.end());
    int high = accumulate(v.begin(), v.end(), 0);

    while(low<=high){
        int mid = low + (high - low)/2;

        if(studentAlloc(v, k, mid)>k){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return low;
}
// Time Complexity: O(log(sum-max-1))*(n)

int main() {
    return 0;
}