#include <bits/stdc++.h>
using namespace std;

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
