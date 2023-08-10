#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(vector<vector<int>> &graph,
             int s, int d, vector<vector<int>> &ans, vector<int> &curr)
    {
        curr.push_back(s);
        if (s == d)
        {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < graph[s].size(), i++)
        {
            dfs(graph, graph[s][i], d, ans, curr);
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(graph, 0, target, ans, curr);
        return ans;
    }
};

int main()
{

    return 0;
}