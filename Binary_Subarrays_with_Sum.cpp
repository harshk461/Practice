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
    int countSubarrays(vector<int> &nums, int goal)
    {
        int left = 0;
        int right = 0;
        long long sum = 0;
        long long ans = 0;

        int n = nums.size();
        while (right < n)
        {
            sum += nums[right];

            while (sum > goal && left <= right)
                sum -= nums[left++];

            ans += (right - left + 1);
            right++;
        }

        return ans;
    }

public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return countSubarrays(nums, goal) - countSubarrays(nums, goal - 1);
    }
};

int main()
{

    return 0;
}