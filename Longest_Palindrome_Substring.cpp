#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, string s1, string s2)
{
    if (i == s1.length() || j == s2.length())
        return 0;

    if (s1[i] == s2[j])
        return 1 + solve(i + 1, j + 1, s1, s2);
    else
        return max(solve(i + 1, j, s1, s2), solve(i, j + 1, s1, s2));
}

string longestPalindromicSubstring(string str)
{
    int n = str.length();
    int index = 0, palindromeLength = 1;
    for (int i = 1; i < n; i++)
    {
        int left = i - 1, right = i;
        while (left >= 0 && right < n && str[left] == str[right])
        {
            if (right - left + 1 > palindromeLength)
            {
                index = left;
                palindromeLength = right - left + 1;
            }
            left--;
            right++;
        }

        left = i - 1, right = i + 1;
        while (left >= 0 && right < n && str[left] == str[right])
        {
            if (right - left + 1 > palindromeLength)
            {
                index = left;
                palindromeLength = right - left + 1;
            }
            left--;
            right++;
        }
    }
    string ans = "";
    for (int i = index; i < index + palindromeLength; i++)
    {
        ans += str[i];
    }

    return ans;
}
int main()
{
    string s = "wowwo";
    cout << longestPalindromicSubstring(s);

    return 0;
}
