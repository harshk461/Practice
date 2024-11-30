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
private:
    vector<pair<int, int>> dirn = {
        {1, 0},  // Down
        {0, 1},  // Right
        {-1, 0}, // Up
        {0, -1}  // Left
    };

public:
    void islandsAndTreasure(vector<vector<int>> &grid)
    {
        int m = grid.size();
        if (m == 0)
            return;
        int n = grid[0].size();

        queue<pair<int, int>> q;

        // Initialize the queue with all treasure chest positions
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0) // If treasure chest
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == -1) // Mark water cells
                {
                    continue;
                }
                else // Mark land cells with INF
                {
                    grid[i][j] = INT_MAX;
                }
            }
        }

        // BFS to fill land cells with the nearest treasure distance
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            int i = top.first;
            int j = top.second;
            int dist = grid[i][j]; // Current distance is 0 for treasure cells

            // Explore all 4 directions
            for (auto it : dirn)
            {
                int x = i + it.first;
                int y = j + it.second;

                // Check boundaries and if the cell is a land cell (INF)
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == INT_MAX)
                {
                    grid[x][y] = dist + 1; // Update the distance
                    q.push({x, y});        // Push the updated cell into the queue
                }
            }
        }
    }
};

int main()
{
    vector<vector<int>> arr = {
        {INT_MAX, -1, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, -1},
        {INT_MAX, -1, INT_MAX, -1},
        {0, -1, INT_MAX, INT_MAX}};

    Solution s;
    s.islandsAndTreasure(arr);
    for (auto it : arr)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}