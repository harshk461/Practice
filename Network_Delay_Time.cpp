// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// private:
//     // adj matrix
//     vector<pair<int, int>> adj[101];
//     void dfs(int node, int time, vector<int> signal)
//     {
//         if (time >= signal[node])
//             return;

//         signal[node] = time;
//         for (pair<int, int> nbr : adj[node])
//         {
//             int travelTime = nbr.first;
//             int nbr_node = nbr.second;

//             dfs(nbr_node, time + travelTime, signal);
//         }
//     }

// public:
//     int networkDelayTime(vector<vector<int>> &times, int n, int k)
//     {
//         for (auto vec : times)
//         {
//             int u = vec[0];
//             int v = vec[1];
//             int t = vec[2];
//             adj[u].push_back({t, v});
//         }

//         for (int i = 1; i <= n; i++)
//             sort(adj[i].begin(), adj[i].end());

//         vector<int> signal(n + 1, INT_MAX);
//         dfs(k, 0, signal);

//         int ans = INT_MIN;
//         for (int node = 1; node <= n; node++)
//             ans = max(ans, signal[node]);
//         return ans;
//     }
// };

// int main()
// {

//     return 0;
// }

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
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto it : times)
        {
            int u = it[0] - 1;
            int v = it[1] - 1;
            int t = it[2];

            adj[u].push_back({v, t});
        }

        queue<int> q;
        q.push(k - 1);
        int ans = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            int maxi = 0;
            for (auto nbr : adj[node])
            {
                maxi = max(maxi, nbr.second);
                q.push(nbr.first);
            }
            ans += maxi;
        }

        return maxi;
    }
};

int main()
{

    return 0;
}