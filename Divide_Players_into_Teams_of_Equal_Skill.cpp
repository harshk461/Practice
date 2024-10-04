#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx, mmx, sse2, sse3, sse4")

static const int disableSync = [](void) noexcept -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        int n = skill.size();
        int teams = n / 2;

        unordered_map<int, int> freq;
        for (auto it : skill)
            freq[it]++;

        vector<pair<int, int>> arr;
        int sum = accumulate(skill.begin(), skill.end());
        if (sum % teams != 0)
            return -1;

        int each_team_sum = sum / teams;
        for (int i = 0; i < n; i++)
        {
            int curr = skill[i];
            if (freq[curr] > 0)
            {
                freq[curr]--;
                int rem = each_team_sum - curr;
                if (freq[rem] > 0)
                {
                    arr.push_back({curr, rem});
                    freq[rem]--;
                }
            }
        }

        int ans = 0;
        for (auto it : arr)
            ans += (it.first * it.second);

        return ans;
    }
};

int main()
{

    return 0;
}