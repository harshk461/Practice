#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        int one_count = 0;

        for (auto it : nums)
            one_count += it;

        if (one_count == 0 || one_count == n)
            return 0;

        // curr window
        int curr_one = 0;
        for (int i = 0; i < one_count; i++)
            curr_one += nums[i];

        int max_ones = curr_one;
        for (int i = 0; i < n; i++)
        {
            curr_one -= nums[i];
            curr_one += nums[(i + one_count) % n];
            max_ones = max(max_ones, curr_one);
        }

        return one_count - max_ones;
    }
};

int main()
{

    return 0;
}