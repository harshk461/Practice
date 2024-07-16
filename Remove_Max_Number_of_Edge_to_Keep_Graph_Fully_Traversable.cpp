#include <bits/stdc++.h>
using namespace std;

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
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        Disjoint alice(n);
        Disjoint bob(n);

        int edgeRequired = 0;
        for (auto it : edges)
        {
            int type = it[0];
            int u = it[1];
            int v = it[2];

            // Adding edge which both alice and bob can travel
            if (type == 3)
                if (alice.UnionBySize(u, v) | bob.UnionBySize(u, v))
                    edgeRequired++;
        }

        // process all type 1 and type 2 edges
        for (auto edge : edges)
        {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (type == 1)
                if (alice.UnionBySize(u, v))
                    edgeRequired++;
            if (type == 2)
                if (bob.UnionBySize(u, v))
                    edgeRequired++;
        }

        if (alice.isConnected() && bob.isConnected())
            return edges.size() - edgeRequired;

        return -1;
    }
};

int main()
{

    return 0;
}