#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dijkstra(int src, vector<vector<pair<int, int>>> &adj, vector<int> &dist, int n, vector<int> &disappear)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src}); // Distance to source is 0
        dist[src] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto &edge : adj[u])
            {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v] && d + weight < disappear[v])
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    }

public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
    {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dist_from_zero(n, 0);
        vector<int> dist(n, INT_MAX);

        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];
            int t = it[2];

            if (u == 0)
                dist_from_zero[v] = t;

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        dijkstra(0, adj, dist, n, disappear);

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (dist[i] <= disappear[i])
                ans[i] = dist[i];
            else
                ans[i] = -1;
        }

        return ans;
    }
};

int main()
{

    return 0;
}