#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // odd
            if (nums[i] % 2 == 1)
                nums[i] = 1;

            // even
            else
                nums[i] = 0;
        }

        unordered_map<int, int> map;
        map[0] = 1;
        int curr_sum = 0;
        int total_subarrays = 0;

        for (auto num : nums)
        {
            curr_sum += num;
            if (map.find(curr_sum - k) != map.end())
                total_subarrays += map[curr_sum - k];

            map[curr_sum]++;
        }

        return total_subarrays;
    }
};

int main()
{

    return 0;
}