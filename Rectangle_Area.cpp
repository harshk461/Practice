#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        // computing 4 corner of the overlapping rectangle
        int x1 = max(ax1, bx1);
        int x2 = min(ax2, bx2);

        int y1 = max(ay1, by1);
        int y2 = min(ay2, by2);

        int x_overlap = abs(x2 - x1);
        int y_overlap = abs(y2 - y1);

        int area_overlap = max(0, x2 - x1) * max(0, y2 - y1);

        int area_of_rect1 = abs(ax2 - ax1) * abs(ay2 - ay1);
        int area_of_rect2 = abs(bx2 - bx1) * abs(by2 - by1);

        return area_of_rect1 + area_of_rect2 - area_overlap;
    }
};

int main()
{

    return 0;
}