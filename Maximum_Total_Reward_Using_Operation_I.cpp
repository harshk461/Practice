class Solution
{
private:
    int solve(int index, int sum, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (index == nums.size())
            return 0;

        if (dp[index][sum] != -1)
            return dp[index][sum];

        int ans = -1;

        if (nums[index] > sum)
        {
            // in this we can pick the element
            // but we have to perform pick not pick here for maximum answer
            // Pick
            ans = max(ans, nums[index] + solve(index + 1, sum + nums[index], nums, dp));
            // Not Pick
            ans = max(ans, solve(index + 1, sum, nums, dp));
        }
        else
        {
            // We can't pick the current element because it is greater than current sum
            ans = max(ans, solve(index + 1, sum, nums, dp));
        }

        return dp[index][sum] = ans;
    }

public:
    int maxTotalReward(vector<int> &rewardValues)
    {
        set<int> st;
        for (auto it : rewardValues)
            st.insert(it);

        vector<vector<int>> dp(2001, vector<int>(4000, -1));

        // only using unique values because no 2 same value reward are used twice
        vector<int> nums(st.begin(), st.end());
        sort(nums.begin(), nums.end());
        // for (auto it : nums)
        //     cout << it << " ";
        return solve(0, 0, nums, dp);
    }
};