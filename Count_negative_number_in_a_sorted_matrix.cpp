#include <bits/stdc++.h>
using namespace std;

// brute force O(N*M)
// int countNegatives(vector<vector<int>> &grid)
// {
//     int count = 0;
//     for (int i = 0; i < grid.size(); i++)
//     {
//         for (int j = 0; j < grid[0].size(); j++)
//         {
//             if (grid[i][j] < 0)
//                 count++;
//         }
//     }
//     return count;
// }

int binarySearch(vector<int> arr, int low, int high, int key)
{
    if (high < low)
        return -1;

    int mid = (low + high) / 2;
    if (key == arr[mid])
        return mid;

    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);

    return binarySearch(arr, low, (mid - 1), key);
}

void ConvertArray(vector<vector<int>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            grid[i][j] = grid[i][j] / abs(grid[i][j]);
        }
    }
}

// Optimized O(M+N)
int countNegatives(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    int i = m - 1;
    int j = 0;
    while (i >= 0 && j < n)
    {
        if (grid[i][j] < 0)
        {
            ans += n - j;
            --i;
        }
        else
        {
            ++j;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    cout << countNegatives(arr);
    return 0;
}