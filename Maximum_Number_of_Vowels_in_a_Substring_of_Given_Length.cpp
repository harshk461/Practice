#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u')
    {
        return true;
    }
    return false;
}

int maxVowels(string s, int k)
{
    int ans = 0;
    int countVowel = 0;
    // first window
    for (int i = 0; i < k; i++)
    {
        if (isVowel(s[i]))
        {
            countVowel++;
        }
    }

    if (ans < countVowel)
    {
        ans = countVowel;
    }

    for (int i = k; i < s.length(); i++)
    {
        if (isVowel(s[i]))
        {
            countVowel++;
        }
        if (isVowel(s[i - k]))
        {
            countVowel--;
        }
        ans = max(countVowel, ans);
    }
    return ans;
}

int main()
{

    return 0;
}