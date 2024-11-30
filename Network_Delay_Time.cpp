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
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int> dist(n, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> adj;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto it : times)
        {
            int u = it[0] - 1;
            int v = it[1] - 1;
            int w = it[2];

            adj[u].push_back({v, w});
        }

        dist[k - 1] = 0;
        pq.push({0, k - 1});

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

        int ans = 0;
        for (auto it : dist)
        {
            // cout<<it<<" ";
            if (it == INT_MAX)
                return -1;
            // We need to maximize the travel time across all reachable nodes
            // This is because we are looking for the minimum time required to send the signal to all nodes
            ans = max(ans, it);
        }

        return ans;
    }
};

int main()
{

    return 0;
}