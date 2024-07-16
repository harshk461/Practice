#include <bits/stdc++.h>
using namespace std;

class Disjoint
{
public:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
    vector<int> weight;
    int components;
    Disjoint(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        weight.resize(n + 1, INT_MAX);
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
        // return parent[node] = FindUltimateParent(parent[node]);
        return FindUltimateParent(parent[node]);
    }

    void UnionByRank(int u, int v, int w)
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

    bool UnionBySize(int u, int v, int w)
    {
        int ulp_u = FindUltimateParent(u);
        int ulp_v = FindUltimateParent(v);

        if (ulp_u == ulp_v)
        {
            weight[ulp_u] = weight[ulp_u] & weight[ulp_v] & w;
            weight[ulp_v] = weight[ulp_u] & weight[ulp_v] & w;

            return false;
        }

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

        weight[ulp_u] = weight[ulp_u] & weight[ulp_v] & w;
        weight[ulp_v] = weight[ulp_u] & weight[ulp_v] & w;

        components--;
        return true;
    }

    int getWeight(int u)
    {
        return weight[FindUltimateParent(u)];
    }
};

class Solution
{
public:
    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
    {
        int m = query.size();
        Disjoint ds(n);

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            ds.UnionBySize(u, v, w);
        }
        vector<int> ans(m, 0);

        for (int i = 0; i < m; i++)
        {
            int start = query[i][0];
            int end = query[i][1];

            if (ds.FindUltimateParent(start) != ds.FindUltimateParent(end))
                ans[i] = -1;
            else
            {
                ans[i] = ds.getWeight(start);
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}