#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isRectangleOverlap(vector<int> bottom1, vector<int> top1, vector<int> bottom2, vector<int> top2)
    {
        int x1 = bottom1[0];
        int y1 = bottom1[1];
        int x2 = top1[0];
        int y2 = top1[1];

        int a1 = bottom2[0];
        int b1 = bottom2[1];
        int a2 = top2[0];
        int b2 = top2[1];

        if (a1 >= x2 || a2 <= x1 || b2 <= y1 || b1 >= y2)
            return false;

        return true;
    }

    int overlapArea(vector<int> bottom1, vector<int> top1, vector<int> bottom2, vector<int> top2)
    {
        int ax1 = bottom1[0];
        int ay1 = bottom1[1];
        int ax2 = top1[0];
        int ay2 = top1[1];

        int bx1 = bottom2[0];
        int by1 = bottom2[1];
        int bx2 = top2[0];
        int by2 = top2[1];

        int x1 = max(ax1, bx1);
        int x2 = min(ax2, bx2);

        int y1 = max(ay1, by1);
        int y2 = min(ay2, by2);

        int x_overlap = abs(x2 - x1);
        int y_overlap = abs(y2 - y1);

        int area_overlap = max(0, x2 - x1) * max(0, y2 - y1);

        return area_overlap;
    }

public:
    long long largestSquareArea(vector<vector<int>> &bottomLeft, vector<vector<int>> &topRight)
    {
        int n = bottomLeft.size();

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isRectangleOverlap(bottomLeft[i], topRight[i], bottomLeft[j], topRight[j]) && i != j)
                {
                    ans = max(ans, overlapArea(bottomLeft[i], topRight[i], bottomLeft[j], topRight[j]));
                }
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}