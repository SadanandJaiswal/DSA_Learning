#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> v) {
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void bubbleSortRecursive(int i, vector<int> &v, bool didSwap)
{
    if(i==v.size()-1 || !didSwap) return;
    for(int j=0; j<v.size()-i-1; j++)
        {
            if(v[j+1]<v[j])
            {
                swap(v[j],v[j+1]);
                didSwap = true;
            }
        }
    bubbleSortRecursive(i+1,v,didSwap);
}


void bubbleSortIterative(vector<int> &v){
    for(int i=0; i<v.size()-1; i++)
    {
        bool didSwap = false;
        for(int j=0; j<v.size()-i-1; j++)
        {
            if(v[j+1]<v[j])
            {
                swap(v[j],v[j+1]);
                didSwap = true;
            }
        }
        if(didSwap==false)
            break;
    }
}

int main()
{
    vector<int> v = {4,2,7,3,9};
    bubbleSortIterative(v);
    // bubbleSortRecursive(0,v,true);
    printVec(v);   
}

// Time Complexity:
// average/worst case: O(n^2),  best case(array is sorted): O(n);

// space Complexity: O(n) (for auxiliary array).