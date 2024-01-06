#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool detectCycle(int src, vector<int> adj[], vector<int> &vis)
    {
        vis[src] = true;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto nbr : adj[node])
            {
                if (!vis[nbr])
                {
                    vis[nbr] = 1;
                    q.push({nbr, node});
                }
                else if (parent != nbr)
                    return true;
            }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detectCycle(i, adj, vis))
                    return true;
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}