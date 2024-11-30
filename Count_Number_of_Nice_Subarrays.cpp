// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     int numberOfSubarrays(vector<int> &nums, int k)
//     {
//         int n = nums.size();
//         for (int i = 0; i < n; i++)
//         {
//             // odd
//             if (nums[i] % 2 == 1)
//                 nums[i] = 1;

//             // even
//             else
//                 nums[i] = 0;
//         }

//         unordered_map<int, int> map;
//         map[0] = 1;
//         int curr_sum = 0;
//         int total_subarrays = 0;

//         for (auto num : nums)
//         {
//             curr_sum += num;
//             if (map.find(curr_sum - k) != map.end())
//                 total_subarrays += map[curr_sum - k];

//             map[curr_sum]++;
//         }

//         return total_subarrays;
//     }
// };

// int main()
// {

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

// #pragma GCC target("avx, mmx, sse2, sse3, sse4")

// static const int disableSync = [](void) noexcept -> int
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     return 0;
// }();

class Solution
{
private:
    int countSubarrays(vector<int> &nums, int goal)
    {
        int left = 0;
        int right = 0;

        int ans = 0;
        int sum = 0;

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
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        // convert all odd to 1 and all even to 0;
        // then we can use k as our goal variable and count the number of subarray with sum equal to goal

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
                nums[i] = 0;
            else
                nums[i] = 1;
        }

        return countSubarrays(nums, k) - countSubarrays(nums, k - 1);
    }
};

int main()
{
    return 0;
}