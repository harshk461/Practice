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
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        vector<vector<int>> mat(m, vector<int>(n, 0));
        // 0 = unguarded, -1 = wall, 1 = guard, 2 = covered

        // Mark walls and guards
        for (auto &wall : walls)
            mat[wall[0]][wall[1]] = -1;

        for (auto &guard : guards)
            mat[guard[0]][guard[1]] = 1;

        // Mark coverage for each guard
        for (auto &guard : guards)
        {
            int x = guard[0], y = guard[1];

            // Up
            for (int i = x - 1; i >= 0; i--)
            {
                if (mat[i][y] == -1 || mat[i][y] == 1)
                    break;
                if (mat[i][y] == 0)
                    mat[i][y] = 2;
            }
            // Down
            for (int i = x + 1; i < m; i++)
            {
                if (mat[i][y] == -1 || mat[i][y] == 1)
                    break;
                if (mat[i][y] == 0)
                    mat[i][y] = 2;
            }
            // Left
            for (int i = y - 1; i >= 0; i--)
            {
                if (mat[x][i] == -1 || mat[x][i] == 1)
                    break;
                if (mat[x][i] == 0)
                    mat[x][i] = 2;
            }
            // Right
            for (int i = y + 1; i < n; i++)
            {
                if (mat[x][i] == -1 || mat[x][i] == 1)
                    break;
                if (mat[x][i] == 0)
                    mat[x][i] = 2;
            }
        }

        // Count unguarded cells
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                    count++;
            }
        }

        return count;
    }
};

int main()
{

    return 0;
}