#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int dfs(vector<vector<int>> &graph, int u, vector<int> &indegree, int n, vector<int> &ans)
    {
        if (u < n)
            ans.push_back(u);

        indegree[u] = -1;
        for (auto int v : graph[u])
        {
            if (--indegree[v] == 0)
                dfs(graph, v, indegree, n, ans);
        }
    }

public:
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
    {
        vector<vector<int>> graph(n + m);
        vector<int> indegree(n + m);

        // adj
        for (int i = 0; i < group.size(); i++)
        {
            if (group[i] == -1)
                continue;
            graph[group[i] + n].push_back(i);
            indegree[i]++;
        }

        for (int i = 0; i < beforeItems.size(); ++i)
            for (const int b : beforeItems[i])
            {
                const int u = group[b] == -1 ? b : group[b] + n;
                const int v = group[i] == -1 ? i : group[i] + n;
                if (u == v)
                { // Already in the same group
                    graph[b].push_back(i);
                    ++indegree[i];
                }
                else
                {
                    graph[u].push_back(v);
                    ++indegree[v];
                }
            }

        // topo
        vector<int> ans;
        for (int i = 0; i < n + m; i++)
        {
            if (indegree[i] == 0)
                dfs(graph, i, indegree, n, ans);
        }

        return ans.size() == n ? ans : vector<int>();
    }
};

int main()
{

    return 0;
}