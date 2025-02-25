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
    long long findScore(vector<int> &nums)
    {
        long long score = 0;
        set<int> vis;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i], i});
        }

        while (!pq.empty())
        {
            while (vis.count(pq.top().second))
                pq.pop();

            auto top = pq.top();
            pq.pop();

            vis.insert(top.second);
            score += top.first;

            if (top.second - 1 >= 0)
                vis.insert(top.second - 1);
            if (top.second + 1 < nums.size())
                vis.insert(top.second + 1);
        }

        return score;
    }
};

int main()
{

    return 0;
}