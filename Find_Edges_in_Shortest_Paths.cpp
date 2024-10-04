#include <bits/stdc++.h>
using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto h1 = hash<T1>()(p.first);
        auto h2 = hash<T2>()(p.second);
        return h1 ^ h2; // XOR the two hash values
    }
};

class Solution
{
private:
    vector<vector<int>> all;

    void dijkstra(int n, int src, unordered_map<int, vector<pair<int, int>>> &adj, vector<vector<int>> &parent)
    {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty())
        {
            auto top = pq.top();
            int node = top.second;
            int ds = top.first;
            pq.pop();
            for (auto nbr : adj[node])
            {
                int next_node = nbr.first;
                int edge_weight = nbr.second;

                if (dist[node] + edge_weight < dist[next_node])
                {
                    dist[next_node] = dist[node] + edge_weight;
                    pq.push({dist[next_node], next_node});
                    parent[next_node].clear();
                    parent[next_node].push_back(node);
                }
                else if (dist[node] + edge_weight == dist[next_node])
                {
                    parent[next_node].push_back(node);
                }
            }
        }
    }

    void findAllPaths(int node, vector<vector<int>> &parent, vector<int> &path)
    {
        if (node == 0)
        {
            path.push_back(0);
            reverse(path.begin(), path.end());
            all.push_back(path);
            reverse(path.begin(), path.end());
            path.pop_back();
            return;
        }

        path.push_back(node);
        for (int p : parent[node])
        {
            findAllPaths(p, parent, path);
        }
        path.pop_back();
    }

public:
    vector<bool> findAnswer(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> parent(n);
        unordered_map<int, vector<pair<int, int>>> adj;
        unordered_map<pair<int, int>, int, pair_hash> mp;
        int m = edges.size();
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            mp[{u, v}] = i;

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        dijkstra(n, 0, adj, parent);

        vector<int> path;
        findAllPaths(n - 1, parent, path);

        // for (auto &p : all)
        // {
        //     for (int node : p)
        //         cout << node << " ";
        //     cout << endl;
        // }
        vector<bool> ans(m);

        set<pair<int, int>> vis;
        for (auto it : all)
        {
            for (int i = 0; i < it.size() - 1; i++)
            {
                if (vis.find({it[i], it[i + 1]}) == vis.end())
                {
                    int index = mp[{it[i], it[i + 1]}];
                    ans[index] = true;
                    vis.insert({it[0], it[1]});
                }
            }
        }

        return ans;
    }
};

#define pi pair<int, int>

class Solution
{
private:
    vector<int> dijkstra(int src, int n, unordered_map<int, vector<pi>> &adj)
    {
        vector<int> distance(n, INT_MAX);
        vector<bool> vis(n);
        distance[src] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, src});

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int node = top.second;
            int wt = top.first;

            if (vis[node])
                continue;

            vis[node] = true;
            if (distance[node] < w)
                continue;

            for (auto nbr : adj[node])
            {
                if (!vis[nbr.first] && distance[nbr.first] > distance[node] + nbr.second)
                {
                    distance[nbr.first] = distance[node] + nbr.second;
                    pq.push({distance[nbr.first], nbr.first});
                }
            }
        }

        return distance;
    }

public:
    vector<bool> findAnswer(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<pi>> adj;
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> start_to_destination = dijkstra(0, n, adj);
        vector<int> destination_to_start = dijkstra(n - 1, n, adj);

        // start_to_desttination[n-1] is the minimum distance from 0 to n-1
        vector<bool> flag;

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            // in any case if the distance from start to end of u +end to start of v (u->v edge) is equal to
            // minimum distance from start to end then that edge is present in the shortest path
            if (start_to_destination[u] != INT_MAX && destination_to_start[v] != INT_MAX && start_to_destination[u] + destination_to_start[v] + w == start_to_destination[n - 1])
                flag.push_back(true);
            else if (start_to_destination[v] != INT_MAX && destination_to_start[u] != INT_MAX && start_to_destination[v] + destination_to_start[u] + w == start_to_destination[n - 1])
                flag.push_back(true);
            else
                flag.push_back(false);
        }

        return flag;
    }
};

int main()
{

    return 0;
}