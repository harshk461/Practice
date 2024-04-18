#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string makeGood(string s)
    {
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.length(); i++)
        {
            if (st.empty() && st.front() != s[i])
                st.push(s[i]);
            else
                st.pop();
        }

        string ans = "";
        for (auto it : st)
            ans += it;
        return ans;
    }
};

int main()
{

    return 0;
}