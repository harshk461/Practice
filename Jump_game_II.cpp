#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums)
{
    int ans = 0;
    int end = 0;
    int farthest = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        farthest = max(farthest, i + nums[i]);
        if (farthest >= nums.size() - 1)
        {
            ans++;
            break;
        }
        if (i == end)
        {
            ans++;
            end = farthest;
        }
    }
    return ans;
}

int main()
{

    return 0;
}