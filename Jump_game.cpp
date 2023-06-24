#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int i = 0, maxReach = 0;

    while (i < nums.size() && i <= maxReach)
    {
        maxReach = max(maxReach, i + nums[i]);
        i++;
    }

    if (i == nums.size())
        return true;
    return false;
}

int main()
{

    return 0;
}