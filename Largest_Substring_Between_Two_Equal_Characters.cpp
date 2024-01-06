#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int findIndex(string s, char ch, bool isUpper)
    {
        if (isUpper)
        {
            for (int i = s.length() - 1; i >= 0; i--)
            {
                if (s[i] == ch)
                    return i;
            }
        }
        else
        {
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == ch)
                    return i;
            }
        }
        return -1;
    }

public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        unordered_set<char> st;
        bool vis = false;
        for (auto it : s)
            st.insert(it);

        int ans = 0;

        for (auto it : st)
        {
            int lower = findIndex(s, it, false);
            int upper = findIndex(s, it, true);
            // cout << it << " " << lower << " " << upper << endl;
            if (upper > lower && upper != -1 && lower != -1)
            {
                vis = true;
                ans = max(ans, upper - lower - 1);
            }
        }

        // cout << ans;
        if (vis)
            return ans;
        else
            return -1;
    }
};

int main()
{
    Solution s;
    s.maxLengthBetweenEqualCharacters("cbzxy");
    return 0;
}