#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dirn = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> safety(n, vector<int>(n, INT_MAX));
        queue<vector<int>> q;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j])
                {
                    q.push({i, j});
                    safety[i][j] = 0;
                }

        while (!q.empty())
        {

            auto top = q.front();
            q.pop();

            int x = top[0], y = top[1];
            for (int i = 0; i < 4; i++)
            {
                int newX = x + dirn[i][0];
                int newY = y + dirn[i][1];

                if (newX >= 0 && newX < n && newY >= 0 && newY < n && safety[newX][newY] > safety[x][y] + 1)
                {
                    safety[newX][newY] = safety[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({safety[0][0], {0, 0}});
        vector<vector<int>> vis(n, vector<int>(n, 0));

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int safe = top.first;
            int x = top.second.first;
            int y = top.second.second;

            if (bx == n - 1 && y == n - 1)
                return safe;

            for (int i = 0; i < 4; i++)
            {
                int newX = x + dirn[i][0];
                int newY = y + dirn[i][1];

                if (newX >= 0 && newX < n && newY >= 0 && newY < n && !vis[newX][newY])
                {
                    pq.push({min(safe, safety[newX][newY]), {newX, newY}});
                    vis[newX][newY] = 1;
                }
            }
        }

        return 0;
    }
};

int main()
{

    return 0;
}