#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 4)
            return 0;

        sort(nums.begin(), nums.end());

        int ans = INT_MAX;

        // first 3 minimum and last 3 maximum
        for (int i = 0, j = n - 4; i < 4; i++, j++)
            ans = min(ans, nums[j] - nums[i]);

        return ans;
    }
};

int main()
{

    return 0;
}