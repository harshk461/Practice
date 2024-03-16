#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int row, int x, int y, int ss, vector<vector<int>> &dist)
    {
        int n = dist.size();
        int count = 0;

        for (int i = x; i >= 0; i--)
        {
            for (int j = y; j <= n; j++)
            {
                if (dist[row][i] % ss == 0 && dist[row][j] % ss == 0)
                    count++;
            }
        }

        return count;
    }

public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int k)
    {
        int n = edges.size();
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});

            dist[u][v] = w;
            dist[v][u] = w;
        }

        // int n=adj.size();

        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=n;j++){
        //         dist[i][j]=adj[i][j].second;
        //         dist[j][i]=adj[j][i];
        //     }
        // }

        for (int k = 0; k <= n; k++)
        {
            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= n; j++)
                {
                    if ((dist[k][j] != INT_MAX) && (dist[i][k] != INT_MAX))
                    {
                        if (dist[i][j] > dist[i][k] + dist[k][j])
                        {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
        }

        for (int i = 0; i <= n; i++)
        {
            dist[i][i] = 0;
        }

        unordered_map<int, vector<int>> map;

        for (int i = 0; i <= n; i++)
        {
            map[i] = dist[i];
        }

        for (auto it : map)
        {
            cout << it.first << "->";
            for (auto i : it.second)
                cout << i << " ";
            cout << endl;
        }

        vector<int> count(n + 1, 0);
        // for(int i=0;i<=n;i++){
        //     int t=0;
        //     for(int j=0;j<=n;j++){
        //         if(dist[i][j]==0){
        //             int x=i-1;
        //             int y=i+1;
        //             t=solve(i,x,y,signalSpeed,dist);
        //             count[i]=t;
        //             break;
        //         }
        //     }
        // }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                for (int l = i + 1; l <= n; l++)
                {
                    if (dist[i][l] % k == 0 && dist[i][j] % k == 0)
                        count[i]++;
                }
            }
        }

        return count;
    }
};

int main()
{
    vector<vector<int>> edges = {{0, 6, 3}, {6, 5, 3}, {0, 3, 1}, {3, 2, 7}, {3, 1, 6}, {3, 4, 2}};
    Solution s;
    s.countPairsOfConnectableServers(edges, 3);
    return 0;
}