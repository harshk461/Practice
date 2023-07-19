#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
    {
        vector<int> ans(n);
        vector<vector<int>> graph(n);
        for (auto vec : paths)
        {
            int u = vec[0] - 1;
            int v = vec[1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 0; i < n; i++)
        {
            vector<bool> used(5);
            for (auto v : graph[i])
                used[ans[v]] = true;

            for (int type = 1; type < 5; type++)
            {
                if (!used[type])
                {
                    ans[i] = type;
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}