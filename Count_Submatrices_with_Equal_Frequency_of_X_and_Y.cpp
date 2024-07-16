#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<pair<int, int>>> prefix(n, vector<pair<int, int>>(m, {0, 0}));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int xc = 0;
                int yc = 0;

                if (grid[i][j] == 'X')
                    xc++;
                if (grid[i][j] == 'Y')
                    yc++;

                pair<int, int> up = {0, 0};
                if (i - 1 >= 0)
                    up = prefix[i - 1][j];

                pair<int, int> down = {0, 0};
                if (j - 1 >= 0)
                    down = prefix[i][j - 1];

                pair<int, int> overlapping = {0, 0};
                if (i - 1 >= 0 && j - 1 >= 0)
                    overlapping = prefix[i - 1][j - 1];

                xc += up.first + down.first - overlapping.first;
                yc += up.second + down.second - overlapping.second;

                prefix[i][j] = {xc, yc};

                if (xc == yc && xc >= 1)
                    ans++;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}