#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countOfPairs(int n, int x, int y)
    {
        unordered_map<int, vector<int>> adj;
        for (int i = 1; i < n; i++)
        {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }

        adj[x].push_back(y);
        adj[y].push_back(x);

        unordered_map<int, int> mp;

        for (int i = 1; i <= n; i++)
        {
            vector<int> vis(n + 1, 0);
            queue<pair<int, int>> q;
            vis[i] = 1;
            // moves,node
            q.push({i, 0});

            while (!q.empty())
            {
                auto top = q.front();
                q.pop();
                mp[top.second]++;
                for (auto nbr : adj[top.first])
                {
                    if (!vis[nbr])
                    {
                        vis[nbr] = 1;
                        q.push({nbr, top.second + 1});
                    }
                }
            }
        }

        vector<int> ans;
        // for (auto it : mp)
        //     cout << it.first << " " << it.second << endl;
        for (int k = 1; k <= n; k++)
        {
            if (mp.find(k) != mp.end())
                ans.push_back(mp[k]);
            else
                ans.push_back(0);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> ans = s.countOfPairs(4, 1, 1);
    for (auto it : ans)
        cout << it << " ";

    return 0;
}