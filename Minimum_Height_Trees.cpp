#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 0)
            return {};
        if (n == 1)
            return {0};

        vector<int> ans;
        vector<int> indegree(n, 0);
        vector<vector<int>> adj;
        for (auto vec : edges)
        {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
            if (indegree[i] == 1)
                q.push(i);

        while (!q.empty())
        {
            ans.clear();
            for (int i = 0; i < q.size(); i++)
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for (auto nbr : adj[node])
                {
                    indegree[nbr]--;
                    if (indegree[nbr] == 1)
                        q.push(nbr);
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}