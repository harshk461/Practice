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
private:
    int countingSort(vector<int> &nums, int coins)
    {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> count(maxi + 1, 0);

        for (auto it : nums)
            count[it]++;

        int ans = 0;
        for (int i = 0; i < count.size(); i++)
        {
            if (coins < i)
                break;

            int maxPossible = min(coins / i, count[i]);
            ans += maxPossible;
            coins -= maxPossible;
        }

        return ans;
    }

public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        sort(costs.begin(), costs.end());
        if (costs[0] > coins)
            return 0;

        int ans = 0;
        for (auto it : costs)
        {
            if (coins - it >= 0)
            {
                ans++;
                coins -= it;
            }
        }

        return countingSort(costs, coins);
    }
};

int main()
{

    return 0;
}