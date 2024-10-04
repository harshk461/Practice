// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// private:
//     int dfs(int stone, unordered_map<int, vector<int>> &adj, vector<bool> &vis)
//     {
//         vis[stone] = true;

//         for (auto nbr : adj[stone])
//         {
//             if (!vis[nbr])
//                 dfs(nbr, adj, vis);
//         }
//     }

// public:
//     int removeStones(vector<vector<int>> &stones)
//     {
//         int n = stones.size();
//         unordered_map<int, vector<int>> adj;

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i + 1; j < n; j++)
//             {
//                 if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
//                 {
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }

//         vector<bool> vis(n);
//         int components = 0;

//         for (int i = 0; i < n; i++)
//         {
//             if (!vis[i])
//             {
//                 components++;
//                 dfs(i, adj, vis);
//             }
//         }
//         return n - components;
//     }
// };

// int main()
// {

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx, mmx, sse2, sse3, sse4")

static const int disableSync = [](void) noexcept -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

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
    int removeStones(vector<vector<int>> &stones)
    {
        int row = 0;
        int col = 0;
        for (auto it : stones)
        {
            row = max(row, it[0]);
            col = max(col, it[1]);
        }

        Disjoint ds(row + col);

        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = i + 1; j < stones.size(); j++)
            {

                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    ds.UnionBySize(i, j);
            }
        }

        return stones.size() - ds.NumberOfConnectedComponents;
    }
};

int main()
{

    return 0;
}