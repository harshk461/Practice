#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long continuousSubarrays(vector<int> &nums)
    {
        long long ans = 1;
        int left = nums[0] - 2;
        int right = nums[0] + 2;
        int l = 0;

        for (int r = 1; r < nums.size(); r++)
        {
            if (left <= nums[r] && nums[r] <= right)
            {
                left = max(left, nums[r] - 2);
                right = min(right, nums[r] + 2);
            }
            else
            {
                left = nums[r] - 2;
                right = nums[r] + 2;
                l = r;
                while (nums[r] - 2 <= nums[l] && nums[l] <= nums[r] + 2)
                {
                    left = max(left, nums[l] - 2);
                    right = min(right, nums[l] + 2);
                    l--;
                }
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};

int main()
{

    return 0;
}