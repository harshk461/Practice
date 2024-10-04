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
    int countPrefixLength(int a, int b)
    {
        string s1 = to_string(a);
        string s2 = to_string(b);

        int i = 0;
        int n = s1.length();
        int m = s2.length();

        while (i < min(m, n) && s1[i] == s2[i])
            i++;

        return i;
    }

    int brute(vector<int> &a1, vector<int> &a2)
    {
        int ans = 0;
        for (auto i : a1)
        {
            for (auto j : a2)
            {
                ans = max(ans, countPrefixLength(i, j));
            }
        }

        return ans;
    }

    int solve(vector<int> &a1, vector<int> &a2)
    {
        set<int> vis;
        for (auto it : a1)
        {
            while (it > 0)
            {
                vis.insert(it);
                it /= 10;
            }
        }

        int ans = 0;
        for (auto it : a2)
        {
            while (it > 0)
            {
                if (vis.count(it))
                {
                    string s = to_string(it);
                    ans = max(ans, s.length());
                }
                it /= 10;
            }
        }

        return ans;
    }

public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        return solve(arr1, arr2);
    }
};

int main()
{

    return 0;
}