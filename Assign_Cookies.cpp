#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int contentCookies = 0;
        int cookieIndex = 0;

        while (cookieIndex < s.size() && contentCookies < g.size())
        {
            if (s[cookieIndex] >= g[contentCookies])
                contentCookies++;
            cookieIndex++;
        }

        return contentCookies;
    }
};

int main()
{

    return 0;
}