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
    int n, m;
    vector<vector<int>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int shortestPathAllKeys(vector<string> &grid)
    {
        n = grid.size();
        m = grid[0].size();

        vector<vector<vector<bool>>> vis(grid.size(), vector<vector<bool>>(grid[0].size(), vector<bool>(64, false)));

        int keys = 0;
        int start_row, start_col;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].length(); j++)
            {
                if (grid[i][j] == '@')
                {
                    start_row = i;
                    start_col = j;
                }
                else if (grid[i][j] >= 'a' and grid[i][j] <= 'z')
                { // check
                    keys++;
                }
            }
        }

        queue<vector<int>> q;
        q.push({start_row, start_col, 0, 0});
        vis[start_row][start_col][0] = true;

        while (q.size() > 0)
        {
            int row = q.front()[0];
            int col = q.front()[1];
            int mask = q.front()[2];
            int steps = q.front()[3];

            q.pop();

            int req_ans = pow(2, keys);
            if (mask == (req_ans - 1))
                return steps;

            for (int i = 0; i < dir.size(); i++)
            {
                int r = dir[i][0];
                int c = dir[i][1];
                if (isValid(row + r, col + c) == true)
                {
                    if (grid[row + r][col + c] == '.')
                    {
                        if (vis[row + r][col + c][mask] == false)
                        {
                            vis[row + r][col + c][mask] = true;
                            q.push({row + r, col + c, mask, steps + 1});
                        }
                    }
                    else if (grid[row + r][col + c] == '#')
                    {
                        continue;
                    }
                    else if (grid[row + r][col + c] == '@')
                    {
                        if (vis[row + r][col + c][mask] == false)
                        {
                            vis[row + r][col + c][mask] = true;
                            q.push({row + r, col + c, mask, steps + 1});
                        }
                    }
                    else if (grid[row + r][col + c] >= 'a' and grid[row + r][col + c] <= 'z')
                    {
                        if (vis[row + r][col + c][mask] == false)
                        {
                            vis[row + r][col + c][mask] = true;
                            int updated_mask = mask | (1 << (grid[row + r][col + c] - 'a'));
                            q.push({row + r, col + c, updated_mask, steps + 1});
                        }
                    }
                    else
                    {
                        if (vis[row + r][col + c][mask] == false)
                        {
                            char lock = (grid[row + r][col + c]);
                            char key = tolower(lock);
                            int found = (mask & (1 << (key - 'a')));
                            if (found > 0)
                                q.push({row + r, col + c, mask, steps + 1});

                            vis[row + r][col + c][mask] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
    bool isValid(int row, int col)
    {
        if (row >= 0 and row < n and col >= 0 and col < m)
            return true;
        return false;
    }
};
int main()
{

    return 0;
}