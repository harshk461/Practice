#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int row = 1; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                int mini = INT_MAX;
                for (int k = max(0, col - 1); k < min(n, col + 2); k++)
                    mini = min(mini, matrix[row - 1][k]);
                matrix[row][col] += mini;
            }
        }
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};

int main()
{
    vector<vector<int>> arr = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    Solution s;
    s.minFallingPathSum(arr);
    return 0;
}