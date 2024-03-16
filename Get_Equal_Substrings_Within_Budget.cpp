#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.length();
        int ans = 0;
        int i = 0;
        int c = maxCost;
        for (int j = 0; j < n; j++)
        {
            c -= abs(s[j] - t[j]);
            if (c >= 0)
                ans = max(ans, j - i + 1);
            else
                c += abs(s[i] - t[i]), i++;
        }

        return ans;
    }
};

int main()
{

    return 0;
}