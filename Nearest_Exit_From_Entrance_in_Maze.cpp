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
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1},
    };

public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        set<pair<int, int>> exits;
        int m = maze.size();
        int n = maze[0].size();

        for (int i = 0; i < n; i++)
        {
            if (maze[0][i] == '.')
                exits.insert({0, i});

            if (maze[m - 1][i] == '.')
                exits.insert({m - 1, i});
        }

        for (int i = 0; i < m; i++)
        {
            if (maze[i][0] == '.')
                exits.insert({i, 0});

            if (maze[i][n - 1] == '.')
                exits.insert({i, n - 1});
        }

        if (exits.find({entrance[0], entrance[1]}) != exits.end())
            exits.erase({entrance[0], entrance[1]});

        // for (auto it : exits)
        //     cout << it << " ";
        int ans = INT_MAX;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {entrance[0], entrance[1]}});
        vector<vector<bool>> vis(m, vector<bool>(n));
        vis[entrance[0]][entrance[1]] = true;
        while (!q.empty())
        {
            auto top = q.front();
            int cost = top.first;

            int i = top.second.first;
            int j = top.second.second;
            // cout<<i<<" "<<j<<endl;
            q.pop();

            if (exits.count({i, j}))
                ans = min(ans, cost);

            for (auto it : dirn)
            {
                int x = i + it.first;
                int y = j + it.second;

                if (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.' && !vis[x][y])
                {
                    vis[x][y] = true;
                    q.push({cost + 1, {x, y}});
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{

    return 0;
}