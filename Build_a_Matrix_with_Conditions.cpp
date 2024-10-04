#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> topological(unordered_map<int, vector<int>> &graph, int k)
    {
        unordered_set<int> curr_path;
        unordered_set<int> vis;

        vector<int> ans;

        for (int i = 1; i <= k; i++)
        {
            if (!dfs(i, graph, vis, curr_path, ans))
                return {};
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    bool dfs(int node, unordered_map<int, vector<int>> &graph, unordered_set<int> &vis, unordered_set<int> &curr, vector<int> &ans)
    {
        // cycle exist
        if (curr.find(node) != curr.end())
            return false;

        // already traversed
        if (vis.find(node) != vis.end())
            return true;

        vis.insert(node);
        curr.insert(node);

        for (auto nbr : graph[node])
        {
            if (!dfs(nbr, graph, vis, curr, ans))
                return false;
        }

        // backtrack
        curr.erase(node);
        ans.push_back(node);

        return true;
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        vector<vector<int>> mat(k, vector<int>(k, 0));
        unordered_map<int, vector<int>> graph1;
        unordered_map<int, vector<int>> graph2;

        for (auto it : rowConditions)
        {
            int u = it[0];
            int v = it[1];

            graph1[u].push_back(v);
        }

        for (auto it : colConditions)
        {
            int u = it[0];
            int v = it[1];

            graph2[u].push_back(v);
        }

        vector<int> row_topo = topological(graph1, k);
        vector<int> col_topo = topological(graph2, k);

        if (row_topo.empty() || col_topo.empty())
            return {};

        unordered_map<int, pair<int, int>> val_to_posn;

        for (int i = 0; i < k; i++)
        {
            val_to_posn[row_topo[i]].first = i;
            val_to_posn[col_topo[i]].second = i;
        }

        for (int i = 1; i <= k; i++)
        {
            int row = val_to_posn[i].first;
            int col = val_to_posn[i].second;

            mat[row][col] = i;
        }

        return mat;
    }
};

int main()
{

    return 0;
}