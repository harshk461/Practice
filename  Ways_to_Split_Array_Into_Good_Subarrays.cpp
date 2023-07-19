#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfGoodSubarraySplits(vector<int> &nums)
    {
        if (count(nums.begin(), nums.end(), 1) == 0)
            return 0;
        int MOD = 1000000007;
        int prev = -1;
        int ans = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                if (prev != -1)
                    ans = ans * static_cast<long>(i - prev) % MOD;
                prev = i;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}