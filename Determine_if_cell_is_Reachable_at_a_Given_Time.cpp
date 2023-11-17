#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(int sx, int sy, int fx, int fy, int t)
    {
        int width = abs(sx - fx);
        int height = abs(sy - fy);

        if (width == 0 && height == 0 && t == 1)
            return false;

        return t >= max(width, height);
    }
    int dfs(int i, int j, int x, int y)
    {
        if (i < 0 || j < 0)
            return 0;

        if (i > x || j > y)
            return 0;

        if (i == x - 1 && j == y - 1)
            return 1;

        int ans = 0;
        int left = dfs(i - 1, j, x, y);
        int right = dfs(i + 1, j, x, y);
        int top = dfs(i, j - 1, x, y);
        int bottom = dfs(i, j + 1, x, y);

        ans = 1 + min(ans, min(left, min(right, min(top, bottom))));
        return ans;
    }

public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        int min_path = dfs(sx, sy, fx, fy);
        // if (min_path > t)
        //     return false;
        // return true;
        cout << min_path << " ";
        return false;
    }
};

int main()
{
    Solution s;
    s.isReachableAtTime(3, 1, 7, 3, 3);

    return 0;
}