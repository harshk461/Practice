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
    int minLength(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if ((!st.empty() && st.top() == 'A' && s[i] == 'B') ||
                (!st.empty() && st.top() == 'C' && s[i] == 'D'))
                st.pop();
            else
                st.push(s[i]);
        }

        return st.size();
    }
};

int main()
{

    return 0;
}