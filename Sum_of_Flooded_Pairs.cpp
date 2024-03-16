#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MOD = 1e9 + 7;
    int sumOfFlooredPairs(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> pairs;
        unordered_map<int, int> freq;

        for (auto it : nums)
            freq[it]++;

        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                sum = sum % MOD + (nums[j] / nums[i]) % MOD;

        // int sum = 0;
        // for (auto it : pairs)
        //     sum = sum % MOD + (it.first / it.second) * (freq[it.first] * freq[it.second]) % MOD;

        return sum + n;
    }
};

int main()
{

    return 0;
}