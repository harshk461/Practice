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
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size();
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++)
            prefix[i] = nums[i] + prefix[i - 1];

        // sum till end is divisble by p
        if (prefix[n - 1] % p == 0)
            return 0;

        for (int x = 0; x < n; x++)
        {
            for (int i = 0; i < n; i++)
            {
                int start = i;
                int end = i + x;

                if (end >= n)
                    continue;

                long long sum = prefix[end];
                if (start != 0)
                    sum -= prefix[end];
                if (prefix[n - 1] != sum && ((prefix[n - 1] - sum) % p) == 0)
                    return x + 1;
            }
        }

        return -1;
    }
};

int main()
{

    return 0;
}