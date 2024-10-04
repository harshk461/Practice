#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, unordered_map<int, int> &adj, vector<bool> &vis, vector<bool> &dfs_vis,
             unordered_map<int, int> &parent, int &cycle_start, int &cycle_length)
    {
        vis[node] = true;
        dfs_vis[node] = true;

        if (adj.find(node) == adj.end()) // Ensure the node has a neighbor
            return false;

        int nbr = adj[node];
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

        dfs_vis[node] = false;
        return false;
    }

    int brute(vector<int> &edges)
    {
        int n = edges.size();

        unordered_map<int, int> adj;
        for (int i = 0; i < edges.size(); i++)
            if (edges[i] != -1)
                adj[i] = edges[i];

        int ans = INT_MIN;
        // detect length of cycle from every node
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[i] == -1)
                continue;

            vector<bool> vis(n, false);
            vector<bool> dfs_vis(n, false);
            unordered_map<int, int> parent;

            int cycle_start = -1;
            int cycle_length = 0;

            if (dfs(i, adj, vis, dfs_vis, parent, cycle_start, cycle_length))
                ans = max(ans, cycle_length);
        }

        return ans == INT_MIN ? -1 : ans;
    }

    int optimised(vector<int> &edges)
    {
        unordered_map<int, int> adj;
        int n = edges.size();
        for (int i = 0; i < n; i++)
            adj[i] = edges[i];

        vector<int> vis(n, 0);
        vector<bool> dfs_vis(n);

        int ans = -1;

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                int temp = optimisiedUtil(i, 0, adj, vis, dfs_vis);
                if (temp != 0)
                    ans = max(ans, temp);
            }
        }

        return ans;
    }

    int optimisiedUtil(int node, int count, unordered_map<int, int> &adj, vector<int> &vis, vector<bool> &dfs_vis)
    {

        if (dfs_vis[node])
            return -1;

        if (adj[node] == -1)
        {
            dfs_vis[node] = true;
            return -1;
        }

        if (vis[node] != 0)
            return count - vis[node] + 1;

        vis[node] = count + 1;
        int ans = optimisiedUtil(adj[node], count + 1, adj, vis, dfs_vis);
        vis[node] = 0;
        dfs_vis[node] = 1;

        return ans;
    }

public:
    int longestCycle(vector<int> &edges)
    {
        return optimised(edges);
    }
};

int main()
{

    return 0;
}