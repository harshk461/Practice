#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        int maxi = 0;
        unordered_map<int, unordered_set<int>> adj;
        for (auto vec : roads)
        {
            int u = vec[0];
            int v = vec[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int curr = adj[i].size() + adj[j].size();
                if (adj[i].find(j) != adj[i].end())
                    curr--;

                maxi = max(maxi, curr);
            }
        }

        return maxi;
    }
};

int main()
{

    return 0;
}