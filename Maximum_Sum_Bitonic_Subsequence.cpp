#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n)
{
    int maxSum = -1;
    vector<int> inc(n);
    vector<int> dec(n);

    for (int i = 0; i < n; i++)
    {
        inc[i] = arr[i];
        dec[i] = arr[i];
    }

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && inc[i] < inc[j] + arr[i])
                inc[i] = inc[j] + arr[i];

    for (int i = n - 2; i >= 0; i--)
        for (int j = n - 1; j > i; j--)
            if (arr[i] > arr[j] && dec[i] < dec[j] + arr[i])
                dec[i] = dec[j] + arr[i];

    for (int i = 0; i < n; i++)
        maxSum = max(maxSum + inc[i] + dec[i] - arr[i]);

    return maxSum;
}

int maxSumBS(int arr[], int n)
{
    return solve(arr, n);
}

int main()
{

    return 0;
}