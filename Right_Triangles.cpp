#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
public:
    long long numberOfRightTriangles(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row_sum(n, 0);
        vector<int> col_sum(m, 0);

        // row sum
        for (int i = 0; i < n; i++)
            row_sum[i] = accumulate(grid[i].begin(), grid[i].end(), 0);

        // col sum
        for (int i = 0; i < m; i++)
        {
            long long sum = 0;
            for (int j = 0; j < n; j++)
                sum += grid[j][i];

            col_sum[i] = sum;
        }

        // for (auto it : row_sum)
        //     cout << it << " ";
        //     cout<<endl;
        // for (auto it : col_sum)
        //     cout << it << " ";

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] && row_sum[i] >= 1 && col_sum[j] >= 1)
                {
                    // don't include the current element at [i][j] thats why we are subtracting row_sum[i]-1 and col_sum[j]-1;
                    ans += (row_sum[i] - 1) * (col_sum[j] - 1);
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}