#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isSafe(int node, int color, unordered_map<int, vector<int>> &adj, vector<int> &colors)
    {
        for (auto nbr : adj[node])
        {
            if (colors[nbr] == color)
                return false;
        }

        return true;
    }
    bool dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &colors, int n, int m)
    {
        if (node == n)
            return true;

        for (int col = 1; col <= m; col++)
        {
            if (isSafe(node, col, adj, colors, n, m))
            {
                colors[node] = col;
                if (dfs(node + 1, adj, colors, n, m))
                    return true;
                colors[node] = 0;
            }
        }

        return false;
    }

public:
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < 101; i++)
        {
            for (int j = 0; j < 101; j++)
            {
                if (graph[i][j])
                {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> colors(n, 0);
        if (dfs(0, adj, colors, n, m))
            return true;
        return false;
    }
};

int main()
{

    return 0;
}