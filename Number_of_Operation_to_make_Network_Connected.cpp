#include <bits/stdc++.h>
using namespace std;

class Disjoint
{
public:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
    Disjoint(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
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

    void UnionBySize(int u, int v)
    {
        int ulp_u = FindUltimateParent(u);
        int ulp_v = FindUltimateParent(v);

        if (ulp_u == ulp_v)
            return;

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
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int num_of_connected = 0;
        int extra_connection = 0;

        Disjoint ds(n);

        for (auto it : connections)
        {
            int u = it[0];
            int v = it[1];

            if (ds.FindUltimateParent(u) == ds.FindUltimateParent(v))
                extra_connection++;
            else
                ds.UnionBySize(u, v);
        }

        for (int i = 0; i < n; i++)
            // if they are the parent means they are head of the component
            // if parent[i]!=i means it belongs to another component with different parent
            if (ds.parent[i] == i)
                num_of_connected++;

        if (num_of_connected - 1 <= extra_connection)
            return num_of_connected - 1;

        return -1;
    }
};

int main()
{

    return 0;
}