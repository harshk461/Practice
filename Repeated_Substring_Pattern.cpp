#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(string temp, string s)
    {
        string ans = "";
        while (ans.length() < s.length())
        {
            ans += temp;
        }
        if (ans == s)
            return true;
        return false;
    }

    bool solve2(string s)
    {
        int n = s.length();
        for (int i = 1; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                string pattern = "";
                for (int j = 0; j < n / i; j++)
                    pattern += s.substr(0, i);
                if (s == pattern)
                    return true;
            }
        }
        return false;
    }

public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.length();
        for (int i = 1; i < n; i++)
        {
            string temp = s.substr(0, i);
            if (solve(temp, s))
                return true;
        }
        return false;
    }
};

int main()
{

    return 0;
}