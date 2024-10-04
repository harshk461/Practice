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
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++)
            if (manager[i] != -1)
                adj[manager[i]].push_back(i);

        queue<pair<int, int>> q;
        q.push({headID, 0});
        int ans = 0;
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();

            int node = top.first;
            int time = top.second;
            ans = max(ans, time);

            for (auto it : adj[node])
            {
                q.push({it, time + informTime[it]});
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}