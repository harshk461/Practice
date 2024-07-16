#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int i, unordered_map<int, vector<int>> &adj, vector<int> &temp, vector<bool> &vis)
    {
        for (auto nbr : adj[i])
        {
            if (!vis[nbr])
            {
                vis[nbr] = true;
                temp.push_back(nbr);
                dfs(nbr, adj, temp, vis);
            }
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;

        // Reverse the edges of graph
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            vector<bool> vis(n);
            dfs(i, adj, temp, vis);
            // vector<int> t(temp.begin(), temp.end());
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }

        return ans;
    }
};

int main()
{
    return 0;
}