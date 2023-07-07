#include <bits/stdc++.h>
using namespace std;

int equalPairs(vector<vector<int>> &grid)
{
    int ans = 0;
    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[0].size(); col++)
        {
            int k = 0;
            for (; k < n; ++k)
            {
                if (grid[i][k] != grid[k][j])
                    break;
            }
            if (k == n)
                ans++;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    equalPairs(arr);
    return 0;
}