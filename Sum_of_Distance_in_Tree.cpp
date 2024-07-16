#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // dfs is for finding the result of 0th node and number of childrens of each node.
    int dfs(int node, vector<int> adj[], vector<int> &child, vector<int> &visited, int &res, int level)
    {
        visited[node] = 1;

        res += level;

        int children = 0;
        for (auto neigh : adj[node])
        {
            if (visited[neigh] == 0)
            {
                children += dfs(neigh, adj, child, visited, res, level + 1);
            }
        }

        return child[node] = children + 1;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {

        vector<int> adj[n];

        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int res = 0;
        int level = 0;
        vector<int> child(n, 0);
        vector<int> visited(n, 0);

        int temp = dfs(0, adj, child, visited, res, level);

        // Now you have , number of childrens of each node and 0th node answer in 'res' .
        // For each node find its parent result. and node answer will be -> (paren_val - number of node children + number of upper nodes)

        vector<int> result(n, 0);
        vector<int> visited1(n, 0);

        queue<pair<int, int>> q;
        q.push({0, 0});
        visited1[0] = 1;

        while (q.size() > 0)
        {
            auto front = q.front();
            q.pop();

            int node = front.first;
            int parent = front.second;

            if (node == 0)
            {
                result[node] = res;
            }
            else
            {
                int parent_val = result[parent];
                int upper_nodes = (n - child[node]);

                result[node] = (parent_val - child[node] + upper_nodes);
            }

            for (auto neigh : adj[node])
            {
                if (visited1[neigh] == 0)
                {
                    q.push({neigh, node});
                    visited1[neigh] = 1;
                }
            }
        }

        return result;
    }
};

int main()
{
    return 0;
}