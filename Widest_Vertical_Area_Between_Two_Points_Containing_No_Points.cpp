#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        int maxi = 0;
        for (int i = 0; i < points.size() - 1; i++)
        {
            maxi = max(maxi, points[i][0] - points[i + 1][0]);
        }
        return maxi;
    }
};

int main()
{
    vector<vector<int>> arr = {{8, 7}, {9, 9}, {7, 4}, {9, 7}};
    Solution s;
    s.maxWidthOfVerticalArea(arr);
    return 0;
}