#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
private:
    long long brute(vector<int> &nums, int k)
    {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n - k; i++)
        {
            set<int> st(nums.begin() + i, nums.begin() + i + k);
            if (st.size() == k)
            {
                int sum = accumulate(nums.begin() + i, nums.begin() + i + k, 0);
                ans = max(ans, sum);
            }
        }

        return ans;
    }
    long long solve(vector<int> &nums, int k)
    {
        long long ans = 0;
        long long curr_sum = 0;
        int i = 0;
        int j = 0;

        unordered_map<int, int> num_to_index;

        while (j < nums.size())
        {
            int curr = nums[j];
            int last_occur = num_to_index.count(curr) ? num_to_index[curr] : -1;

            while (i <= last_occur || j - i + 1 > k)
            {
                curr_sum -= nums[i];
                i++;
            }

            num_to_index[curr] = j;
            curr_sum += nums[j];

            if (j - i + 1 == k)
                ans = max(ans, curr_sum);
            j++;
        }
        return ans;
    }

public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        return solve(nums, k);
    }
};

int main()
{

    return 0;
}