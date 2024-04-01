#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> v) {
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void merge(vector<int> &v, int low, int mid, int high){
    vector<int> temp;
    int i = low, j=mid+1;

    while(i<=mid && j <=high){
        if(v[i] < v[j]){
            temp.push_back(v[i]);
            i++;
        }
        else{
            temp.push_back(v[j]);
            j++;
        }
    }

    while(i<=mid)
    {
        temp.push_back(v[i]);
        i++;
    }

    while (j<=high)
    {
        temp.push_back(v[j]);
        j++;
    }

    // v = temp;    // this wont work   // because  v is passed by reference and temp is a copy of it, so any changes made to v will reflect in the original array but not vice vers
    for(int k = low; k <= high; k++) {
        v[k] = temp[k - low];
    }
}

void mergeSort(int low, int high, vector<int> &v)
{
    if(low>=high)
    {
        return;
    }

    int mid = (low + high)/2;

    mergeSort(low, mid, v);
    mergeSort(mid+1, high, v);

    merge(v, low, mid, high);
}

int main()
{
    vector<int> v = {4,2,7,3,9};
    mergeSort(0, v.size()-1, v);
    printVec(v);   
}