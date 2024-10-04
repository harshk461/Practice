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
    void bfs(int n, unordered_map<int, vector<pair<int, int>>> &adj, vector<vector<int>> &distance)
    {

        queue<pair<int, int>> pq;
        pq.push({0, 1});
        pq.push({0, 0});

        // distance to 0 with 0(red) edge
        distance[0][0] = 0;
        // distance to 0 with 1(blue) edge
        distance[1][0] = 0;

        while (!pq.empty())
        {
            int node = pq.front().first;
            int color = pq.front().second;

            pq.pop();

            for (auto [nbr, col] : adj[node])
            {
                if (distance[col][nbr] > distance[color][node] + 1 && col != color)
                {
                    distance[col][nbr] = distance[color][node] + 1;
                    pq.push({nbr, col});
                }
            }
        }
    }

public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        // 1->red
        // 0->blue
        unordered_map<int, vector<pair<int, int>>> adj;
        vector<vector<int>> colors(n, vector<int>(n, -1));
        for (auto it : redEdges)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back({v, 1});
        }

        for (auto it : blueEdges)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back({v, 0});
        }

        vector<vector<int>> distance(2, vector<int>(n, INT_MAX));
        bfs(n, adj, distance);
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int temp = min(distance[0][i], distance[1][i]);
            ans[i] = temp == INT_MAX ? -1 : temp;
        }

        return ans;
    }
};

int main()
{

    return 0;
}