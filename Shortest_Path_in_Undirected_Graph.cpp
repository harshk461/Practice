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
    vector<int> shortestPath(vector<vector<int>> &edges, int n, int m, int src)
    {
        unordered_map<int, vector<int>> adj;
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(n, INT_MAX);
        // node,dist
        queue<pair<int, int>> q;
        dist[src] = 0;
        q.push({src, 0});

        vector<bool> vis(n);
        vis[src] = 1;

        while (!q.empty())
        {
            auto top = q.front();
            q.pop();

            int node = top.first;
            int wt = top.second;

            for (auto nbr : adj[node])
            {
                if (!vis[nbr] && dist[nbr] > wt + 1)
                {
                    dist[nbr] = 1 + wt;
                    q.push({nbr, dist[nbr]});
                    vis[nbr] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
            if (dist[i] == INT_MAX)
                dist[i] = -1;

        return dist;
    }
};

int main()
{

    return 0;
}