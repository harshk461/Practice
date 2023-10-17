#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);

        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }

public:
    int firstMissingPositive(vector<int> &nums)
    {
        int maxi = 0, mini = 0;
        unordered_map<int, bool> map;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 1)
            {
                maxi = max(maxi, nums[i]);
                mini = min(mini, nums[i]);
                map[nums[i]] = true;
            }
        }

        for (int i = mini; i <= maxi; i++)
        {
            if (!map[i])
                return i;
        }
        return maxi + 1;
    }
};

int main()
{

    return 0;
}