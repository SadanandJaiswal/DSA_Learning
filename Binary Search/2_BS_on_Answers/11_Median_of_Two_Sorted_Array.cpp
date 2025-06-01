#include <bits/stdc++.h>
using namespace std;

/*
    Question: Two different size sorted array is given, need to find the median of the two sorted array

    Approach 1: Brute Force 
        - take one counter variable, and find the index for the mid elm, that is (n1+n2)/2
        - initially counter will be 0, and ind1 = (n1+n2)/2, ind2 = ind1 -1
        - ind1el = ind2el = -1, ind1 will point to the mid element in merged array and ind2 will point previous elm of ind1 this will be used if length is even
        - do merge of two sorted array and with each iteration increase the counter value
        - when cnt == ind1 or ind2 update the ind1el and ind2el accordingly
        - return the median of the two sorted array

    Approach 2: Binary Search on Answer
        - We can't see any direct use of binary search
        - but we observe if we take certain part of one array and rest to make (n1+n2)/2 then remaing for both on other side then for perfect size we will get the mid element for both the array
        - we observed that if l1>r1 -> take higher value to divide array
        - if l2>r1 then take lower value to divide array
        - else is the answer
        - for this consider the array with less length, to reduce the complexity
*/

// Approach 1: Brute Force
double median_of_two_sorted_array_brute_force(vector<int> &arr1, vector<int> &arr2){
    int i =0, j=0, n1 = arr1.size(), n2 = arr2.size();

    int ind1 = (n1+n2)/2;
    int ind2 = ind1 - 1;

    int ind1el = -1, ind2el = -1;

    int cnt = 0;

    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            if(cnt==ind1) ind1el = arr1[i];
            if(cnt==ind2) ind2el = arr1[i];
            i++;
        }else{
            if(cnt==ind1) ind1el = arr2[j];
            if(cnt==ind2) ind2el = arr2[j];
            j++;
        }
        cnt++;
    }

    while(i<n1){
        if(cnt==ind1) ind1el = arr1[i];
        if(cnt==ind2) ind2el = arr1[i];
        i++;
        cnt++;
    }

    while(j<n2){
        if(cnt==ind1) ind1el = arr2[j];
        if(cnt==ind2) ind2el = arr2[j];
        j++;
        cnt++;
    }

    if((n1+n2)%2==0){
        return (double)(ind1el + ind2el)/2.0;
    }
    return ind1el;
}
// Time Complexity: O(n+m)
// Space Complexity: O(1)

double median_of_two_sorted_array_binary_search_solution(vector<int> &arr1, vector<int> &arr2){
    int n1 = arr1.size(), n2 = arr2.size();

    if(n1>n2) return median_of_two_sorted_array_binary_search_solution(arr2, arr1);

    int n = n1 + n2;

    int left = (n+1)/2;

    int low = 0, high = n1;

    while(low<=high){
        int mid1 = low + (high - low)/2;
        int mid2 = left - mid1;

        int l1 = INT32_MIN, l2 = INT32_MIN;
        int r1 = INT32_MIN, r2 = INT32_MIN;

        if(mid1>0) l1 = arr1[mid1-1];
        if(mid1<n1) r1 = arr1[mid1];

        if(mid2>0) l2 = arr2[mid2-1];
        if(mid2<n2) r2 = arr2[mid2];

        if(l1>=r2 && l2>=r1){
            if(n%2==1){
                return max(l1, l2);
            }else{
                return (double)((max(l1,l2) + min(r1, r2))/2.0);
            }
        }
        else if(l1>r2){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}
// Time Complexity: O(log(min(n,m)))

int main() {
    return 0;
}