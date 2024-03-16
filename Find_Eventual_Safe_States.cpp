#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// private:
//     bool dfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &vis, vector<bool> &present)
//     {
//         if (vis[node])
//             return false;
//         if (present[node])
//             return true;

//         vis[node] = true;
//         present[node] = true;

//         for (auto nbr : adj[node])
//         {
//             if (dfs(nbr, adj, vis, present))
//                 return true;
//         }

//         // backtrack
//         present[node] = false;
//         return false;
//     }

// public:
//     vector<int> eventualSafeNodes(vector<vector<int>> &graph)
//     {
//         int n = graph.size();
//         vector<bool> vis(n), present(n);

//         for (int i = 0; i < n; i++)
//             adj[i] = graph[i];

//         for (int i = 0; i < n; i++)
//             dfs(i, adj, vis, present);

//         vector<int> ans;
//         for (int i = 0; i < n; i++)
//             if (!present[i])
//                 ans.push_back(i);

//         return ans;
//     }
// };

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++)
            // i->it
            // it->i
            for (auto it : graph[i])
            {
                adj[it].push_back(i);
                indegree[i]++;
            }
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
            {
                ans.push_back(i);
                q.push(i);
            }

        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            for (auto it : adj[top])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    ans.push_back(it);
                    q.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> arr = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<int> ans = s.eventualSafeNodes(arr);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}