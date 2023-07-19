#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateSubarrays(const vector<int> &arr)
{
    vector<vector<int>> subarrays;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            vector<int> subarray(arr.begin() + i, arr.begin() + j + 1);
            subarrays.push_back(subarray);
        }
    }

    return subarrays;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans = generateSubarrays(arr);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}