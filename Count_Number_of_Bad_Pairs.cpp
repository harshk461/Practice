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
    // Brute force approach: O(n^2) time complexity
    // Checks all pairs (i, j) and counts those that don't satisfy the good pair condition
    long long brute(vector<int> &nums)
    {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // A pair (i, j) is "bad" if the condition j - i != nums[j] - nums[i] holds
                if (j - i != (nums[j] - nums[i]))
                    ans++;
            }
        }
        return ans;
    }

    // Optimized approach: O(n) time complexity
    long long solve(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, long long> map; // To store the frequency of (nums[i] - i)

        // Populate the frequency map
        for (int i = 0; i < n; i++)
        {
            map[nums[i] - i]++;
        }

        // Calculate total number of pairs (nC2 = n * (n - 1) / 2)
        long long ans = (1LL * n * (n - 1)) / 2;

        // Subtract the count of "good" pairs from the total
        for (auto it : map)
        {
            long long count = it.second;
            // If there are `count` elements with the same value of (nums[i] - i),
            // the number of "good" pairs among them is count * (count - 1) / 2.
            ans -= (count * (count - 1)) / 2;
        }

        return ans; // Remaining pairs are the "bad" ones
    }

public:
    // Wrapper function to call the optimized solution
    long long countBadPairs(vector<int> &nums)
    {
        return solve(nums);
    }
};

int main()
{

    return 0;
}