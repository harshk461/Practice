#include <bits/stdc++.h>
using namespace std;

int findMiddleIndex(vector<int> &nums)
{
    int n = nums.size();
    int sum_arr = 0;
    for (auto i : nums)
    {
        sum_arr += i;
    }
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += nums[i];
        if (curr - nums[i] == sum_arr - curr)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {2, 3, -1, 8, 4};
    cout << findMiddleIndex(nums);
    return 0;
}