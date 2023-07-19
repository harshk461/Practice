#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int> &qr, int n, vector<int> query)
{
    int cost = query[0];
    int k = query[1];
    vector<bool> isBroken(n, false);
    if (query.size() > 2)
    {
        for (int i = 2; i < query.size(); i++)
        {
            isBroken[query[i] - 1] = true;
        }
    }
    vector<int> new_array;
    for (int i = 0; i < n; i++)
        if (!isBroken[i])
            new_array.push_back(qr[i]);

    int count = 0, sum = 0;
    sort(new_array.begin(), new_array.end());
    for (int i = 0; i < new_array.size(); i++)
    {
        if (sum + new_array[i] <= cost)
        {
            sum = sum + new_array[i];
            count++;
        }
    }
    return count;
}

int maximumToys(vector<int> &arr, int n, vector<vector<int>> &query, int q)
{
    for (auto qr : query)
    {
        cout << solve(arr, n, qr) << ' ';
    }
}

int main()
{
    vector<int> qr = {7, 3, 6, 8, 2, 1, 4, 9, 5, 10};
    int n = 10;
    vector<vector<int>> query = {{10, 2, 2, 5}, {15, 1, 1}, {20, 3, 1, 2, 3}, {100, 0}};
    maximumToys(qr, n, query, 4);
}