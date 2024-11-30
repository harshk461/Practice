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
    int solve(string s)
    {
        stack<char> st;
        int unbalanced = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[')
                st.push(s[i]);
            else
            {
                // if stack is empty means we don't have any opening bracket for the incoming closing bracket
                // but if stack is not empty we have to increase the number of unbalanced
                // unbalanced are pair of closing and opening bracket
                if (!st.empty())
                    st.pop();
                else
                    unbalanced++;
            }

            return (unbalanced + 1) / 2;
        }
    }

public:
    int minSwaps(string s)
    {
        int close = 0;
        int open = 0;

        int ans = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '[')
                open++;
            else
                close++;

            cout << close << " " << open << " " << ans << endl;
            if (close > open)
            {
                open++;  // Balance the counts by treating this closing bracket as an opening bracket
                close--; // Decrease close count since we are treating it as balanced now

                ans++; // A swap is required to fix the imbalance
            }
        }

        return solve(s);
    }
};

int main()
{

    return 0;
}