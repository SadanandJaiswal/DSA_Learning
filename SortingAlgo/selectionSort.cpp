// Selection Sort

// step1: select the minimum elm in a array and swap the a[i++], a[j]
// do this for all the remaining array -> i+1 to n-1

#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> v) {
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void selectionSortIterative(vector<int> &v){
    for(int i=0; i<v.size()-1; i++)
    {
        int mini = i;
        for(int j=i; j<v.size(); j++)
        {
            if(v[j]<v[mini]) 
                mini = j;
        }
        swap(v[mini], v[i]);
    }
}

void selectionSortRecursive(int i, vector<int> &v){
    if (i==v.size()-1) return;
    int mini = i;
    for(int j=i; j<v.size() ; j++)
    {
        if(v[j] < v[mini])  
            mini = j;
    }
    swap(v[i], v[mini]);
    selectionSortRecursive(i+1, v);
}

int main(){
    vector<int> arr = {4, 2, 7, 9, 3};
    // selectionSortIterative(arr);
    selectionSortRecursive(0,arr);
    printVec(arr);
}

// Time Complexity
//  Iterative: O(n^2), Recursive: O(n^2)

// Space Complexity
// Iterative: O(1), Recursive: O(n) // n for depth of recursion stack