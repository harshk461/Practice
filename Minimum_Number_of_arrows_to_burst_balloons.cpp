#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int arrows = 1;
        sort(points.begin(), points.end(), [&](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        int end = points[0][1];

        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > end)
            {
                arrows++;
                end = points[i][1];
            }
            else
            {
                end = min(end, points[i][1]);
            }
        }

        return arrows;
    }
};

int main()
{

    return 0;
}