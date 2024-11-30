#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx, mmx, sse2, sse3, sse4")

static const int disableSync = [](void) noexcept -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution
{
private:
    int brute(vector<int> &arr)
    {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] <= arr[j])
                    ans = max(ans, j - i);
            }
        }

        return ans;
    }

    int solve(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> suffix(n);

        suffix[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
            suffix[i] = max(suffix[i + 1], nums[i]);

        int ans = 0;
        int i = 0, j = 0;

        while (j < n)
        {
            while (i < j && nums[i] > suffix[j])
                i++;
            ans = max(ans, j - i);
            j++;
        }

        return ans;
    }

public:
    int maxWidthRamp(vector<int> &nums)
    {
        return solve(nums);
    }
};

int main()
{

    return 0;
}