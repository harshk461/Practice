#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int l, int r, vector<int> &pre, int m)
    {
        if (l > r)
            return 0;
        if (l == r)
            return 1;
        if (r - 1 == 1)
            return 1;

        bool res = 0;
        if (pre[r] - pre[l] >= m)
            res = solve(l + 1, r, pre);
        if ((l >= 1 && pre[r - 1] - pre[l - 1] >= m) || (l == 0 && pre[r - 1] >= m))
            res = res || solve(l, r - 1, pre, m);

        return res;
    }

public:
    bool canSplitArray(vector<int> &nums, int m)
    {
        int n = nums.size();
        if (n == 1)
            return 1;

        vector<int> pre;
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            pre[i] = nums[i];
            pre[i] += pre[i - 1];
        }
        int l = 0;
        int r = n - 1;

        bool res = 0;
        if (pre[r] - pre[0] >= m || r - 1 == 1)
            res = solve(1, r, pre, m);
        if (n > 1 && pre[r - 1] >= m)
            res = res || solve(0, r - 1, pre, m);
        return res;
    }
    bool solve2(vector<int> &nums, int m)
    {
        if (nums.size() < 3)
            return true;

        for (int i = 1; i < nums.size(); i++)
            if (nums[i] + nums[i - 1] >= m)
                return true;
        return false;
    }
};

int main()
{

    return 0;
}