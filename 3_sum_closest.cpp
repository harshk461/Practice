#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());

        for (int i = 0; i + 2 < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // find num[i] between l and r
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target)
                    return sum;
                // in this we find which answer is closest to target
                if (abs(sum - target) < abs(ans - target))
                    ans = sum;
                if (sum < target)
                    l++;
                else
                    r--;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 1, 1, 0};
    Solution s;
    s.threeSumClosest(arr, -100);
    return 0;
}