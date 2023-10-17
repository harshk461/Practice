#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<vector<int>> &isConnected, unordered_map<int, bool> vis)
    {
        vis[node] = true;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (isConnected[node][i] && !vis[i])
                dfs(i, isConnected, vis);
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int count = 0;
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                count++;
                dfs(i, isConnected, vis);
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}