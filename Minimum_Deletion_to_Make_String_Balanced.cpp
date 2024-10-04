#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int using_stack(string s)
    {
        int n = s.length();
        stack<char> st;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            // if 'a' appear after b then we have to delete it
            if (!st.empty() && st.top() == 'b' && s[i] == 'a')
            {
                st.pop();
                ans++;
            }
            else
                st.push(s[i]);
        }
        return ans;
    }

public:
    int minimumDeletions(string s)
    {
        int n = s.length();
        vector<int> a_prefix(n, 0);
        vector<int> b_prefix(n, 0);

        int ca = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
                ca++;
            a_prefix[i] = ca;
        }

        int cb = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'b')
                cb++;
            b_prefix[i] = cb;
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int na = a_prefix[i];
            int nb = b_prefix[i];

            ans = min(ans, na + nb);
        }

        return using_stack(s);
    }
};

int main()
{

    return 0;
}