#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int dfs(int node, vector<int> &time, unordered_map<int, vector<int>> &graph, vector<int> &dp)
    {
        if (dp[node] != -1)
            return dp[node];

        if (graph[node].size() == 0)
            return time[node];
        int ans = 0;
        for (auto nbr : graph[node])
            ans = max(ans, dfs(nbr, time, graph, dp));

        return dp[node] = time[node] + ans;
    }

public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        unordered_map<int, vector<int>> graph;
        vector<int> dp(n, vector<int>(n, -1));
        for (auto it : relations)
        {
            int u = it[0] - 1;
            int v = it[1] - 1;
            graph[u].push_back(v);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, dfs(i, time, graph, dp));
        return ans;
    }
};

int main()
{

    return 0;
}