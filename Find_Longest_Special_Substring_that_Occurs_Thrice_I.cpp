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
    bool check(int idx, int mid, string main)
    {
        string s = "";
        for (int i = 0; i < mid; i++)
            s += ('a' + idx);
        int count = 0;
        for (int i = 0; i < main.length() - idx; i++)
        {
            if (main.substr(i, i + s.length()) == s)
                count++;
        }

        return count >= 3;
    }

public:
    int maximumLength(string s)
    {
        int ans = -1;
        int n = s.length();

        int maxLen = n - 2;
        // generating substring using a-z each character
        for (int i = 0; i < 26; i++)
        {
            int low = 1;
            int high = maxLen;

            while (low < high)
            {
                int mid = (low + high) / 2;

                if (check(i, mid, s))
                {
                    ans = max(ans, mid);
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{
    string s = "aaaa";
    Solution sts;
    cout << sts.maximumLength(s);
    return 0;
}