#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string solve(string s)
    {
        stack<string> st;
        int i = 0;
        int n = s.length();
        string ans = "";

        while (i < n)
        {
            string ch = s[i];
            if (ch == '(')
                st.push("(");
            else if (s[i] == ')')
            {
                string curr = "";
                while (s[i] != '(' && st.size() > 0)
                {
                    curr += st.top();
                    st.pop();
                }

                st.pop();
                st.push(curr);
            }
            else
            {
                st.push(to_string(ch));
            }
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }

public:
    string reverseParentheses(string s)
    {
        int n = s.length();
        string ans = "";
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (ch == '(')
                st.push(i);
            else if (ch == ')')
            {
                int start = st.top() + 1;
                int end = i;

                reverse(s.begin() + start, s.begin() + end);
                st.pop();
            }
        }

        for (auto it : s)
        {
            if (it != '(' && it != ')')
                ans += it;
        }
        return solve(s);
    }
};

int main()
{

    return 0;
}