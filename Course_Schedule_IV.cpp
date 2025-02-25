#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
private:
    void dfs(int node, vector<vector<int>> &reachable, vector<vector<int>> &adjList, int startNode)
    {
        for (int neighbor : adjList[node])
        {
            if (!reachable[startNode][neighbor])
            {
                reachable[startNode][neighbor] = 1;
                dfs(neighbor, reachable, adjList, startNode);
            }
        }
    }

public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<vector<int>> adjList(n);
        for (auto &prerequisite : prerequisites)
        {
            int u = prerequisite[0];
            int v = prerequisite[1];
            adjList[u].push_back(v);
        }

        vector<vector<int>> reachable(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            reachable[i][i] = 1;
            dfs(i, reachable, adjList, i);
        }

        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];
            ans[i] = reachable[u][v];
        }

        return ans;
    }
};

int main()
{

    return 0;
}