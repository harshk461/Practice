#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, unordered_map<int, vector<int>> &adj, vector<bool> &vis, vector<bool> &dfs_vis,
             unordered_map<int, int> &parent, int &cycle_start, int &cycle_length)
    {

        vis[node] = true;
        dfs_vis[node] = true;

        for (auto nbr : adj[node])
        {
            if (!vis[nbr])
            {
                parent[nbr] = node;
                if (dfs(nbr, adj, vis, dfs_vis, parent, cycle_start, cycle_length))
                    return true;
            }
            else if (dfs_vis[nbr])
            {
                cycle_start = nbr;
                int curr = node;
                cycle_length = 1;
                while (curr != cycle_start)
                {
                    curr = parent[curr];
                    cycle_length++;
                }

                return true;
            }
        }

        dfs_vis[node] = false;
        return false;
    }

public:
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {

            vector<bool> vis(n);
            vector<bool> dfs_vis(n);
            int cycle_start = -1;
            int cycle_length = 0;

            if (dfs(i, adj, vis, dfs_vis, parent, cycle_start, cycle_length))
                ans = min(ans, cycle_length);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{

    return 0;
}