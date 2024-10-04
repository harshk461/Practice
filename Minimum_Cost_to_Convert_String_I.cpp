#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        int n = source.length();
        int m = original.size();
        vector<vector<long long>> dist(26, vector<long long>(26, INT_MAX));

        for (int i = 0; i < m; i++)
        {
            int org = original[i] - 'a';
            int chg = changed[i] - 'a';
            int co = cost[i];
            dist[org][chg] = (long long)co;
        }

        // floyd warshall
        for (int k = 0; k < 26; k++)
        {
            for (int j = 0; j < 26; j++)
            {
                for (int i = 0; i < 26; i++)
                {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // for (int i = 0; i < 26; i++)
        // {
        //     for (int j = 0; j < 26; j++)
        //     {
        //         if (dist[i][j] != LONG_LONG_MAX)
        //             cout << dist[i][j] << " ";
        //         else
        //             cout << " ";
        //     }
        //     cout << endl;
        // }

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (source[i] == target[i])
                continue;
            // cout << source[i] << "->" << target[i] << " " << dist[source[i] - 'a'][target[i] - 'a'] << endl;
            if (dist[source[i] - 'a'][target[i] - 'a'] >= INT_MAX)
                return -1;

            ans += dist[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};

int main()
{
    return 0;
}