#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
private:
    vector<int> dijkstra(int src, int n, unordered_map<int, vector<pi>> &adj)
    {
        vector<int> distance(n, INT_MAX);
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, src});
        distance[src] = 0;

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int node = top.second;
            int wt = top.first;

            if (distance[node] < wt)
                continue;

            for (auto &nbr : adj[node])
            {
                if (distance[nbr.first] > distance[node] + nbr.second)
                {
                    distance[nbr.first] = distance[node] + nbr.second;
                    pq.push({distance[nbr.first], nbr.first});
                }
            }
        }

        return distance;
    }

    int dfs(int node, int n, unordered_map<int, vector<int>> &adj2, vector<int> &dp)
    {
        if (node == n - 1)
            return 1;

        if (dp[node] != -1)
            return dp[node];

        int count = 0;
        const int MOD = 1e9 + 7;
        for (int nbr : adj2[node])
        {
            count = (count + dfs(nbr, n, adj2, dp)) % MOD;
        }

        return dp[node] = count;
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<pi>> adj;
        for (auto &it : edges)
        {
            int u = it[0] - 1;
            int v = it[1] - 1;
            int w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> distance = dijkstra(n - 1, n, adj);

        unordered_map<int, vector<int>> adj2;
        for (auto &it : edges)
        {
            int u = it[0] - 1;
            int v = it[1] - 1;
            if (distance[u] > distance[v])
                adj2[u].push_back(v);
            else if (distance[v] > distance[u])
                adj2[v].push_back(u);
        }

        vector<int> dp(n, -1);
        return dfs(0, n, adj2, dp);
    }
};

int main()
{

    return 0;
}