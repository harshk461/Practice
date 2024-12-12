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
    bool canMakeSubsequence(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();

        int i = 0; // second string index
        for (int j = 0; j < n && i < m; j++)
        {
            if (str1[j] == str2[i] || (str1[j] + 1 == str2[i]) ||
                (str1[j] - 25 == str2[i]))
                i++;
        }

        return i == m;
    }
};

int main()
{

    return 0;
}