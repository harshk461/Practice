#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int open = 0, close = 0;
        int ans = INT_MIN;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                open++;
            if (s[i] == ')')
                close++;

            if (open == close)
                ans = max(ans, open + close);
            if (close > open)
                open = 0, close = 0;
        }

        for (int j = n - 1; j >= 0; j--)
        {
            if (s[j] == '(')
                open++;
            if (s[j] == ')')
                close++;

            if (open == close)
                ans = max(ans, open + close);
            if (close > open)
                open = 0, close = 0;
        }

        return ans;
    }
};

int main()
{

    return 0;
}