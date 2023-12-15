#include <bits/stdc++.h>

using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // A simple hash function combining the hash values
        return h1 ^ h2;
    }
};

class Solution
{
private:
    int reverseNum(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            int temp = n % 10;
            ans = ans * 10 + temp;
            n /= 10;
        }
        return ans;
    }

    int solve(vector<int> &nums)
    {
        unordered_map<pair<int, int>, int, pair_hash> count;
        int n = nums.size();

        for (int i = 0; i < n; i++)
            nums[i] = nums[i] - reverseNum(nums[i]);

        for (auto it : nums)
            cout << it << " ";

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (nums[i] == nums[j])
                    count[{i, j}]++;

        int ans = 0;
        for (auto it : count)
            ans = max(ans, it.second);
        return ans;
    }

    int solve2(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            nums[i] = nums[i] - reverse(nums[i]);

        unordered_map<int, int> map;
        int ans = 0;
        int MOD = 1e9 + 7;

        for (auto num : nums)
        {
            ans = (ans + map[nums]) % MOD;
            map[num]++;
        }

        return ans;
    }

public:
    int countNicePairs(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && (nums[i] + reverseNum(nums[j])) == (nums[j] + reverseNum(nums[i])))
                    count++;
            }
        }

        return count;
    }
};

int main()
{

    Solution s;
    vector<int> arr = {12, 3, 4};
    return 0;
}