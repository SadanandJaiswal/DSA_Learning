// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void combinationSum1(int i, int n, int target, vector<int> a, vector<int> v)
{
    if (i >= n)
    {
        if (target == 0)
        {
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    if (a[i] <= target)
    {
        v.push_back(a[i]);
        combinationSum1(i, n, target - a[i], a, v);
        v.pop_back();
    }
    combinationSum1(i + 1, n, target, a, v);
}

int main()
{
    vector<int> a = {2, 3, 6, 7};
    int target = 7;
    vector<int> v;
    combinationSum1(0, a.size(), target, a, v);

    return 0;
}