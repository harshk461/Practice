#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                {
                    ans += 4; // assuming at first that block don't have any neighbour

                    if (r > 0 && grid[r - 1][c] == 1)
                        ans -= 2;
                    if (c > 0 && grid[r][c - 1] == 1)
                        ans -= 2;
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