#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &vis, vector<bool> &present)
    {
        if (vis[node])
            return false;
        if (present[node])
            return true;

        vis[node] = true;
        present[node] = true;

        for (auto nbr : adj[node])
        {
            if (dfs(nbr, adj, vis, present))
                return true;
        }

        // backtrack
        present[node] = false;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<bool> vis(n), present(n);

        for (int i = 0; i < n; i++)
            adj[i] = graph[i];

        for (int i = 0; i < n; i++)
            dfs(i, adj, vis, present);

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (!present[i])
                ans.push_back(i);

        return ans;
    }
};

int main()
{

    return 0;
}