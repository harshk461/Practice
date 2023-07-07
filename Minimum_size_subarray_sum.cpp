#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int ans = INT_MAX;
        int sum = 0;
        for (int l = 0, r = 0; r < nums.size(); ++r)
        {
            sum += nums[r];
            while (sum >= target)
            {
                ans = min(ans, r - l + 1);
                sum -= nums[l++];
            }
        }
        return ans < INT_MAX ? ans : 0;
    }
};

int main()
{

    return 0;
}