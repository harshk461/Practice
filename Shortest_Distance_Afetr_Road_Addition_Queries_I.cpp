#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void floydWarshall(vector<vector<int>> &dist, int n)
    {
        for (int k = 0; k < n; k++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int i = 0; i < n; i++)
                {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    {
                        if (dist[i][j] > dist[i][k] + dist[k][j])
                            dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    int dijkstra(vector<vector<pair<int, int>>> &graph, int n)
    {
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto ele = pq.top();
            int cd = ele.first, node = ele.second;
            pq.pop();
            if (node == n - 1)
                return dist[n - 1];
            if (cd > dist[node])
                continue;
            for (auto ele : graph[node])
            {
                int nbr = ele.first, wt = ele.second;
                if (cd + wt < dist[nbr])
                {
                    dist[nbr] = cd + wt;
                    pq.push({cd + wt, nbr});
                }
            }
        }
        return dist[n - 1];
    }

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        int m = queries.size();
        vector<vector<pair<int, int>>> adj;
        for (int i = 0; i < n - 1; i++)
        {
            adj[i].push_back({i + 1, 1});
        }

        dijkstra(adj, n);

        // for (auto it : adj)
        // {
        //     for (auto i : it)
        //     {
        //         if (i != INT_MAX)
        //             cout << i << " ";
        //         else
        //             cout << " ";
        //     }
        //     cout << endl;
        // }

        vector<int> ans;
        for (auto it : queries)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back({v, 1});
            // adj[v][u]=1;

            int d = dijkstra(adj, n);
            ans.push_back(d);
        }

        return ans;
    }
};

int main()
{

    return 0;
}