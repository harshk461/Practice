// #include <bits/stdc++.h>
// using namespace std;

// #pragma GCC target("avx, mmx, sse2, sse3, sse4")

// static const int disableSync = [](void) noexcept -> int
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     return 0;
// }();

// class Solution
// {
// public:
//     long long dividePlayers(vector<int> &skill)
//     {
//         int n = skill.size();
//         int teams = n / 2;

//         unordered_map<int, int> freq;
//         for (auto it : skill)
//             freq[it]++;

//         vector<pair<int, int>> arr;
//         int sum = accumulate(skill.begin(), skill.end());
//         if (sum % teams != 0)
//             return -1;

//         int each_team_sum = sum / teams;
//         for (int i = 0; i < n; i++)
//         {
//             int curr = skill[i];
//             if (freq[curr] > 0)
//             {
//                 freq[curr]--;
//                 int rem = each_team_sum - curr;
//                 if (freq[rem] > 0)
//                 {
//                     arr.push_back({curr, rem});
//                     freq[rem]--;
//                 }
//             }
//         }

//         int ans = 0;
//         for (auto it : arr)
//             ans += (it.first * it.second);

//         return ans;
//     }
// };

// int main()
// {

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int> &expenses, int k)
{
    unordered_map<long long, int> remainder_map;
    remainder_map[0] = -1;

    long long prefix_sum = 0;
    int max_length = 0;

    for (int i = 0; i < expenses.size(); ++i)
    {
        prefix_sum += expenses[i];

        int remainder = ((prefix_sum % k) + k) % k;
        if (remainder_map.find(remainder) != remainder_map.end())
        {
            int curr = i - remainder_map[remainder];
            max_length = max(max_length, curr);
        }
        else
        {
            remainder_map[remainder] = i;
        }
    }

    return max_length;
}

int main()
{
    vector<int> expenses1 = {20, 70, 60, 10, 40, 50};
    int k1 = 30;
    cout << solve(expenses1, k1) << endl;

    vector<int> expenses2 = {40, 50, 0, -20, -30, 10};
    int k2 = 50;
    cout << solve(expenses2, k2) << endl;

    return 0;
}
