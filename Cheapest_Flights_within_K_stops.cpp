#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int dijkstra(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto vec : flights)
            adj[vec[0]].push_back({vec[1], vec[2]});

        vector<int> stops(n, numeric_limits<int>::max());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // {dist_from_src_node, node, number_of_stops_from_src_node}
        pq.push({0, src, 0});

        while (!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();
            int dist = temp[0];
            int node = temp[1];
            int steps = temp[2];

            if (steps > stops[node] || steps > k + 1)
                continue;

            stops[node] = steps;
            if (node == dst)
                return dist;

            for (auto &[nbr, price] : adj[node])
                pq.push({dist + price, nbr, steps + 1});
        }
        return -1;
    }

public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // node->{nbr,cost}
        vector<vector<pair<int, int>>> adj(n);
        for (auto vec : flights)
            adj[vec[0]].push_back({vec[1], vec[2]});

        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;
        while (stops <= k && !q.empty())
        {
            int size = q.size();
            // iterate curr level
            while (size--)
            {
                auto &[node, distance] = q.front();
                q.pop();

                for (auto &[nbr, price] : adj[node])
                {
                    if (price + distance >= dist[nbr])
                        continue;
                    dist[nbr] = price + distance;
                    q.push({nbr, dist[nbr]});
                }
            }
            stops++;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

int main()
{

    return 0;
}