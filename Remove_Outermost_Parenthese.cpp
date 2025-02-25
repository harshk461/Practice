#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string ans = "";
        int balance = 0;
        int i = 0;
        int n = s.length();

        while (i < n)
        {
            if (s[i] == '(')
            {
                if (balance > 0)
                    ans += s[i];
                balance++;
            }
            else
            {
                balance--;
                if (balance > 0)
                    ans += s[i];
            }
            i++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}