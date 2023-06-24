#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    string temp = s;
    int start = 0, e = s.length() - 1;
    while (start < e)
    {
        swap(s[start], s[e]);
        start++;
        e--;
    }
    if (s == temp)
    {
        return true;
    }
    return false;
}
string firstPalindrome(vector<string> &words)
{
    for (auto i : words)
    {
        if (isPalindrome(i))
        {
            return i;
        }
    }
    return "";
}

int main()
{
    vector<string> arr = {"def", "ghi"};
    cout << firstPalindrome(arr);
    return 0;
}