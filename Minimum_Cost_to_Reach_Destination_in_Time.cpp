#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int index, int maxTime, unordered_map<int, list<pair<int, int>>> &adj,
              vector<int> &fees, vector<vector<int>> &dp)
    {
        if (maxTime < 0)
            return 1e8;

        if (index == adj.size() - 1)
            return maxTime >= 0 ? fees[index] : 1e8;

        if (dp[index][maxTime] != -1)
            return dp[index][maxTime];

        int temp = 1e8;

        for (auto nbr : adj[index])
            temp = min(temp, fees[index] + solve(nbr.first, maxTime - nbr.second, adj, fees, dp));

        return dp[index][maxTime] = temp;
    }

public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees)
    {
        unordered_map<int, list<pair<int, int>>> adj;
        int n = edges.size();
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int c = it[2];

            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }

        int ans = solve(0, maxTime, adj, passingFees, dp);

        return ans == 1e8 ? -1 : ans;
    }
};

int main()
{

    return 0;
}