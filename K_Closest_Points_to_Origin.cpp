#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

typedef pair<double, vector<int>> pi;
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for (auto it : points)
        {
            double dist = (double)sqrt(pow(it[0], 2) + pow(it[1], 2));
            // cout << dist << " ";
            pq.push({dist, {it[0], it[1]}});
        }

        vector<vector<int>> ans;

        while (k--)
        {
            auto top = pq.top();
            pq.pop();

            ans.push_back(top.second);
        }
        return ans;
    }
};

int main()
{

    return 0;
}