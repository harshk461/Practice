#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries)
    {
        int m = queries.size();
        vector<int> ans(m, 0);

        unordered_map<int, int> indegree;
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            indegree[u]++;
            indegree[v]++;
        }

        for (int i = 0; i < m; i++)
        {
            int q = queries[i];
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (indegree[i] + indegree[j] > q)
                        count++;
                }
            }
            ans[i] = count;
        }

        return ans;
    }
};

int main()
{

    return 0;
}