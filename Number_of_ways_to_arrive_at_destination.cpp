// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// private:
//     int solve(vector<vector<pair<int, int>>> &graph, int src, int dst, int n)
//     {
//         int MOD = (int)(1e9 + 7);
//         vector<int> ways(n, 0);
//         vector<int> dist(n, 1e9);
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//         ways[src] = 1;
//         dist[src] = 0;

//         pq.push({dist[src], src});

//         while (!pq.empty())
//         {
//             auto [d, u] = pq.top();
//             pq.pop();

//             if (d > dist[u])
//                 continue;

//             for (auto &[v, w] : graph[u])
//             {
//                 if (d + w < dist[v])
//                 {
//                     dist[v] = d + w;
//                     ways[v] = ways[u];
//                     pq.push({dist[v], v});
//                 }
//                 else if (d + w == dist[u])
//                 {
//                     ways[v] += ways[u];
//                     ways[v] %= MOD;
//                 }
//             }
//         }
//         return ways[dst];
//     }

// public:
//     int countPaths(int n, vector<vector<int>> &roads)
//     {
//         // vector<pair<int, int>> adj[n];
//         // for (auto it : roads)
//         // {
//         //     adj[it[0]].push_back({it[1], it[2]});
//         //     adj[it[1]].push_back({it[0], it[2]});
//         // }

//         // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         // int MOD = (int)(1e9 + 7);
//         // vector<int> dist(n, 1e9), ways(n, 0);
//         // dist[0] = 0;
//         // ways[0] = 1;

//         // pq.push({0, 0});
//         // while (!pq.empty())
//         // {
//         //     int dis = pq.top().first;
//         //     int node = pq.top().second;
//         //     pq.pop();

//         //     for (auto it : adj[node])
//         //     {
//         //         int adjNode = it.first;
//         //         int edW = it.second;
//         //         // first time
//         //         if (dis + edW < dist[adjNode])
//         //         {
//         //             dist[adjNode] = dis + edW;
//         //             pq.push({dis + edW, adjNode});
//         //             ways[adjNode] = ways[node];
//         //         }
//         //         else if (dis + edW == dist[adjNode])
//         //             ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
//         //     }
//         // }
//         // return ways[n - 1] % MOD;

//         vector<vector<pair<int, int>>> graph(n);

//         for (const vector<int> &road : roads)
//         {
//             const int u = road[0];
//             const int v = road[1];
//             const int w = road[2];
//             graph[u].emplace_back(v, w);
//             graph[v].emplace_back(u, w);
//         }
//         return solve(graph, 0, n - 1, n);
//     }
// };

// class Solution
// {
// public:
//     int countPaths(int n, vector<vector<int>> &roads)
//     {
//         vector<vector<pair<int, int>>> graph(n);

//         for (const vector<int> &road : roads)
//         {
//             const int u = road[0];
//             const int v = road[1];
//             const int w = road[2];
//             graph[u].emplace_back(v, w);
//             graph[v].emplace_back(u, w);
//         }

//         return dijkstra(graph, 0, n - 1);
//     }

// private:
//     int dijkstra(const vector<vector<pair<int, int>>> &graph, int src, int dst)
//     {
//         constexpr int kMod = 1'000'000'007;
//         vector<long long> ways(graph.size());
//         vector<long long> dist(graph.size(), LLONG_MAX);
//         using P = pair<long long, int>; // (d, u)
//         priority_queue<P, vector<P>, greater<>> minHeap;

//         ways[src] = 1;
//         dist[src] = 0;
//         minHeap.emplace(dist[src], src);

//         while (!minHeap.empty())
//         {
//             const auto [d, u] = minHeap.top();
//             minHeap.pop();
//             if (d > dist[u])
//                 continue;
//             for (const auto &[v, w] : graph[u])
//                 if (d + w < dist[v])
//                 {
//                     dist[v] = d + w;
//                     ways[v] = ways[u];
//                     minHeap.emplace(dist[v], v);
//                 }
//                 else if (d + w == dist[v])
//                 {
//                     ways[v] += ways[u];
//                     ways[v] %= kMod;
//                 }
//         }

//         return ways[dst];
//     }
// };

// int main()
// {
//     Solution s;
//     vector<vector<int>> arr = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
//     s.countPaths(7, arr);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>> &roads)
    {
        unordered_map<long long, vector<pair<long long, long long>>> adj;
        for (auto it : roads)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> paths(n);
        paths[0] = 1;

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
        // dist,node
        q.push({0, 0});

        dist[0] = 0;

        while (!q.empty())
        {
            auto top = q.top();
            q.pop();

            int node = top.second;
            long long wt = top.first;

            for (auto it : adj[node])
            {
                int nbr = it.first;
                int edge_wt = it.second;

                if (dist[nbr] > wt + edge_wt)
                {
                    dist[nbr] = wt + edge_wt;
                    q.push({dist[nbr], nbr});
                    paths[nbr] = paths[node] % MOD;
                }
                else if (dist[nbr] == wt + edge_wt)
                    paths[nbr] += paths[node] % MOD;
            }
        }

        return paths[n - 1] % MOD;
    }
};

int main()
{

    return 0;
}