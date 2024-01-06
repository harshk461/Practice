#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;
    int solve(vector<int> &arr)
    {
        int n = arr.size();
        int count = 0;
        unordered_map<int, int> map;
        for (auto it : arr)
            map[it]++;

        vector<int> modified;
        for (auto it : map)
            modified.push_back(it.first);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = (nums[i] / nums[j]) % MOD;
                count += (temp * map[i]) % MOD;
            }
        }

        return 0;
    }

public:
    int sumOfFlooredPairs(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                count += floor((nums[i] / nums[j]));
                count %= MOD;
            }
        }
        return solve(nums);
    }
};

int main()
{
    vector<int> arr = {2, 5, 9};
    Solution s;
    cout << s.sumOfFlooredPairs(arr);
    return 0;
}