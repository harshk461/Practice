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
    int numberOfSubstrings(string s)
    {
        unordered_map<char, int> freq;

        int l = 0;
        int ans = 0;

        for (int r = 0; r < s.length(); r++)
        {
            freq[s[r]]++;

            while (freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0)
            {
                ans += s.length() - r;
                l++;
                freq[s[l]]--;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}