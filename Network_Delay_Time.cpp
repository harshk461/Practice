#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // adj matrix
    vector<pair<int, int>> adj[101];
    void dfs(int node, int time, vector<int> signal)
    {
        if (time >= signal[node])
            return;

        signal[node] = time;
        for (pair<int, int> nbr : adj[node])
        {
            int travelTime = nbr.first;
            int nbr_node = nbr.second;

            dfs(nbr_node, time + travelTime, signal);
        }
    }

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        for (auto vec : times)
        {
            int u = vec[0];
            int v = vec[1];
            int t = vec[2];
            adj[u].push_back({t, v});
        }

        for (int i = 1; i <= n; i++)
            sort(adj[i].begin(), adj[i].end());

        vector<int> signal(n + 1, INT_MAX);
        dfs(k, 0, signal);

        int ans = INT_MIN;
        for (int node = 1; node <= n; node++)
            ans = max(ans, signal[node]);
        return ans;
    }
};

int main()
{

    return 0;
}