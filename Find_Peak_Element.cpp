#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;

    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] >= nums[mid + 1])
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}

int main()
{

    return 0;
}