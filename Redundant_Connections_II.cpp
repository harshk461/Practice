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
};

class Solution
{
private:
    boold checkDSUCycle(int n, vector<vector<int>> &edges, vector<int> &blacklist)
    {
        Disjoint ds(n);

        for (int i = 0; i < edges.size(); i++)
        {
            if (blacklist.size() > 0 && edges[i] == blacklist)
                continue;

            if (ds.FindUltimateParent(edges[i][0]) == ds.FindUltimateParent(edges[i][1]))
            {
                edge = edges[i];
                return true;
            }
            else
                ds.UnionBySize(edges[i][0], edges[i][1]);
        }

        return false;
    }

public:
    vector<int> edge;
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> indegree(n + 1, -1);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if (indegree[v] != -1)
            {
                vector<int> blacklist = edges[i];
                if (checkDSUCycle(n, edges, blacklist))
                    return edges[indegree[v]];
                else
                    return blacklist
            }
            else
                indegree[v] = i;
        }

        vector<int> noblackList;
        checkDSUCycle(n, edges, noblackList);
        return edge;
    }
};

int main()
{

    return 0;
}