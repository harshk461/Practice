#include <bits/stdc++.h>
using namespace std;

class Solution
{
    typedef long long LL;

private:
    void dfs(int &index, int &count, vector<vector<int>> &graph, vector<bool> &vis)
    {
        vis[index] = true;
        count++;

        for (int i = 0; i < graph[index].size(); i++)
        {
            if (!vis[graph[index][i]])
                dfs(graph[index][i], count, graph, vis);
        }
    }

public:
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        int n = bombs.size();
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++)
        {
            LL x1 = bombs[i][0];
            LL y1 = bombs[i][1];
            LL r1 = bombs[i][2];

            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    LL x2 = abs(x1 - bombs[j][0]);
                    LL y2 = abs(y1 - bombs[j][1]);
                    LL r2 = bombs[j][2];
                    if (pow(x2, 2) + pow(y2, 2) <= r1 * r1)
                        graph[i].push_back(j);
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int bomb_count = 0;
            vector<bool> vis(n);

            dfs(i, bomb_count, graph, vis);

            ans = max(ans, bomb_count);
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}};
    Solution s;
    s.maximumDetonation(arr);

    return 0;
}