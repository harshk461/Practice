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
    int minAddToMakeValid(string s)
    {
        int open = 0;
        int ans = 0;
        for (auto it : s)
        {
            if (it == '(')
                open++;
            // closing bracket case
            else
            {
                // if we have open bracket then we can pair it with the closing bracket
                if (open > 0)
                    open--;
                // but if not then we have to add open brackets extra
                else
                    ans++;
            }
        }

        // we add required open bracket and current total open bracket after iterating whole string
        return ans + open;
    }
};

int main()
{

    return 0;
}