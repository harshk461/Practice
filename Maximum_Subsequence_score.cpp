#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> arr, int s, int e)
{
    int min_val = INT_MAX;
    for (int i = s; i <= e; i++)
    {
        min_val = min(min_val, arr[i]);
    }
    return min_val;
}

long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
{
    int window
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    cout << findMin(arr, 2, 5);
    return 0;
}