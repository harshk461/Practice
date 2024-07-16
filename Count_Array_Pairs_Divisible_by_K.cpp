class Solution
{
private:
    long long brute(vector<int> &nums, int k)
    {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                long long t1 = (long long)nums[i];
                long long t2 = (long long)nums[j];

                long long a = t1 * t2;
                if (a % k == 0)
                    ans++;
            }
        return ans;
    }

    long long solve(vector<int> &nums, int k)
    {
        int n = nums.size();
        long long ans = 0;
        vector<long long> prefix;
        prefix[0] = (long long)nums[0];

        for (int i = 1; i < n; i++)
            prefix[i] = ((long long)nums[i]) * prefix[i - 1];

        return ans;
    }

public:
    long long countPairs(vector<int> &nums, int k)
    {
        return solve(nums, k);
    }
};