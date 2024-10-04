#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        // shortest distance from each node
        for (int k = 0; k < n; k++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int i = 0; i < n; i++)
                {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    {
                        if (dist[i][j] > dist[i][k] + dist[k][j])
                            dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        map<int, vector<int>> node_to_node;
        for (int i = 0; i < n; i++)
        {
            vector<int> emp;
            node_to_node[i] = emp;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] <= distanceThreshold && i != j)
                    node_to_node[i].push_back(j);
            }
        }

        for (auto it : node_to_node)
        {
            cout << it.first << "->" << it.second.size();
            // for (auto i : it.second)
            //     cout << i << " ";
            cout << endl;
        }
        int ans = -1;
        int curr_min_city_size = INT_MAX;
        for (auto it : node_to_node)
        {
            if (it.second.size() < curr_min_city_size)
            {
                curr_min_city_size = it.second.size();
                ans = it.first;
            }
            if (it.second.size() == curr_min_city_size)
                ans = max(ans, it.first);
        }

        return ans;
    }
};

int main()
{

    return 0;
}