#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    double bruteButWithWrongAnswer(int n, vector<vector<int>> &edges,
                                   vector<double> &succProb, int start_node, int end_node)
    {
        double ans = 0.0;

        // node->{nbr,weight}
        unordered_map<int, vector<pair<int, double>>> adj;

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            double cost = succProb[i];

            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
        }

        //{cost,node}
        priority_queue<pair<double, int>> q;
        q.push({1.0, start_node});

        vector<double> prob(n, 0);

        // probability of reaching start node is always 1.0
        prob[start_node] = 1;
        while (!q.empty())
        {
            auto top = q.top();
            q.pop();

            int node = top.second;
            double c = top.first;

            // cout << node << " " << c << endl;

            if (node == end_node)
            {
                return c;
            }

            for (auto nbr : adj[node])
            {
                if (prob[nbr.first] < nbr.second * c)
                {
                    prob[nbr.first] = nbr.second * c;
                    q.push({c * nbr.second, nbr.first});
                }
            }
        }

        return 0;
    }

    void dijkstra(int src, unordered_map<int, vector<pair<int, double>>> &adj, vector<double> &dist)
    {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            double d = pq.top().first;
            pq.pop();

            for (auto &edge : adj[u])
            {
                int v = edge.first;
                double weight = edge.second;

                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    }

public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        return bruteButWithWrongAnswer(n, edges, succProb, start_node, end_node);
    }
};

int main()
{

    return 0;
}