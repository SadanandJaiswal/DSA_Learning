#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> v) {
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void insertionSortRecursive(int i, vector<int> &v)
{
    if(i==v.size()) return;
    int j = i;
    while(j>0 && v[j-1]>v[j])
    {
        swap(v[j], v[j-1]);
        j--;
    }
    insertionSortRecursive(i+1, v);
}

void insertionSortIterative(vector<int> &v)
{
    for(int i=0; i<v.size(); i++)
    {
        int j = i;
        while(j>0 && v[j-1]>v[j])
        {
            swap(v[j-1],v[j]);
            j--;
        }
        
    }
}

int main()
{
    vector<int> v = {2,3,4,7,9};
    // insertionSortIterative(v);
    insertionSortRecursive(0,v);
    printVec(v);
}

// Time Complexity:
// worst/average: O(n^2), best case(sorted): O(n)

// space complexity:
// iterative: O(1), Recursive: O(n);