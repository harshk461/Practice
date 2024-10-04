#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        unordered_map<int, vector<int>> adj;
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> minimum(n + 1, INT_MAX);
        vector<int> second_minimum(n + 1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({1, 0});
        minimum[1] = 0;

        while (!pq.empty())
        {
            auto top = pq.top();
            int node = top.first;
            int node_time = top.second;
            pq.pop();

            int node_change_time = node_time / change;

            int wait_time;
            if (node_change_time % 2 == 1)
                wait_time = (node_change_time + 1) * change;
            else
                wait_time = node_time;

            int new_time = wait_time + time;
            for (auto it : adj[node])
            {
                if (new_time < minimum[it])
                {
                    second_minimum[it] = minimum[it];
                    minimum[it] = new_time;
                    pq.push({it, new_time});
                }
                else if (new_time > minimum[it] && new_time < second_minimum[it])
                {
                    second_minimum[it] = new_time;
                    pq.push({it, new_time});
                }
            }

            return second_minimum[n];
        }
    }
};

int main()
{

    return 0;
}