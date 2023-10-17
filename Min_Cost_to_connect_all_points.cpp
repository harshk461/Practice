#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int distance(vector<int> a, vector<int> b)
    {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        if (points.size() < 1)
            return 0;

        int n = points.size();
        vector<int> minDist(n, 0);
        minDist[0] = INT_MAX;
        int ans = 0;
        for (int i = 1; i < n; i++)
            minDist[i] = distance(points[0], points[i]);

        for (int i = 1; i < n; i++)
        {
            auto it = min_element(minDist.begin(), minDist.end());
            ans += *it;
            int index = it - minDist.begin();
            *it = INT_MAX;
            for (auto i = 0; i < n; i++)
            {
                if (minDist[i] == INT_MAX)
                    continue;
                minDist[i] = min(minDist[i], distance(points[i], points[index]));
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> arr = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    Solution s;
    cout << s.minCostConnectPoints(arr);
    return 0;
}