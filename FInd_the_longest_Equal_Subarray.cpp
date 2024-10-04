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
    int longestEqualSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int left = 0;
        int right = 0;

        int maxFreq = 0;
        unordered_map<int, int> freq;

        int ans = 1;

        while (right < n)
        {
            freq[nums[right]]++;
            maxFreq = max(maxFreq, freq[nums[right]]);

            int num_of_delete = (right - left + 1) - maxFreq;

            while (num_of_delete > k && left < right)
            {
                freq[nums[left]]--;
                left++;
                num_of_delete--;
            }

            ans = max(ans, maxFreq);
            right++;
        }

        return ans;
    }
};

int main()
{

    return 0;
}