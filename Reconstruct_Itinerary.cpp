#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(string airport, unordered_map<string, vector<string>> &adj, vector<string> &ans)
    {
        vector<string> dest = adj[airport];

        while (!dest.empty())
        {
            string nextDest = dest.back();
            dest.pop_back();
            dfs(nextDest, adj, ans);
        }

        ans.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, vector<string>> adj;
        vector<string> ans;
        for (auto it : tickets)
        {
            string u = it[0];
            string v = it[1];
            adj[u].push_back(v);
        }

        // sorting destination
        for (auto &entry : adj)
            sort(entry.second.begin(), entry.second.end());

        dfs("JFK", adj, ans);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}