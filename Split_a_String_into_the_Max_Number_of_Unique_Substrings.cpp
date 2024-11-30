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
private:
    int solve(int index, string s, set<string> &vis)
    {
        if (index == s.length())
            return 0;

        int max_count = 0;
        string curr = "";

        for (int i = index; i < s.length(); i++)
        {
            curr += s[i];
            if (vis.find(curr) == vis.end())
            {
                vis.insert(curr);
                max_count = max(max_count, 1 + solve(i + 1, s, vis));
                vis.erase(curr);
            }
        }

        return max_count;
    }

public:
    int maxUniqueSplit(string s)
    {
        set<string> vis;
        return solve(0, s, vis);
    }
};

int main()
{

    return 0;
}