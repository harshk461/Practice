#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx, mmx, sse2, sse3, sse4")

static const int disableSync = [](void) noexcept -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

typedef pair<int, int> pi;
class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
        }

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        pq.push({0, 0});

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int node = top.second;
            int wt = top.first;

            for (auto it : adj[node])
            {
                int nbr = it.first;
                int edge_wt = it.second;
                if (dist[nbr] > dist[node] + edge_wt)
                {
                    dist[nbr] = dist[node] + edge_wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        for (int i = 0; i < n; i++)
            if (dist[i] == INT_MAX)
                dist[i] = -1;

        return dist;
    }
};

int main()
{

    return 0;
}