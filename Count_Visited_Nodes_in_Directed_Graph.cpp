#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int dfs(int node, unordered_map<int, int> &adj, unordered_map<int, bool> &vis)
    {
        vis[node] = 1;
        int ans = 1;

        int nbr = adj[node];
        if (!vis[nbr])
            ans += 1 + dfs(nbr, adj, vis);

        return ans;
    }

public:
    vector<int> countVisitedNodes(vector<int> &edges)
    {
        int n = edges.size();
        unordered_map<int, int> adj;
        for (int i = 0; i < n; i++)
        {
            adj[i] = edges[i];
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            unordered_map<int, bool> vis;
            ans[i] = dfs(i, adj, vis);
        }

        return ans;
    }
};

int main()
{

    return 0;
}