#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj)
    {
        vis[node] = true;
        for (auto nbr : adj[node])
        {
            if (!vis[nbr])
                dfs(nbr, vis, adj);
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<bool> vis(n);
        vis[0] = true;

        dfs(0, vis, rooms);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                return false;
        }
        return true;
    }
};

int main()
{

    return 0;
}