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
    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
    {
        int n = vals.size();
        unordered_map<int, vector<int>> adj;
        Disjoint graph(n);

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];

            // we do u->v if vals[u]>=vals[v] because all the connecting path have value less than or equal
            if (vals[u] > vals[v])
                adj[u].push_back(v);
            else
                adj[v].push_back(u);
        }

        // for (auto it : adj)
        // {
        //     cout << it.first << "->";
        //     for (auto i : it.second)
        //         cout << i << " ";
        //     cout << end;
        // }

        int ans = 0;

        unordered_map<int, vector<int>> node_to_index;

        for (int i = 0; i < n; i++)
            node_to_index[vals[i]].push_back(i);

        // for (auto it : node_to_index)
        // {
        //     cout << it.first << "->";
        //     for (auto i : it.second)
        //         cout << i << " ";
        //     cout << endl;
        // }

        for (auto values : node_to_index)
        {
            unordered_map<int, int> mp;
            for (auto it : values.second)
            {
                for (auto element : adj[it])
                    graph.UnionBySize(it, element);
            }

            for (auto ele : values.second)
                mp[graph.FindUltimateParent(ele)]++;

            for (auto q : mp)
                ans += (q.second * (q.second - 1) / 2);
        }

        return ans + n;
    }
};

int main()
{

    return 0;
}