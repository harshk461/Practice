#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int dijkstra(int n, int src, int dest, unordered_map<int, vector<pair<int, int>>> &adj)
    {
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty())
        {
            auto top = pq.top();
            int wt = top.first;
            int node = top.second;

            pq.pop();

            for (auto nbr : adj[node])
            {
                int nb = nbr.first;
                int weight = nbr.second;

                if (dist[node] + weight < dist[nb])
                {
                    dist[nb] = dist[node] + weight;
                    pq.push({dist[nb], nb});
                }
            }
        }

        return dist[dest];
    }

public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
    {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if (w == -1)
                continue;

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int initial_path_cost = dijkstra(n, source, destination, adj);
        if (initial_path_cost < target)
            return {};

        bool isEqual = (initial_path_cost == target);
        for (auto &it : edges)
        {
            if (it[2] != -1)
                continue;

            int u = it[0];
            int v = it[1];
            int w = it[2];

            it[2] = isEqual ? 2e9 : 1;
            adj[u].push_back({v, it[2]});
            adj[v].push_back({u, it[2]});

            if (!isEqual)
            {
                int new_path = dijkstra(n, source, destination, adj);
                if (new_path <= target)
                {
                    isEqual = true;
                    it[2] += target - new_path;
                }
            }
        }

        if (isEqual)
            return edges;
        return {};
    }
};

int main()
{

    return 0;
}