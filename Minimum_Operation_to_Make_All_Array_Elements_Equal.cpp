class Solution
{
private:
    vector<long long> brute(vector<int> &nums, vector<int> &queries)
    {
        unordered_map<int, int> map;
        for (auto it : nums)
            map[it]++;
        vector<long long> ans;
        for (auto it : queries)
        {
            long long count = 0;
            for (auto mp : map)
            {
                long long t = abs(it - mp.first);
                count += t * mp.second;
            }
            ans.push_back(count);
        }

        return ans;
    }

public:
    vector<long long> minOperations(vector<int> &nums, vector<int> &queries)
    {
        sort(nums.begin(), nums.end());
        vector<long long> ans;
        int n = nums.size();

        vector<long long> prefix(n + 1);
        prefix[0] = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            prefix[i + 1] = sum;
        }

        for (auto q : queries)
        {
            long long lb = lower_bound(nums.begin(), nums.end(), q) - nums.begin() - 1;
            long long ub = upper_bound(nums.begin(), nums.end(), q) - nums.begin();

            long long left = 0;

            if (lb != -1)
                left += (q * (lb + 1) - prefix[lb + 1] - prefix[0]);

            long long right = 0;

            if (ub != n)
                right += (prefix[n] - prefix[ub]) - (q * (n - ub));

            ans.push_back(left + right);
        }

        ve

            return ans;
    }
};