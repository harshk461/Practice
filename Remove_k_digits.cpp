#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.length();
        if (n == k)
            return "0";

        stack<int> st;

        for (auto it : num)
        {
            while (!st.empty() && it < st.top() && k > 0)
            {
                k--;
                st.pop();
            }

            st.push(it);
        }

        while (k > 0 && !st.empty())
        {
            st.pop();
            k--;
        }

        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // remove leading zeros
        int i = 0;
        while (i < ans.length() && ans[i] == '0')
            i++;
        string res(ans.begin() + i, ans.end());
        return res == "" ? "0" : res;
    }
};

int main()
{
    return 0;
}