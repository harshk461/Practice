#include <bits/stdc++.h>
using namespace std;

int findCircleNum(vector<vector<int>> &isConnected)
{
    unordered_map<int, int> map;
    int ans = isConnected.size();
    for (int i = 0; i < isConnected.size(); i++)
    {
        map[i + 1] = isConnected[0][i];
    }
    for (int i = 1; i < isConnected.size(); i++)
    {
        vector<int> temp = isConnected[i];
        for (int j = 0; j < isConnected.size(); j++)
        {
            if (temp[j] == 1 || map[j + 1] == 1)
            {
                ans--;
            }
        }
    }
    return ans;
}

class Disjoint
{
public:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
    int components;
    Disjoint(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        components = n;
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    // Highest Parent
    int FindUltimateParent(int node)
    {
        if (node == parent[node])
            return node;

        // parent[node]->used for path compression
        return parent[node] = FindUltimateParent(parent[node]);
    }

    void UnionByRank(int u, int v)
    {
        int ultimateParent_u = FindUltimateParent(u);
        int ultimateParent_v = FindUltimateParent(v);

        if (ultimateParent_u == ultimateParent_v)
            return;

        if (rank[ultimateParent_u] < rank[ultimateParent_v])
            parent[ultimateParent_u] = ultimateParent_v;
        else if (rank[ultimateParent_v] < rank[ultimateParent_u])
            parent[ultimateParent_v] = ultimateParent_u;
        else
        {
            parent[ultimateParent_u] = ultimateParent_v;
            rank[ultimateParent_u]++;
        }
    }

    bool UnionBySize(int u, int v)
    {
        int ulp_u = FindUltimateParent(u);
        int ulp_v = FindUltimateParent(v);

        if (ulp_u == ulp_v)
            return false;

        // u->smaller component and v is larger
        // we are joining smaller to the larger one and changing parent of smaller one
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        components--;
        return true;
    }

    int NumberOfConnectedComponents(int n, vector<vector<int>> &edges)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];

            UnionBySize(u, v);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (parent[i] == i)
                ans++;

        return ans;
    }

    bool isConnected()
    {
        return components == 1;
    }
};

class Solution
{
public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        Disjoint ds(V);

        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj.size(); j++)
            {
                if (adj[i][j] == 1)
                    ds.UnionBySize(i, j);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                ans++;
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << findCircleNum(arr);
    return 0;
}