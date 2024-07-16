#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        // possible direction combo are
        // 1 0 -1->i
        // 1 0 -1->j

        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2, 0));

        vector<int> x_dirn = {1, 0, -1};
        vector<int> y_dirn = {1, 0, -1};
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        int x = i + x_dirn[k];
                        int y = j + y_dirn[l];
                        ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[x][y]);
                    }
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