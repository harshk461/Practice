#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        set<pair<int, int>> k;
        for (auto o : obstacles)
            k.insert({o[0], o[1]});

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int x = 0, y = 0, m = 0, n = 0;

        for (int b : commands)
        {
            if (b == -1)
                m = (m + 1) % 4;
            else if (b == -2)
                m = (m + 3) % 4;
            else
            {
                for (int i = 0; i < b; ++i)
                {
                    int u = x + dx[m], v = y + dy[m];
                    if (k.count({u, v}))
                        break;
                    x = u;
                    y = v;
                    n = max(n, x * x + y * y);
                }
            }
        }
        return n;
    }
};
int main()
{

    return 0;
}