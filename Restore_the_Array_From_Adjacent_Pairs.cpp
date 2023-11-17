#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    unordered_map<int, vector<int>> adj;
    void dfs(int node, int prev, vector<int> &ans)
    {
        ans.push_back(node);
        for (auto nbr : adj[node])
        {
            if (nbr != prev)
                dfs(nbr, node, ans);
        }
    }

public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        for (auto it : adjacentPairs)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int root = 0;
        for (auto it : adj)
        {
            if (it.second.size() == 1)
            {
                root = it.first;
                break;
            }
        }

        vector<int> ans;
        dfs(root, INT_MAX, ans);
        return ans;
    }
};

int main()
{

    return 0;
}