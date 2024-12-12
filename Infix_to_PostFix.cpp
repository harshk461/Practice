#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

// Precedence
int prec(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '/' || ch == '*')
        return 2;
    else if (ch == '-' || ch == '+')
        return 1;
    else
        return -1;
}

string convert(string s)
{
    stack<char> st;
    string ans = "";

    for (auto ch : s)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            ans += ch;

        else if (ch == '(')
        {
            st.push(')');
        }
        // evaluate the current equation inside the parentheses
        else if (ch == ')')
        {
            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            // remove current parentheses
            st.pop();
        }
        // if operator is there
        else
        {
            while (!st.empty() && prec(ch) <= prec(st.top()))
            {
                ans += st.top();
                st.pop();
            }
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    string s = "a+b*(c^d-e)^(f+g*h)-i";
    cout << convert(s);
    return 0;
}