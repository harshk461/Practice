#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        // node->{count,winning/Lossing}
        map<int, int> loss;

        vector<vector<int>> ans(2);

        for (auto it : matches)
        {
            loss[it[1]]++;
        }

        for (auto it : loss)
            if (it.second == 1)
                ans[1].push_back(it.first);

        set<int> vis;
        for (auto it : matches)
            if (loss.find(it[0]) == loss.end() && vis.find(it[0])==vis.end())
            {
                vis.insert(it[0]);
                ans[0].push_back(it[0]);
            }
        return ans;
    }
};

int main()
{

    return 0;
}