class Solution
{
private:
    int solve(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
            {
                ans++;
                nums[i]++;
            }

            // if after operations our current index val is less than previous one
            if (nums[i] < nums[i - 1])
            {
                ans += nums[i - 1] - nums[i] + 1;
                nums[i] += nums[i - 1] - nums[i] + 1;
            }
        }

        return ans;
    }

public:
    int minIncrementForUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i + 1]++;
                ans++;
            }

            if (nums[i + 1] < nums[i])
            {
                ans += nums[i] - nums[i + 1] + 1;
                nums[i + 1] += nums[i] - nums[i + 1] + 1;
            }
        }

        return ans;
    }
};