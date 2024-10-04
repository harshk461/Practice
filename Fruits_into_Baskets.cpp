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
    int slidingWindow(vector<int> &fruits)
    {
        unordered_map<int, int> freq;
        int n = fruits.size();

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++)
        {
            freq[fruits[right]]++;

            if (freq.size() > 2)
            {
                while (left < right)
                {
                    freq[fruits[left]]--;
                    if (freq[fruits[left]] == 0)
                    {
                        freq.erase(fruits[left]);
                        left++;
                        break;
                    }
                    left++;
                }
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }

    int slidingWindowOptimized(vector<int> &fruits)
    {
        unordered_map<int, int> freq;
        int n = fruits.size();

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++)
        {
            freq[fruits[right]]++;

            if (freq.size() > 2)
            {
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0)
                    freq.erase(fruits[left]);
                left++;
            }
            else
            {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }

public:
    int totalFruit(vector<int> &fruits)
    {
        return slidingWindowOptimized(fruits);
    }
};

int main()
{

    return 0;
}